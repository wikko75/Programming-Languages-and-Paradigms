with Ada.Text_IO;                   use Ada.Text_IO;
with Ada.Integer_Text_IO;           use Ada.Integer_Text_IO;

procedure Main is
    procedure Print(S : String) renames Put_Line;

    No_Of_Philosophers : Natural := 5;

    protected type Fork is
        entry Take(Philosopher_ID : Natural);
        entry Release(Philosopher_ID : Natural);
        function IsAvailable return Boolean;
    private
        Available : Boolean := True;
    end Fork;

    task type Philosopher is
        entry set(ID : Natural; Meals_To_Eat : Natural);
    end Philosopher;

    protected body Fork is
        entry Take(Philosopher_ID : Natural) when Available is
        begin
            Put_Line("Taken by " & Integer'Image(Philosopher_ID));
            Available := False;
        end Take;

        entry Release(Philosopher_ID : Natural) when not Available is
        begin
            Put_Line("Released by " & Integer'Image(Philosopher_ID));
            Available := True;
        end Release;

        function IsAvailable return Boolean is
        begin
            return Available;
        end IsAvailable;

    end Fork;



    type Fork_Array is array(1..No_Of_Philosophers) of Fork;

    Forks : Fork_Array;


    task body Philosopher is
        Philosopher_ID  : Natural;
        Meals_Left      : Natural;
        Left_Fork_Idx   : Natural;
        Right_Fork_Idx  : Natural;
    begin
        accept set(ID : Natural; Meals_To_Eat : Natural) do
            Philosopher_ID  := ID;
            Meals_Left           := Meals_To_Eat;
            Left_Fork_Idx   := Philosopher_ID;
            Right_Fork_Idx  := (Philosopher_ID mod No_Of_Philosophers) + 1;
        end set;

        loop
            Put_Line("Philosopher" & Integer'Image(Philosopher_ID) & ": Still have meals to eat! (" & Integer'Image(Meals_Left) & " left)");

            delay 1.0; 

            if Forks(Left_Fork_Idx).IsAvailable then
                Forks(Left_Fork_Idx).Take(Philosopher_ID => Philosopher_ID);
                if Forks(Right_Fork_Idx).IsAvailable then
                    Forks(Right_Fork_Idx).Take(Philosopher_ID => Philosopher_ID);
                    
                    Meals_Left := Meals_Left - 1;
                    
                    Forks(Right_Fork_Idx).Release(Philosopher_ID => Philosopher_ID);
                    Forks(Left_Fork_Idx).Release(Philosopher_ID => Philosopher_ID);
                else
                    Forks(Left_Fork_Idx).Release(Philosopher_ID => Philosopher_ID);
                end if; 
            else
                exit;  
            end if;

        if Meals_Left = 0 then
            Print("Philosopher" &Integer'Image(Philosopher_ID) & " Finished eating");
            exit;
        end if;

        end loop;

    end Philosopher;


    type Philosopher_Array is array(1..No_Of_Philosophers) of Philosopher;

    Philosophers : Philosopher_Array;


begin
    for i in 1..No_Of_Philosophers loop
        Philosophers (i). set(ID => i, Meals_To_Eat => No_Of_Philosophers - (i - 1));
    end loop;

end;