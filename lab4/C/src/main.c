#include <stdio.h>
#include <stdlib.h>
#include "diningPhilosophers.h"



int main(int args, char** argv)
{
    if (args != 2)
    {
        printf("Usage:\n%s <no. of philosophers>\n", argv[0]);
        return 0;
    }

    int no_of_philosophers = atoi(argv[1]);
    
    if (no_of_philosophers <= 0)
    {
        printf("No. of philosophers <= 0\nAborting...\n");
        return 0;
    }
    
    // array of philosophers
    pthread_t* philosophers = (pthread_t*) malloc(sizeof(pthread_t) * no_of_philosophers);

    // array of forks
    struct Fork* forks= (struct Fork*) malloc(sizeof(struct Fork) * no_of_philosophers);

    // array of philosophers' data
    struct PhilosopherData* data = (struct PhilosopherData*) malloc(sizeof(struct PhilosopherData) * no_of_philosophers);

    // initialize forks
    for (int i = 0; i < no_of_philosophers; ++i)
    {
        forks[i].id = i;
        if (pthread_mutex_init(&forks->mutex, NULL) == -1)
        {
            perror("Error initializing fork mutex");
            clean_up(philosophers, forks, data);
            return 0;
        }
    }

    // initialize philosophers
    for (int i = 0; i < no_of_philosophers; ++i)
    {
        data[i].philosopher_idx = i;
        data[i].meals_to_eat = 5;
        data[i].p_left_fork  = &forks[i];
        data[i].p_right_fork = &forks[(i + 1) % no_of_philosophers];

        pthread_create(&philosophers[i], NULL, eat, (void*)(data + i));
    }

    join_philosopher_threads(philosophers, no_of_philosophers);

    printf("\nAll philosophers have finished all of their meals :) \n");
    clean_up(philosophers, forks, data);

    return 0;
}
