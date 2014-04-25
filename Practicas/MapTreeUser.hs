import MapInterface
import MapTree

treeVacio :: MapTree k v
treeVacio = emptyM

busqueda :: Ord k => MapTree k v -> k -> Maybe v
busqueda m k = lookUpM m k