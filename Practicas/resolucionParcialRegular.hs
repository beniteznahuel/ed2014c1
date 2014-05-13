data BT = Nil | Node Int BitTree BitTree

contains :: BT -> Chain -> Int
contains Nil _ = 0
contains (Node x l r) [] = x
contains (Node x l r) (Off:bs) = contains l bs
contains (Node x l r) (On:bs) = contains r bs

insert :: BT -> Chain -> BT
insert Nil [] = Node 1 Nil Nil
insert Nil (Off:bs) = Node 0 (Node 1 Nil Nil) Nil
insert Nil (On:bs) = Node 0 Nil (Node 1 Nil Nil)
insert (Node x l r) [] = Node (x+1) l r
insert (Node x l r) (Off:bs) = Node x (insert l bs) r
insert (Node x l r) (On:bs) = Node x l (insert r bs)

remove :: BT -> Chain -> BT
remove Nil _ = Nil
remove (Node x l r) [] = fix (Node (dec x) l r)
remove (Node x l r) (Off:bs) = fix (Node x (remove l bs) r)
remove (Node x l r) (On:bs) = fix (Node x l (remove r bs))
  where dec x = if x > 0 then x-1 else 0
	fix = (Node 0 Nil Nil) = Nil
	fix t = t
	
elements :: BT -> [(Int, Chain)]
elements t = elems t []

  where elems :: BT -> Chain -> [(Int, Chain)]
	elems Nil branch = []
	elems (Node x l r) branch = (if x > 0 then [(x, branch)] else []) ++ elems l (Off:branch) ++ elems r (On:branch)
	
data HT = Hleaf Int | HBin Int HT HT

weight :: HT -> Int
weight (HLeaf w) = w
weight (HBin w l r) = w
	
weightedSize :: HT -> Int
weightedSize t = wsaux
  where wsaux (HLeaf w) h = w * h
	wsaux (HBin w l r) h = wsaux l (h1) + wsaux r (h+1)

assemble :: Priority Queue pq => pq HT -> HT
assemble pq | sizePQ pq == 1 = fst(dequeuePQ pq)
	    | otherwise      = let (h1, q1) = dequeuePQ pq
				   (h2, q2) = dequeuePQ q1
				      hb    = HBin (weight h1 + weight h2) h1 h2
			in assemble (enqueuePQ q2 hb)
			
compress :: [Chain] -> [Chain]
compress cs = let hTree = genTree cs
		  table = genTable hTree
	      in compressWith table cs
  where compressWith table [] = []
	compressWith table (c:cs) = fromJust(lookUpM table c) : (compressWith table cs)