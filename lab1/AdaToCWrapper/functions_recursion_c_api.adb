package body Functions_C_API is

    function Factorial_Tail_Recursion (N : int; Acc : in out int) return int is
    begin   
        if N = 1 then
            return Acc;
        end if;
        Acc := Acc * N;
        return Factorial_Tail_Recursion (N - 1, Acc);
    end Factorial_Tail_Recursion;


    function Factorial (N : int) return int is
        Acc : int := 1;
    begin
        return Factorial_Tail_Recursion(N => N, Acc => Acc);
    end Factorial;


    function GCD (A, B : int) return int is
    begin

        if A <= 0 then
            return -1;
        end if;

        if B = 0 then
            return A;
        end if;

    return GCD(B, A mod B);

    end GCD;


    function Diofantic_Eq (A, B : int) return Solution is
        Result : Solution;
        X : int;
        Y : int;
    begin
        if B = 0 then
            Result.X := 1;
            Result.Y := 0;
            return Result;
        end if;

        declare
            PrevResult : Solution := Diofantic_Eq(A => B, B => A mod B);
        begin
            X := PrevResult.Y;
            Y := PrevResult.X - PrevResult.Y * ( A / B ); 

        end;
        
        Result := (X, Y);
        return Result;

    end Diofantic_Eq;


end Functions_C_API;