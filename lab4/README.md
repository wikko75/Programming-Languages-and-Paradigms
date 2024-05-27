# Implementation of Dining philosophers problem

## `Prerequisites`

- C, Ada, Go compilers
- Make


## `Problem Description`
Philosophers are seated around a circular table. Each philosopher does only two things: think and eat. In front of each philosopher is a plate of spaghetti (or whatever meal you think is sutable). To eat, a philosopher needs two forks: the one on their left and the one on their right. Each fork lies between each pair of adjacent philosophers, and so there's always one fork lacking for all philosophers to eat simultaneously.


----


<div align="center">
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/81/Dining_philosophers_diagram.jpg/1024px-Dining_philosophers_diagram.jpg" alt="Philosophers and table" width="300">
</div>


----


The challenge is to design a protocol that ensures:

1. No two philosophers can use the same fork simultaneously.
2. No philosopher is starved, meaning each philosopher gets a chance to eat.
232. The solution avoids deadlock, a situation where no progress is possible because each philosopher holds one fork and waits for the other.

Additionaly:
- number of philosophers is **not** restricted to a classical case (5)
- all philosophers behave **the same**

## `Build and Run`
## Ada

``` powershell
gprbuild Dining_philosophers.gpr
```


---


## Go

``` powershell
go run . <no. of philosophers>
 ```

or (5 philosophers each eating 5 meals):

``` powershell
go run .
 ```

---


## C
``` Powershell
make
 ```

 ``` Powershell
./dining_philosophers.out <no. of philosophers>
```

----


## `Sample usage`

``` powershell
./dining_philosophers.out 10
Philosopher 0 wants to eat      (5 meals to eat left)
Philosopher 4 wants to eat      (5 meals to eat left)
Philosopher 4 just ate his meal (4 meals to eat left)
Philosopher 0 just ate his meal (4 meals to eat left)
Philosopher 6 wants to eat      (5 meals to eat left)
Philosopher 3 wants to eat      (5 meals to eat left)
Philosopher 1 wants to eat      (5 meals to eat left)
Philosopher 1 just ate his meal (4 meals to eat left)
Philosopher 9 wants to eat      (5 meals to eat left)
Philosopher 9 just ate his meal (4 meals to eat left)
Philosopher 7 wants to eat      (5 meals to eat left)
Philosopher 3 just ate his meal (4 meals to eat left)
Philosopher 6 just ate his meal (4 meals to eat left)
Philosopher 5 wants to eat      (5 meals to eat left)
Philosopher 5 just ate his meal (4 meals to eat left)
Philosopher 8 wants to eat      (5 meals to eat left)
Philosopher 8 just ate his meal (4 meals to eat left)
Philosopher 2 wants to eat      (5 meals to eat left)
Philosopher 2 just ate his meal (4 meals to eat left)
Philosopher 0 wants to eat      (4 meals to eat left)
Philosopher 2 wants to eat      (4 meals to eat left)
Philosopher 2 just ate his meal (3 meals to eat left)
Philosopher 5 wants to eat      (4 meals to eat left)
Philosopher 5 just ate his meal (3 meals to eat left)
Philosopher 7 wants to eat      (5 meals to eat left)
Philosopher 7 just ate his meal (4 meals to eat left)
Philosopher 0 just ate his meal (3 meals to eat left)
Philosopher 4 wants to eat      (4 meals to eat left)
Philosopher 4 just ate his meal (3 meals to eat left)
Philosopher 3 wants to eat      (4 meals to eat left)
Philosopher 3 just ate his meal (3 meals to eat left)
Philosopher 8 wants to eat      (4 meals to eat left)
Philosopher 8 just ate his meal (3 meals to eat left)
Philosopher 9 wants to eat      (4 meals to eat left)
Philosopher 9 just ate his meal (3 meals to eat left)
Philosopher 1 wants to eat      (4 meals to eat left)
Philosopher 1 just ate his meal (3 meals to eat left)
Philosopher 6 wants to eat      (4 meals to eat left)
Philosopher 6 just ate his meal (3 meals to eat left)
Philosopher 2 wants to eat      (3 meals to eat left)
Philosopher 2 just ate his meal (2 meals to eat left)
Philosopher 5 wants to eat      (3 meals to eat left)
Philosopher 5 just ate his meal (2 meals to eat left)
Philosopher 0 wants to eat      (3 meals to eat left)
Philosopher 0 just ate his meal (2 meals to eat left)
Philosopher 7 wants to eat      (4 meals to eat left)
Philosopher 7 just ate his meal (3 meals to eat left)
Philosopher 4 wants to eat      (3 meals to eat left)
Philosopher 4 just ate his meal (2 meals to eat left)
Philosopher 3 wants to eat      (3 meals to eat left)
Philosopher 3 just ate his meal (2 meals to eat left)
Philosopher 8 wants to eat      (3 meals to eat left)
Philosopher 8 just ate his meal (2 meals to eat left)
Philosopher 1 wants to eat      (3 meals to eat left)
Philosopher 1 just ate his meal (2 meals to eat left)
Philosopher 6 wants to eat      (3 meals to eat left)
Philosopher 6 just ate his meal (2 meals to eat left)
Philosopher 9 wants to eat      (3 meals to eat left)
Philosopher 9 just ate his meal (2 meals to eat left)
Philosopher 2 wants to eat      (2 meals to eat left)
Philosopher 2 just ate his meal (1 meals to eat left)
Philosopher 5 wants to eat      (2 meals to eat left)
Philosopher 5 just ate his meal (1 meals to eat left)
Philosopher 0 wants to eat      (2 meals to eat left)
Philosopher 0 just ate his meal (1 meals to eat left)
Philosopher 7 wants to eat      (3 meals to eat left)
Philosopher 7 just ate his meal (2 meals to eat left)
Philosopher 3 wants to eat      (2 meals to eat left)
Philosopher 3 just ate his meal (1 meals to eat left)
Philosopher 4 wants to eat      (2 meals to eat left)
Philosopher 4 just ate his meal (1 meals to eat left)
Philosopher 8 wants to eat      (2 meals to eat left)
Philosopher 8 just ate his meal (1 meals to eat left)
Philosopher 1 wants to eat      (2 meals to eat left)
Philosopher 6 wants to eat      (2 meals to eat left)
Philosopher 6 just ate his meal (1 meals to eat left)
Philosopher 9 wants to eat      (2 meals to eat left)
Philosopher 9 just ate his meal (1 meals to eat left)
Philosopher 1 just ate his meal (1 meals to eat left)
Philosopher 2 wants to eat      (1 meals to eat left)
Philosopher 2 just ate his meal (0 meals to eat left)
Philosopher 2 finished all of his meals!
Philosopher 5 wants to eat      (1 meals to eat left)
Philosopher 5 just ate his meal (0 meals to eat left)
Philosopher 5 finished all of his meals!
Philosopher 0 wants to eat      (1 meals to eat left)
Philosopher 0 just ate his meal (0 meals to eat left)
Philosopher 0 finished all of his meals!
Philosopher 7 wants to eat      (2 meals to eat left)
Philosopher 7 just ate his meal (1 meals to eat left)
Philosopher 3 wants to eat      (1 meals to eat left)
Philosopher 3 just ate his meal (0 meals to eat left)
Philosopher 3 finished all of his meals!
Philosopher 4 wants to eat      (1 meals to eat left)
Philosopher 4 just ate his meal (0 meals to eat left)
Philosopher 4 finished all of his meals!
Philosopher 8 wants to eat      (1 meals to eat left)
Philosopher 8 just ate his meal (0 meals to eat left)
Philosopher 8 finished all of his meals!
Philosopher 6 wants to eat      (1 meals to eat left)
Philosopher 6 just ate his meal (0 meals to eat left)
Philosopher 6 finished all of his meals!
Philosopher 9 wants to eat      (1 meals to eat left)
Philosopher 9 just ate his meal (0 meals to eat left)
Philosopher 9 finished all of his meals!
Philosopher 1 wants to eat      (1 meals to eat left)
Philosopher 1 just ate his meal (0 meals to eat left)
Philosopher 1 finished all of his meals!
Philosopher 7 wants to eat      (1 meals to eat left)
Philosopher 7 just ate his meal (0 meals to eat left)
Philosopher 7 finished all of his meals!

All philosophers have finished all of their meals :) 
```