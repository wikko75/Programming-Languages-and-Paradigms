# Implementation of Dining philosophers problem


## `Build and Run`
## Ada

``` Powershell
gprbuild Dining_philosophers.gpr
```

## Go

``` Powershell
go run . <no. of philosophers>
 ```

or (5 philosophers each eating 5 meals):

``` Powershell
go run .
 ```


## C
``` Powershell
clang src/main.c -o dining_philosophers.out -Wall -Wextra -pedantic -O3
 ```

 ``` Powershell
./dining_philosophers.out <no. of philosophers>
```