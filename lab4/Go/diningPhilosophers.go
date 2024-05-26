package main;

import (
   "fmt"
   "time"
   "sync"
)


type Fork struct {
   mu sync.Mutex
   id int
}


func diningPhilosophers(noOfPhilosophers int, mealsToEat []int) {
   forks := make([]Fork, noOfPhilosophers)
      
   for i := 0; i < noOfPhilosophers; i++ {
      forks[i] = Fork{id : i}
      fmt.Printf("Fork id: %d\n", forks[i].id)
   }
   
   var wg sync.WaitGroup

   for i := 0; i < noOfPhilosophers; i++ {
      wg.Add(1);
      go philosopher(i, &forks[i], &forks[(i + 1) % noOfPhilosophers], mealsToEat[i], &wg)
   }

   wg.Wait();
   time.Sleep(100*time.Millisecond)
}

func philosopher(index int, leftFork *Fork, rightFork *Fork, mealsToEat int, wg *sync.WaitGroup) {
   defer  wg.Done();

   fmt.Printf("Philosopher: %d, (meals left: %d)\n", index, mealsToEat)
   fmt.Printf("Philosopher %d forks: {%d, %d}\n", index, leftFork.id, rightFork.id)

   for {
      time.Sleep(20 * time.Millisecond) //random delay?
      // try to take possession of your left fork
      if leftFork.mu.TryLock() {
         // try to take possession of your right fork
         if rightFork.mu.TryLock() {
            // eat your meal
            fmt.Printf("Philosopher: %d starts eating a meal (meals left: %d)\n", index, mealsToEat);
            mealsToEat = mealsToEat - 1
            // put away right fork
            rightFork.mu.Unlock()
         }
         // put away left fork
         leftFork.mu.Unlock()
         fmt.Printf("Philosopher: %d finished a meal (meals left: %d)\n", index, mealsToEat);
      }

      if mealsToEat == 0 {
         fmt.Printf("Philosopher: %d finished all his meals!\n", index)
         break
      }
   }
}
