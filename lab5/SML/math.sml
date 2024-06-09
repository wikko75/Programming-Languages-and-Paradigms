fun binomial (n : int, k : int) : int = if n = k orelse k = 0 then  
    1
    else
        binomial(n-1, k) + binomial (n-1, k-1);


fun build_triangle 0 = [1]
  | build_triangle n =
    let
        val previous_row = build_triangle (n - 1)
    in
        1 :: ListPair.map op+ (List.take(previous_row, n), List.drop(previous_row, 1)) @ [1] 
    end;

fun binomial2 (n : int, k : int) : int =
    if n = k orelse k = 0 then  
        1
    else
        List.nth(build_triangle(n), k);

    
fun merge ([], []) = []
    | merge ([], right) = right
    | merge (left, []) = left
    | merge (left, right) = 
        if hd left < hd right then
            hd left :: merge (tl left, right)
        else
            hd right :: merge (left, tl right);


fun merge_sort [] = []
    | merge_sort [n] = [n]
    | merge_sort xs = let
        val mid = ( List.length(xs) ) div  2
        val left = merge_sort ( List.take(xs, mid) )
        val right = merge_sort ( List.drop(xs, mid) )
    in
        merge(left, right)
    end;


fun de (0, b) = (0, 1, b)
  | de (a, 0) = (1, 0, a)
  | de (a, b) =
    let
        val (x1, y1, gcd) = de (b, a mod b)
        val x = y1
        val y = x1 - (a div b) * y1
    in
        (x, y, gcd)
    end;




fun get_next_prime n =
    let
        fun is_prime number =
            let
                fun is_divisible (n, d) =
                    n mod d = 0
                fun check_divisors (n, d) =
                    if d * d > n then
                        true
                    else if is_divisible (n, d) then
                        false
                    else
                        check_divisors (n, d + 1)
            in
                if number < 2 then
                    true
                else
                    check_divisors (number, 2)
            end;
    in
        if is_prime n then
            n
        else
            get_next_prime (n + 1)
    end;


fun get_prime_coefficients n =
    let
        fun helper (n, coeffList, start) =
            let
                val nextPrime = get_next_prime start
            in
                if nextPrime > n then
                    coeffList
                else if n mod nextPrime = 0 then
                    helper ( (n div nextPrime), (nextPrime :: coeffList), nextPrime )
                else
                    helper (n, coeffList, (nextPrime + 1))
            end
    in
        helper (n, [], 2)
    end;


fun prime_factors n =
    if n < 1 then
        nil
    else if n <= 2 then
        [n]
    else
        get_prime_coefficients n;


fun gcd (a, 0) = a
  | gcd (a, b) = gcd (b, a - b*(a div b))

      
fun totient (n : int) : int =  
    if n < 2 then
        ~1
    else
      let
        fun count_relatively_prime_numbers (n, a, accu) = 
            if a > n then
                accu
            else if gcd (n, a) = 1 then
                count_relatively_prime_numbers (n, (a + 1), (accu + 1))
            else
                count_relatively_prime_numbers (n, (a + 1), accu)
      in
        count_relatively_prime_numbers (n, 1, 0)
      end; 


fun totient2 (n : int) : int =
    if n < 2 then
      ~1
    else
      let
        val n_range_list = List.tabulate(n, fn x => x)
        val prime_factors_list = prime_factors n
        fun is_not_multiple (x) : bool = 
            if List.exists(fn n => (x mod n) = 0) prime_factors_list then (*check if some prime factor divides x *)
              false
            else
              true
      in
        List.length(List.filter(is_not_multiple) n_range_list)
      end


fun primes (n : int) =
    if n < 2 then
      nil
    else
      let
        fun get_primes (start, primes_list) =
            let
              val current_prime = get_next_prime start
            in
                if current_prime > n then
                    primes_list
                else
                    get_primes (current_prime + 1, current_prime :: primes_list)
            end
      in
        get_primes (2, nil)
      end