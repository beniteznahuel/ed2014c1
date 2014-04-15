module SetListSortedSize where
  import SetInterface

  data SetListSortedSize = SLSS [Int] Int deriving (Show) --Ordenada de menor a mayor, el ultimo Int es el size.

  instance Set SetListSortedSize where 
  
    empty = (SLSS [] 0)
  
    belongs (SLSS xs _) e = elem e xs
  
    add (SLSS xs c) e | elem e xs = (SLSS xs c)
                      | otherwise = SLSS (addInPositiion xs e) (c+1)
                             
    remove (SLSS xs c) e | elem e xs = (SLSS xs c)
                         | otherwise = SLSS (deleteElem xs e) (c-1)

    size (SLSS _ c) = c
  
 addInPosition :: [Int] -> Int -> [Int]
 addInPosition [] e = [e]
 addInPosition (x:xs) e | e > x = x:(addInPosition xs e)
                        | otherwise = e:x:xs

 deleteElem :: [Int] -> Int -> [Int]
 deleteElem [] _ = [] 
 deleteElem (x:xs) e | x == e = xs
                     | otherwise = x:(deleteElem xs e)