-- Haskell ❤️❤️❤️

binomial :: Int -> Int -> Int
binomial n 0 = 1
binomial n k = if n == k then 1
               else binomial (pred n) k + binomial (pred n) (pred k)

build_triangle_row :: Int -> [Int] -> [Int]
build_triangle_row 0 prev_row = prev_row
build_triangle_row n prev_row = build_triangle_row (pred n) next_row
                                where
                                    next_row = 1 : zipWith (+) (init prev_row) (tail prev_row) ++ [1]
                                
binomial2 :: Int -> Int -> Int
binomial2 n 0 = 1
binomial2 n k = if n == k then 1
                else (build_triangle_row n [1])!!k

merge :: [Int] -> [Int] -> [Int]
merge [] right_part = right_part
merge left_part []  = left_part
merge left_part right_part = if head left_part < head right_part then 
                                head left_part : (merge (tail left_part) right_part)
                             else 
                                head right_part : (merge left_part (tail right_part))

merge_sort :: [Int] -> [Int]
merge_sort [] = []
merge_sort [x] = [x]
merge_sort list = merge (merge_sort left_part) (merge_sort right_part)
                  where
                        split_result = splitAt (div (length list) 2) list
                        left_part = fst split_result
                        right_part = snd split_result
         
de :: Int -> Int -> (Int, Int, Int)
de 0 b = (0, 1, b)
de a 0 = (1, 0, a)
de a b = (x, y, gcd)
         where
            (x1, y1, gcd) = de b (mod a b)
            x = y1
            y =  x1 - (div a b) * y1

is_prime :: Int -> Bool
is_prime 2 = True
is_prime 3 = True
is_prime n
            | n < 2 = False 
            | otherwise = not (any (\x -> mod n x == 0) [2..isqrt n])
                where
                isqrt :: Int -> Int
                isqrt = floor . sqrt . fromIntegral

get_next_prime :: Int -> Int
get_next_prime 2 = 2
get_next_prime 3 = 3
get_next_prime n = if is_prime n then n
                   else
                       get_next_prime (succ n)


get_prime_factors :: Int -> Int -> [Int]
get_prime_factors n start = if next_prime > n then
                        []
                      else 
                        if mod n next_prime == 0 then
                            next_prime : get_prime_factors next_n start
                        else
                            get_prime_factors n (next_prime + 1)
                      where
                        next_prime = get_next_prime start
                        next_n = div n next_prime

prime_factors :: Int -> [Int]
prime_factors n = get_prime_factors n 2

totient :: Int -> Int
totient n = length([x | x <- [1..n], gcd x n == 1])
 
totient2 :: Int -> Int
totient2 n = length([ x | x <- [1..n], not (any (\y -> mod x y == 0) (prime_factors n) ) ])

primes :: Int -> [Int]
primes n | n < 2 = []
         | otherwise = [x | x <- [2..n], is_prime x == True]