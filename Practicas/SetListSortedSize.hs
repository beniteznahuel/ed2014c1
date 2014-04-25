module SetListSortedSize where
import SetInterface

data SetListSortedSize = SLSS [Int] Int deriving (Show) --Ordenada de menor a mayor, el ultimo Int es el size.

instance Set SetListSortedSize where 
  
  empty = (SLSS [] 0)
  
  belongs (SLSS xs _) e = belongs' xs e
  
  add (SLSS xs c) e | elem e xs = (SLSS xs c)
                    | otherwise = SLSS (addInPosition xs e) (c+1)
                             
  remove (SLSS xs c) e | elem e xs = SLSS (deleteElem xs e) (c-1) 
                       | otherwise = (SLSS xs c)

  size (SLSS _ c) = c
  
addInPosition :: [Int] -> Int -> [Int]
addInPosition [] e = [e]
addInPosition (x:xs) e | e > x = x:(addInPosition xs e)
                       | otherwise = e:x:xs

deleteElem :: [Int] -> Int -> [Int]
deleteElem [] _ = [] 
deleteElem (x:xs) e | x == e = xs
                    | otherwise = x:(deleteElem xs e)
                    
belongs' :: [Int] -> Int -> Bool
belongs' [] _ = False
belongs' (x:xs) y | x == y = True
                  | y < x = False
		  | otherwise = belongs' xs y
                 