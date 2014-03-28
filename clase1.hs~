data Color = Azul | Amarillo | Rojo

first :: (a,a) -> a
first (x,y) = x

second :: (a,b) -> b
second (x,y) = y

max' :: (Int, Int) -> Int
max' (x,y) = if x > y then x else y

min' :: (Int, Int) -> Int
min' (x,y) = if x < y then x else y

null' :: [a] -> Bool
null' [] = True
null' (x:xs) = False

--Precondición not (null xs)    
head' :: [a] -> a
head' [] = undefined
head' (x:xs) = x    

tail' :: [a] -> [a]
tail' [] = []
tail' (x:xs) = xs

length' :: [a] -> Int
length' [] = 0
length' (x:xs) = 1 + length' xs

drop' :: Int -> [a] -> [a]
drop' 0 xs  = xs
drop' n (x:xs) = drop' (n-1) xs

take' :: Int -> [a] -> [a]
take' 0 xs = []
take' n (x:xs) = x : (take' (n-1) xs)

split :: Int -> [a] -> ([a],[a])
split n xs = (take' n xs, drop' n xs)

append' :: [a] -> [a] -> [a]
append' [] ys = ys
append' (x:xs) ys = x:(append' xs ys)
 
snoc' :: [a] -> a -> [a]
snoc' xs x = append' xs [x]

reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = snoc' (reverse xs) x

last' :: [a] -> a
last' [x] = x
last' (x:xs) = last' xs

zip' :: [a] -> [b] -> [(a,b)]
zip' [] [] = []
zip' (x:xs) (y:ys) = (x,y) : zip' xs ys

flatten :: [[a]] -> [a]
flatten [] = []
flatten (x:xs) = append' x (flatten xs)

maximum' :: [Int] -> Int
--precondición: lista con al menos 1 elemento
maximum' [x] = x
maximum' (x:xs) = max' (x, maximum' xs)

headM :: [a] -> Maybe a
headM [] = Nothing
headM (x:xs) = Just x

tailM :: [a] -> Maybe [a]
tailM [] = Nothing
tailM (x:xs) = Just xs

dropM :: Int -> [a] -> Maybe [a]
dropM _ [] = Nothing
dropM 0 xs = Just xs
dropM n (x:xs) = dropM (n-1) xs

lastM :: [a] -> Maybe a
lastM [] = Nothing
lastM [x] = Just x
lastM (x:xs) = lastM xs