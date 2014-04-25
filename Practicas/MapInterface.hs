module MapInterface where

  class Map m where
    
    emptyM :: m k v
    lookUpM :: Ord k => m k v -> k -> Maybe v
    addM :: Ord k => m k v -> k -> v -> m k v
    bstM :: m Int Char