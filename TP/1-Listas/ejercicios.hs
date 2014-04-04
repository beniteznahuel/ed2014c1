mapSucesor :: [Int] -> [Int]
mapSucesor [] = []
mapSucesor (x:xs) = (x+1):mapSucesor xs

filterPositivos :: [Int] -> [Int]
filterPositivos [] = []
filterPositivos (x:xs) = if x > 0 then x:filterPositivos xs else filterPositivos xs

esPrimo :: Int -> Bool
esPrimo 2 = True
esPrimo 3 = True
esPrimo 5 = True
esPrimo 7 = True
esPrimo n | (mod n 2) == 0 = False
	  | (mod n 3) == 0 = False
	  | (mod n 5) == 0 = False
          | (mod n 7) == 0 = False
	  | otherwise = True
          
filterPrimos :: [Int] -> [Int]
filterPrimos [] = []
filterPrimos (x:xs) = if esPrimo x then x:filterPrimos xs else filterPrimos xs

zipMaximos :: [Int] -> [Int] -> [Int]
zipMaximos [] [] = []
zipMaximos (x:xs) (y:ys) = (max x y):zipMaximos xs ys

zipMaximos2 :: [Int] -> [Int] -> [Int]
zipMaximos2 [] ys = ys
zipMaximos2 xs [] = xs
zipMaximos2 (x:xs) (y:ys) = (max x y) : zipMaximos2 xs ys

zipSort :: [Int] -> [Int] -> [(Int,Int)]
zipSort [] [] = []
zipSort (x:xs) (y:ys) = (min x y, max x y):zipSort xs ys

mapLongitudes :: [[a]] -> [Int]
mapLongitudes [] = []
mapLongitudes (x:xs) = (length x) : mapLongitudes xs 

longitudMayorA :: Int -> [[a]] -> [[a]]
longitudMayorA n [] = []
longitudMayorA n (x:xs) = if (length x) > n then x:longitudMayorA n xs else longitudMayorA n xs

mapCuadrados :: [Int] -> [Int]
mapCuadrados [] = []
mapCuadrados (x:xs) = if x > 0 then (x*x):mapCuadrados xs else mapCuadrados xs

sumaPar :: [(Int,Int)] -> [Int]
sumaPar [] = []
sumaPar ((x1,x2):xs) = (x1+x2) : sumaPar xs

data Fecha = MkFecha{
  anho :: Int,
  mes :: Int,
  dia :: Int
  } deriving (Show)
  
data Persona = MkPersona{
  nombre :: String,
  apellido :: String,
  fechaDeNacimiento :: Fecha
  } deriving (Show)
  
nacioAntesDe :: Fecha -> Persona -> Bool
nacioAntesDe (MkFecha a m d) (MkPersona _ _ f) | anho f > a = False
					       | anho f < a = True
	                                       | mes f > m = False
					       | mes f < m = True
	                                       | dia f > d = False
					       | dia f < d = True
	                                       | otherwise = False
	                                    
takePersonas :: [Persona] -> Fecha -> [Persona]
takePersonas [] _ = []
takePersonas (p:ps) f = if nacioAntesDe f p then p:takePersonas ps f else takePersonas ps f

data Pizza = MkPizza{
  ingredientes :: [String],
  precio :: Int
  } deriving (Show)
  
dropPizza :: [Pizza] -> [Pizza]
dropPizza [] = []
dropPizza (x:xs) = if precio x > 30 then x:dropPizza xs else dropPizza xs

takeNombresPersonas :: [Persona] -> Fecha -> [String]
takeNombresPersonas [] _ = []
takeNombresPersonas (p:ps) f = if nacioAntesDe f p then (nombre p):takeNombresPersonas ps f else takeNombresPersonas ps f

-- data Color = Rojo | Azul | Verde | Negro

--data ParColor = MkParColor{
--  color :: Color,
--  cantidad :: Int
--}

-- sumParesColor :: [ParColor] -> [ParColor] -> [ParColor]
-- sumParesColor (x:xs) (y:ys) 

snoc :: [a] -> a -> [a]
snoc xs e = xs ++ [e]

reversa :: [Int] -> [Int]
reversa [] = []
reversa (x:xs) = snoc (reversa xs) x

aplanar :: [[a]] -> [a]
aplanar [] = []
aplanar (x:xs) = x ++ aplanar xs

append' :: [a] -> [a] -> [a]
append' [] ys = ys
append' [x] ys = x:ys 
append' (x:xs) ys = x:append' xs ys 

snocAlt :: [Int] -> Int -> [Int]
snocAlt [] i = i:[]
snocAlt (x:xs) i = x:snocAlt xs i

--precondicion: la lista entrante no puede ser vacía
init' :: [a] -> [a]
init' [x] = []
init' (x:xs) = x:init xs

--precondicion: la lista entrante no puede ser vacía
last' :: [a] -> a
last' [x] = x
last' (x:xs) = last' xs

--precondicion, el string debe estar en la lista.
lookup' :: [String] -> String -> Int
lookup' [] _ = 0
lookup' (x:xs) s | x == s = 1
                 | otherwise = 1 + lookup' xs s
                
--precondicion el numero no puede ser negativo
takeN :: [a] -> Int -> [a]
takeN [] _ = []
takeN xs 0 = []
takeN (x:xs) n = x:takeN xs (n-1)

--precondicion el numero no puede ser negativo
dropN :: [a] -> Int -> [a]
dropN [] _ = []
dropN xs 0 = xs
dropN (x:xs) n = dropN xs (n-1)

--precondicion la clave debe estar en la lista
valorParaClave :: [(String,Int)] -> String -> Int
valorParaClave ((xa,xb):xs) a | xa == a = xb
                              | otherwise = valorParaClave xs a

maximum' :: [Int] -> Int
maximum' [] = 0
maximum' (x:xs) = max x (maximum' xs) 
s
fromJust :: Maybe a -> a
fromJust (Just x) = x

isIn :: [String] -> String -> Bool
isIn [] s = False
isIn (x:xs) s = if s == x then True else isIn xs s 

mLookUp :: [String] -> String -> Maybe Int
mLookUp [] _ = Nothing
mLookUp l@(x:xs) s = if isIn l s then (if x == s then Just 1 else Just (1 + (fromJust (mLookUp xs s)))) else Nothing

mInit :: [a] -> Maybe [a]
mInit [] = Nothing
mInit [x] = Just []
mInit (x:xs) = Just (x:(fromJust (mInit xs)))

mLast :: [a] -> Maybe a
mLast [] = Nothing
mLast [x] = Just x
mLast (x:xs) = mLast xs

takeExactlyN :: [a] -> Int -> Maybe [a]
takeExactlyN xs 0 = Just []
takeExactlyN l@(x:xs) n = if (length l) < n then Nothing else Just (x: (fromJust (takeExactlyN  xs (n-1))))

dropExactlyN :: [a] -> Int -> Maybe [a]
dropExactlyN [] _ = Nothing
dropExactlyN xs 0 = Just xs
dropExactlyN (x:xs) n = dropExactlyN xs (n-1)

mValorParaClave :: [(String,String)] -> String -> Maybe String
mValorParaClave [] _ = Nothing
mValorParaClave ((x,y):xs) xz | x == xz = Just y
			      | otherwise = mValorParaClave xs xz
			      
mMaximo :: [Int] -> Maybe Int
mMaximo [] = Nothing
mMaximo [x] = Just x
mMaximo (x:xs) = Just (max x (fromJust (mMaximo xs)))
