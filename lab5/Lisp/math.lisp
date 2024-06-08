; Functions performing / computing:
; - binomial (2 versions)
; - merge sort
; - prime factors
; - totient (2 versions)
; - primes


(defun binomial (n k)
    (cond ((= k 0) 1)   ; edge case 1
          ((= k n) 1)   ; edge case 2
          ((< n k) 0)   ; edge case 3
          (t (+ (binomial (- n 1) k) (binomial (- n 1) (- k 1))))  ; recursion
    )
)



; cons - builds list from provided head and tail
; car/first - returns head (first element)
; cdr - return all but first element - tail


; 1. Insert first element (1)
; 2. Add (all but last from previous row) to (all but first from previous row)
; 3. Add last element (1)
(defun build_triangle (n)
    (if (= n 0) 
        '(1)   ; base case (first row)
        (let ((previous_row (build_triangle (- n 1))))
            (cons 1 
                (append
                    (mapcar #'+ (butlast previous_row) (cdr previous_row)) '(1)
                )
            )
        )
    )
)   

(defun binomial2 (n k)
        (cond ((= k 0) 1)   ; edge case 1
              ((= k n) 1)   ; edge case 2
              ((< n k) 0)   ; edge case 3
              (t (nth k (build_triangle n)))
        )
)



(defun merge_lists (L R)
  (cond
        ((null L) R)
        ((null R) L)
        ((<= (first L) (first R)) (cons (first L) (merge_lists (rest L) R)))
        (t (cons (first R) (merge_lists L (rest R))))
    )
)

; 1. Halve until there's one elem (or empty list)
; 2. Merge halves 
(defun merge_sort (L)
    (if (<= (list-length L) 1) 
        L   ; return list (since there's only one element or empty)
        (let* 
            (
                (mid (floor(/ (list-length L) 2 )))
                (left_part (subseq L 0 mid))     
                (right_part (subseq L mid)) 
            )
            (merge_lists (merge_sort left_part) (merge_sort right_part) ) ; merge two halves
        )
    )
)



(defun extended_euclides (a b)
  (if (= b 0)
      (list a 1 0) ; a * 1 + b * 0 = a
      (let* ((result (extended_euclides b (mod a b)))
             (d (first result))
             (x (second result))
             (y (third result)))
        (list d y (- x (* y (floor a b)))))))


(defun de (a b)
  (let 
    (
        (coefficients (extended_euclides a b))
    )
    (list (second coefficients)  (third coefficients) (first coefficients)))
)


(defun is_prime (number &optional (divider 2))
    (cond ((< number 2) t)
          ((> divider (sqrt number)) t)
          ((= (rem number divider) 0) nil)
          (t  (is_prime number (+ divider 1)))
    )
)

(defun get_next_prime (&optional (start 2))
    (if (is_prime start)
        start
        (get_next_prime (+ start 1))  
    )
)

(defun get_prime_coefficients (n &optional (coeff_list '()) (start 2))
    (let 
        (
            (next_prime (get_next_prime start))
        )

        (cond (
                (> next_prime n) 
                coeff_list
              )
              (
                (=(rem n next_prime) 0) ; if  next_prime | n, append next_prime to coeff_list
                (get_prime_coefficients (floor n next_prime) (cons next_prime coeff_list)) 
              ) 
              (
                t 
                (get_prime_coefficients n coeff_list (+ next_prime 1))
              )  
        )
    )
)

; TODO: make get_prime_coefficients inner function of prime_factors
(defun prime_factors (n)
    (cond ((< n 1) (print "n is not natural!"))
          ((<= n 2) n)
          (t (get_prime_coefficients n))
    )  
)


(defun totient (n)
    (if (<= n 0)
        (print "n must be natural")
        (labels 
            ((count_relatively_prime_numbers (a &optional (b 0) (accu 0))
                (cond ((< a b) accu)
                      ((=(gcd a b) 1) (count_relatively_prime_numbers a (+ b 1) (+ accu 1)))
                      (t (count_relatively_prime_numbers a (+ b 1) accu))
                )
            ))

            (count_relatively_prime_numbers n 1)
        )
    )
)


(defun list_from_1_to_n (n &optional (current 1) (acc '()))
  (if (> current n)
      (reverse acc)
      (list_from_1_to_n n (1+ current) (cons current acc))))



; 1. Get prime factors list -> A
; 2. Given list (1,...,n) -> B,  gdelete multiples of A elems in B
;   - 
(defun totient2 (n)
    (if (<= n 0) 
        (print "n must be natural")
        (let 
            (
                (prime_factors_list (prime_factors n))
                (n_range_list (list_from_1_to_n n))
            )
            
            (list-length (remove-if (lambda (x) (some (lambda (factor) (= (mod x factor) 0)) prime_factors_list)) n_range_list))
        )
    )
)