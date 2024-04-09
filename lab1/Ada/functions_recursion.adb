with Ada.Text_IO; 
package body Functions is
    
    function Factorial_Tail_Recursion (N : Integer; Acc : in out Integer) return Integer is
    begin   
        if N = 1 then
            return Acc;
        end if;
        Acc := Acc * N;
        return Factorial_Tail_Recursion (N - 1, Acc);
    end Factorial_Tail_Recursion;


    function Factorial (N : Integer) return Integer is
        Acc : Integer := 1;
    begin
        return Factorial_Tail_Recursion(N => N, Acc => Acc);
    end Factorial;


    function GCD (A, B : Integer) return Integer is
    begin

        if A <= 0 then
            return -1;
        end if;

        if B = 0 then
            return A;
        end if;

    return GCD(B, A mod B);

    end GCD;


    function Diofantic_Eq (A, B, C : Integer) return Solution is
        Result : Solution;
        X : Integer;
        Y : Integer;
        CTemp : Integer;
    begin

        if  c mod (GCD(A => A, B => B)) /= 0 then
            Ada.Text_IO.Put_Line("Wrong c provided: c % GCD(A, B) != 0");
            Result := (X => -1, Y => -1);
            return Result;
        end if;

        if B = 0 then
            Result.X := 1;
            Result.Y := 0;
            return Result;
        end if;

        declare
            PrevResult : Solution := Diofantic_Eq(A => B, B => A mod B, C => C);
        begin
            X := PrevResult.Y;
            Y := PrevResult.X - PrevResult.Y * ( A / B ); 

        end;
        
        Result := (X, Y);
        return Result;

    end Diofantic_Eq;


end Functions;