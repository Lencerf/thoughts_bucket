mergeSort::(Ord a) => [a] -> [a]
mergeSort xs
    | length xs < 2 = xs
    | otherwise = 
        let leftArray = mergeSort (fst dividedList)
            rightArray = mergeSort (snd dividedList)
        in  merge leftArray rightArray
        where dividedList = (\x -> mSplitAt ((length x) `quot` 2) x) xs

mSplitAt::Int -> [a] -> ([a], [a])
mSplitAt m xs = lastTwo $ foldr funcx ((length xs) - 1, [], []) xs  
    where lastTwo (_, a, b) = (a, b)
          funcx x (index, left, right) = if index < m then (index - 1, x:left, right) else (index - 1, left, x:right)

merge::(Ord a) => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:[]) (y:[]) = if x < y then [x, y] else [y, x]
merge (x:xs) (y:ys) = if x < y then x:(merge xs (y:ys)) else y:(merge (x:xs) ys)
