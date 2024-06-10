merge([], RIGHT, RIGHT).
merge(LEFT, [], LEFT).
merge([HL|TL], [HR|TR], [HL|T]) :-
        HL =< HR,
        merge(TL, [HR|TR], T).
merge([HL|TL], [HR|TR], [HR|T]) :-
        HL > HR,
        merge([HL|TL],TR, T).

split([], [], []).
split([X], [X], []).
split([H1, H2|T], [H1|T1], [H2|T2]) :-
    split(T, T1, T2).

mergesort([], []).
mergesort([X], [X]).
mergesort(List, Sorted) :-
    split(List, L1, L2),
    mergesort(L1, Sorted1),
    mergesort(L2, Sorted2),
    merge(Sorted1, Sorted2, Sorted).


gcd(0, B, B) :- B \= 0.
gcd(A, 0, A) :- A \= 0.
gcd(A, B, G) :-
    A \= 0,
    B \= 0,
    R is A mod B,
    gcd(B, R, G).

de(0, B, 0, 1, B) :- B \= 0.
de(A, 0, 1, 0, A) :- A \= 0.
de(A, B, X, Y, G) :-
    B \= 0,
    Q is A // B,
    R is A mod B,
    de(B, R, X1, Y1, G),
    X is Y1,
    Y is X1 - Q * Y1.


is_prime(2).
is_prime(3).
is_prime(N) :-
    N > 3,
    N mod 2 =\= 0,
    \+ has_factor(N, 3).

has_factor(N, F) :-
    N mod F =:= 0.
has_factor(N, F) :-
    F * F < N,
    F2 is F + 2,
    has_factor(N, F2).

next_prime(P, NP) :-
    NP is P + 1,
    is_prime(NP).

smallest_prime_factor(N, F) :-
    between(2, N, F),
    N mod F =:= 0,
    is_prime(F), !.

prime_factors(1, []).
prime_factors(N, [F|Fs]) :-
    N > 1,
    smallest_prime_factor(N, F),
    N1 is N // F,
    prime_factors(N1, Fs).


totient(N, T) :-
    findall(X, (between(1, N, X), gcd(N, X, 1)), RelPrimes),
    length(RelPrimes, T).

primes(N, P) :-
    findall(X, (between(2, N, X), 
    is_prime(X)), P).