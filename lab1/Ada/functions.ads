package Functions is

    function Factorial (N : Integer) return Integer;

    function GCD(A, B : Integer) return Integer;

    type Solution is record
        X : Integer;
        Y : Integer;
    end record;

    function Diofantic_Eq (A, B : Integer) return Solution;

end Functions;