data Tree a = EmptyT | NodeT a (Tree a) (Tree a) deriving (Show)

sizeT :: Tree a -> Int
sizeT EmptyT = 0
sizeT (NodeT _ t1 t2) = 1 + sizeT t1 + sizeT t2

leaves :: Tree a -> Int
leaves EmptyT = 1
leaves (NodeT _ t1 t2) = leaves t1 + leaves t2

nodes :: Tree a -> Int
nodes EmptyT = 0
nodes (NodeT _ EmptyT EmptyT) = 0
nodes (NodeT _ t1 t2) = 1 + nodes t1 + nodes t2

mirrorT :: Tree a -> Tree a
mirrorT EmptyT = EmptyT
mirrorT (NodeT r t1 t2) = NodeT r (mirrorT t2) (mirrorT t1)

levelT :: Tree a -> Int -> [Tree a]
levelT EmptyT _ = [] 
levelT t 1 = [t]
levelT (NodeT r t1 t2) n = (levelT t1 (n-1)) ++ (levelT t2 (n-1))

tree2listPerLevel :: Tree Int -> [[Int]]
tree2listPerLevel EmptyT = []
tree2listPerLevel (NodeT r t1 t2) = [r] : zipConcat (tree2listPerLevel t1) (tree2listPerLevel t2)

zipConcat :: [[a]] -> [[a]] -> [[a]]
zipConcat xs [] = xs
zipConcat [] ys = ys
zipConcat (x:xs) (y:ys) = (x++y) : (zipConcat xs ys)

-- occursT :: Tree a -> 

data Expr = Const Int | Var String | UnExp UnOp Expr | BinExp BinOp Expr Expr
data UnOp = Neg
data BinOp = Add | Sub | Mul | Div
type Env = [(String,Int)]

valorParaClave :: [(String,Int)] -> String -> Int
valorParaClave ((xa,xb):xs) a | xa == a = xb
                              | otherwise = valorParaClave xs a

eval :: Expr -> Env -> Maybe Int
eval (Const n) env = Just n
eval (Var s) env = Just (valorParaClave env s) -- practica 1 
eval (UnExp op u) env = evalUnExp op (eval u env) -- asumo que sé resolver epresiones unarias
eval (BinExp op i d) env = evalBinExp op (eval i env) (eval d env) -- idem arriba, pero con exp binarias
  
evalUnExp :: UnOp -> Maybe Int -> Maybe Int
evalUnExp Neg mi = evalNeg mi 
  where evalNeg Nothing = Nothing
	evalNeg (Just i) = Just (-i)
	
evalBinExp :: BinOp -> Maybe Int -> Maybe Int -> Maybe Int
evalBinExp Add mi md = evalAdd mi md
evalBinExp Sub mi md = evalSub mi md
evalBinExp Mul mi md = evalMul mi md
evalBinExp Div mi md = evalDiv mi md

evalAdd :: Maybe Int -> Maybe Int -> Maybe Int
evalAdd (Just i) (Just d) = Just (i+d)
evalAdd _ _ = Nothing

evalSub :: Maybe Int -> Maybe Int -> Maybe Int
evalSub (Just i) (Just d) = Just (i-d)
evalSub _ _ = Nothing

evalMul :: Maybe Int -> Maybe Int -> Maybe Int
evalMul (Just i) (Just d) = Just (i*d)
evalMul _ _ = Nothing

evalDiv :: Maybe Int -> Maybe Int -> Maybe Int
evalDiv (Just i) (Just d) | d == 0 = Nothing
			  | otherwise = Just (i `div` d)
evalDiv _ _ = Nothing

-- Version con menos código

evalBinExp' :: BinOp -> Maybe Int -> Maybe Int -> Maybe Int
evalBinExp' Add (Just i) (Just d) = Just (i+d)
evalBinExp' Sub (Just i) (Just d) = Just (i-d)
evalBinExp' Mul (Just i) (Just d) = Just (i*d)
evalBinExp' Div (Just i) (Just d) | d == 0 = Nothing
				  | otherwise = Just (i `div` d)
evalBinExp' _ _ _ = Nothing