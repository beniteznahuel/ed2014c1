module StackList (StackList) where
  import StackInterface

  data StackList a = MKSL [a] deriving (Show)

  instance Stack StackList where

    emptyS = MKSL []

    pushS e (MKSL xs) = MKSL (e:xs)

    popS (MKSL xs) = MKSL (tail xs)

    topS (MKSL xs) = head xs

    isEmptyS (MKSL xs) = null xs