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
tree2listPerLevel (NodeT r t1 t2) = (tree2listPerLevel t1) ++ (tree2listPerLevel t2)