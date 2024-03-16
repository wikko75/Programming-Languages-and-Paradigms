with Ada.Text_IO; use Ada.Text_IO;
with Interfaces.C; use Interfaces.C;
with C_Wrapper; use C_Wrapper;

procedure test_c_wrapper is
    procedure Print(content: String) renames Ada.Text_IO.Put_line;
    Eq_Solution : Solution; 
begin

    Print ("Factorial: " & int'Image (Factorial(5)));

    Print ("GCD: " & int'Image (GCD(12, 4)));

    Eq_Solution := Diofantic_Eq(1914, 899);

    Print("Diofantic_Eg: [X = " & int'Image (Eq_Solution.X) & ", " & int'Image (Eq_Solution.Y) & " ]");
    
end test_c_wrapper;