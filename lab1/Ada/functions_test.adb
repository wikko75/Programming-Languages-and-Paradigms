with Ada.Text_IO; 
with Functions; use Functions;


procedure Functions_Test is
    procedure Print (S : String) renames Ada.Text_IO.Put_Line;
begin
    Print ("Testing Factorial: " & Integer'Image (Factorial(5)) );

    Print ("Testing GCD: " & Integer'Image (GCD(A => 12,  B => 4)) );


    declare
        Diof_Eg_Res : Solution;
    begin
        Diof_Eg_Res := Diofantic_Eq (A => 1914, B => 899);
        Print ("Testing Diofantic_Eq: [" & Integer'Image (Diof_Eg_Res.X) & ", " & Integer'Image (Diof_Eg_Res.Y) & " ]");
        
    end;
    
end Functions_Test;