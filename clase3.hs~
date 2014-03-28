data Tree a = EmptyT | NodeT a (Tree a) (Tree a) deriving (Show)

ocurrsT :: Eq a => a -> Tree a -> Bool -- Eq a restringe el tipo de a para que sólo sean tipos comparables.
ocurrsT x EmptyT = False
ocurrsT x (NodeT r t1 t2) = if x == r then True else (ocurrsT x t1) || (ocurrsT x t2)

esHoja :: Tree a -> Bool
esHoja (NodeT r EmptyT EmptyT) = True
esHoja _ = False

countLeaves :: Tree a -> Int
countLeaves EmptyT = 0
countLeaves t@(NodeT _ ti td) = if esHoja t then 1 else countLeaves ti + countLeaves td

height :: Tree a -> Int
height EmptyT = 0
height (NodeT r t1 t2) = 1 + max (height t1) (height t2)

minT :: Tree Int -> Int
minT EmptyT = error "no tiene"
minT (NodeT r EmptyT EmptyT) = r 
minT (NodeT r EmptyT t2) = min r (minT t2)
minT (NodeT r t1 EmptyT) = min r (minT t1)
minT (NodeT r t1 t2) = min r (min (minT t1) (minT t2))

tree2list :: Tree a -> [a]
tree2list EmptyT = []
tree2list (NodeT r t1 t2) = r : ((tree2list t1) ++ (tree2list t2))