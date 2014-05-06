subset :: Tree Int -> Int -> Int -> Tree Int
subset EmptyT n m = EmptyT
subset (NodeT e l r) n m | e < m && e > n = NodeT e (subset l n m) (subset r n m)
			 | e < n = subset r n m
                         | e > m = subset m n m
                         
data Lista a = L [a] Bool

reverseL :: Lista a -> Lista a
reverseL (L xs r) = L xs (not r)

headL :: Lista a -> a
headL (L xs r) = if r then last xs else head xs

consL :: a -> Lista a
consL x (L xs r) = if r then (L (xs++[x]) r) else (L (x:xs) r)

concatL :: Lista a -> Lista a -> Lista a
concatL l1 l2 = if isEmptyL l1 then l2 else consL (headL l1) (concatL (tailL l1) l2)

isEmptyL :: Lista a -> Bool
isEmptyL (L l _) = null l

#Parcial 2

mover s Repartir = repartir s
mover s (MoverNDeA o d n) = MoverDeA o d n s