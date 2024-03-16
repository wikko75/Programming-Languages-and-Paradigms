with Interfaces.C; use Interfaces.C;

package Functions_C_API is

    function Factorial (N : int) return int
        with
            Export        => True,
            Convention    => C,
            External_name => "factorial";

    function GCD(A, B : int) return int
        with
            Export        => True,
            Convention    => C,
            External_name => "gcd";


    type Solution is record
        X : int;
        Y : int;
    end record;


    function Diofantic_Eq (A, B : int) return Solution
        with
            Export        => True,
            Convention    => C,
            External_name => "diofantic_eq";

end Functions_C_API;

