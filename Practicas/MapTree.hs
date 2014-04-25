module MapTree where
import MapInterface

data Tree a = EmptyT | NodeT a (Tree a) (Tree a) deriving (Eq, Ord, Show)
data MapTree k v = MT (Tree (k,v)) deriving (Eq, Ord, Show)

instance Map MapTree where
  
  emptyM = MT EmptyT
  lookUpM (MT t) k = buscarEnArbol t k
  addM (MT t) k v = MT (crearYVerificar t k v)
  bstM = MT bt
  
buscarEnArbol :: Ord k => Tree (k,v) -> k -> Maybe v
buscarEnArbol EmptyT _ = Nothing
buscarEnArbol (NodeT (k,v) t1 t2) k' = if k == k' then Just v
						  else if k' > k then buscarEnArbol t2 k'
								 else buscarEnArbol t1 k'

crearYVerificar :: Ord k => Tree (k,v) -> k -> v -> Tree (k,v)
crearYVerificar EmptyT k' v' = (NodeT (k',v') EmptyT EmptyT)
crearYVerificar (NodeT (k,v) t1 t2) k' v' = if k == k' then (NodeT (k,v') t1 t2)
						       else if k' < k then NodeT (k,v) (crearYVerificar t1 k' v') t2
							    else NodeT (k,v) t1 (crearYVerificar t2 k' v')


bt :: Tree (Int, Char)
bt = (NodeT (7,'a') (NodeT (5,'b') EmptyT EmptyT) (NodeT (9,'c') EmptyT EmptyT))




