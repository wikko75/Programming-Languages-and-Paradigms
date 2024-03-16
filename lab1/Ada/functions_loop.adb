package body Functions is

    function Factorial (N : Integer) return Integer is
        Result : Integer := N;
        Factor : Integer := N - 1;
    begin
        loop
            exit when Factor = 1;
            Result := Result * Factor;
            Factor := Factor - 1;
        end loop;

        return Result;
    end Factorial;


    function GCD (A, B : Integer) return Integer is
        Temp : Integer;
        B_Copy : Integer := B;
        A_Copy : Integer := A;
    begin
    
        if A <= 0 or B <= 0 then
            return -1;
        end if;

        while B_Copy /= 0 loop
            Temp := B_Copy;
            B_Copy := A_Copy mod B_Copy;
            A_Copy := Temp;
        end loop;

        return A_Copy;

    end GCD;


    function Diofantic_Eq (A, B : Integer) return Solution is
        Result : Solution := (X => 0, Y => 1);
        A_Copy : Integer := A;
        B_Copy : Integer := B;
        U : Integer := 1;
        V : Integer := 0;
        Q : Integer;
        R : Integer;
        M : Integer;
        N : Integer;
    begin
        while A_Copy /= 0 loop

            Q := B_Copy / A_Copy;
            R := B_Copy mod A_Copy;

            M :=    Result.X - U * Q;
            N :=    Result.Y - V * Q;

            B_Copy := A_Copy;
            A_Copy := R;
            Result.X := U;
            Result.Y := V;
            U := M;
            V := N;

        end loop;
        return  Result;
    end Diofantic_Eq;

end Functions;