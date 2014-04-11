module StackInterface where

  class Stack s where
    
    emptyS :: s a
    pushS :: a -> s a -> s a
    popS :: s a -> s a
    topS :: s a -> a
    isEmptyS :: s a -> Bool