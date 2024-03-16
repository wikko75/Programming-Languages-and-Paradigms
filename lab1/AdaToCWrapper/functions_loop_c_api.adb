package body Functions_C_API is

    function Factorial (N : int) return int is
        Result : int := N;
        Factor : int := N - 1;
    begin
        loop
            exit when Factor = 1;
            Result := Result * Factor;
            Factor := Factor - 1;
        end loop;

        return Result;
    end Factorial;


    function GCD (A, B : int) return int is
        Temp : int;
        B_Copy : int := B;
        A_Copy : int := A;
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


    function Diofantic_Eq (A, B : int) return Solution is
        Result : Solution := (X => 0, Y => 1);
        A_Copy : int := A;
        B_Copy : int := B;
        U : int := 1;
        V : int := 0;
        Q : int;
        R : int;
        M : int;
        N : int;
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

end Functions_C_API;