esClave :: (a,b) -> a -> Bool
esClave (k,_) c = k == c 

buscaRep :: [(a,b)] -> a -> Maybe b
buscaRep [] _ = Nothing
buscaRep (x:xs) k | esClave x k = Just (snd x)
                  | otherwise = buscaRep xs k

borrarRep :: [(a,b)] -> a -> [(a,b)]
borrarRep [] _ = []
borrarRep (x:xs) k | esClave x k  = xs
                   | otherwise = borrarRep xs k

clavesRep :: [(k,v)] -> [k]
clavesRep [] = []
clavesRep (x:xs) = (fst x):(clavesRep xs)

-----------------------------------------------------------------

-- Único valor

agregarRep :: [(a,b)] -> a -> b -> [(a,b)]
agregarRep [] k v = [(k,v)]
agregarRep (x:xs) k v | esClave x k = (reemplazarValor x v):xs
                      | otherwise = x:agregarRep xs k v

reemplazarValor :: (a,b) -> b -> (a,b)
reemplazarValor (k,_) n = (k,n)

-----------------------------------------------------------------

-- Lista de valores

agregarRep :: [(a,[b])] -> a -> b -> [(a,[b])]
agregarRep [] k v = [(k,v)]
agregarRep (x:xs) k v | esClave x k = (agregarValor x v):xs
                      | otherwise = x:agregarRep xs k v

agregarValor :: (a,[b]) -> b -> (a,[b])
agregarValor (k,v) n = (k,(n:v))



