data AATree a b = Nil | Node Int a b (AATree a b) (AATree a b) -- El Int es el nivel del árbol

{- Inv. Rep: El hijo izquierdo no puede tener nivel menor al del árbol raíz, pero el derecho sí puede, al menos una vez consecutivamente.-}

level :: AATree a b -> Int
level Nil = 0
level (Node n k v l r) = n

isNil :: AATree a b -> Bool
isNil Nil = True
isNil _ = False

maximumT :: AATree a b -> (a,b)
maximumT (Node _ k v _ r) = if isNil r then (k,v) else maximumT r

lookupT :: Ord a => AATree a b -> a -> Maybe b
lookupT Nil _ = Nothing
lookupT (Node n k v l r) x | x < k = lookupT l x
			   | x > k = lookupT r x
                           | otherwise = Just v
                           
insert :: Ord a => AATree a b -> a -> b -> AATree a b
insert Nil k v = Node 1 k v Nil Nil
insert (Node n k v l r) k' v' | k' < k = fix(Node n k v (insert l k' v') r)
			      | k' > k = fix(Node n k v l (insert l k' v'))
	                      | otherwise = Node n k v' l r
  where fix t = split(skew t)
	
skew :: AATree a b -> AATree a b
skew (Node n k v (Node ln lk lv ll lr) r) | n == ln = Node ln lk lv ll (Node n k v lr r)
					  | otherwise = t
					  
split :: AATree a b -> AATree a b
split (Node n k v l (Node rn rk rv rl rr@(Node rrn _ _ _ _))) | n == rrn  = Node (rn+1) rk rv (Node n k v l rl) rr
split t = t

remove :: Ord a => AATree a b -> a -> AAtree a b
remove Nil _ = Nil
remove (Node n k v l r) x | x < k = fix(Node n k v (remove l x) r)
			  | x > k = fix(Node n k v l (remove r x))
                          | nil l && nil r = Nil
			  | nil l = let (sk, sv) = maximumT r
				    in fix(Node n sk sv Nil (remove r sk))
		          | otherwise = let (pk,pv) = maximumT l
					in fix(Node n pk pv (remove l pk) r)
			  where fix t = splitn 2( skewn 3(decrease t))

decrease :: AATree a b -> AAtree a b
decrease (Node n k v l r) = let lvl = min (level l) (level r) + 1
			    in Node lvl k v l (case r of
			                       Nil -> Nil
			                       Node rn rk rv rl rr -> Node (min lvl rn) rk rv rl rr)
			                       
splitn :: Int -> AATree a b -> AATree a b
splitn i t | i == 0 = t
	   | otherwise = case split of 
		           Nil -> Nil
		           Node n k v l r -> Node n k v l (splitn (i-1) r)
		           
skewn :: Int -> AATree a b -> AATree a b
skewn i t | i == 0 = t
	  | otherwise = case split of 
		           Nil -> Nil
		           Node n k v l r -> Node n k v l (skewn (i-1) r)