data Tree a = EmptyT | NodeT a (Tree a) (Tree a) deriving (Show)

ocurrsT :: Eq a => a -> Tree a -> Bool -- Eq a restringe el tipo de a para que sólo sean tipos comparables.
ocurrsT x EmptyT = False
ocurrsT x (NodeT r t1 t2) = if x == r then True else (ocurrsT x t1) || (ocurrsT x t2)

esHoja :: Tree a -> Bool
esHoja (NodeT r EmptyT EmptyT) = True
esHoja _ = False

countLeaves :: Tree a -> Int
countLeaves EmptyT = 0
countLeaves (NodeT r ti td) = if (esHoja (NodeT r ti td)) then 1 else (countLeaves ti) + (countLeaves td)