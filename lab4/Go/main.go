package main;

import (
   "os"
   "strconv"
   "fmt"
)

func main() {
   if len(os.Args)==2 {
      noOfPhilosophers, _ := strconv.Atoi(os.Args[1])

      var meal int
      mealArray := make([]int, noOfPhilosophers)

      for i := 0; i < noOfPhilosophers; i++ { 
         fmt.Printf("Philosopher %d: meals to eat:\n", i)
         fmt.Scanln(&meal)
         mealArray[i] = meal
      }

      diningPhilosophers(noOfPhilosophers, mealArray)

   } else {
      fmt.Printf("Usage: go run . <no. of philosophers>\n")
      fmt.Printf("Running default mode (5 philosophers, each eating 5 meals)\n")

      mealArray := []int {5,5,5,5,5}
      diningPhilosophers(5, mealArray)
   }

}
