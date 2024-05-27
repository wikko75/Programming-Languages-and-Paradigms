#include "diningPhilosophers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


void* eat(void *data)
{
    struct PhilosopherData* philosopher_data = (struct PhilosopherData*) data;
    const int philosopher_idx = philosopher_data->philosopher_idx;
    struct Fork* left_fork = philosopher_data->p_left_fork;
    struct Fork* right_fork = philosopher_data->p_right_fork;
    int* meals_left = &philosopher_data->meals_to_eat;

    while (1)
    {  
        sleep_millis(100);
        printf("Philosopher %d wants to eat      (%d meals to eat left)\n", philosopher_idx, *meals_left);
        
        // try to take left fork
        if (pthread_mutex_trylock(&left_fork->mutex) == 0)
        {
            // try to take right fork
            if (pthread_mutex_trylock(&right_fork->mutex) == 0)
            {
                // eat the meal
                *meals_left -= 1;

        printf("Philosopher %d just ate his meal (%d meals to eat left)\n", philosopher_idx, *meals_left);

                // put down right fork
                pthread_mutex_unlock(&right_fork->mutex);
                // put down left fork
                pthread_mutex_unlock(&left_fork->mutex);
            }
            else
            {
                // put down left fork
                pthread_mutex_unlock(&left_fork->mutex);
            }
        }

        if (*meals_left == 0)
        {
            printf("Philosopher %d finished all of his meals!\n", philosopher_idx);
            break;
        }
    }
    
    return NULL;
}

void join_philosopher_threads(pthread_t *philosophers_array, const int no_of_philosophers)
{
    for (int i = 0; i < no_of_philosophers; ++i)
    {
        pthread_join(philosophers_array[i], NULL);
    }
}

void sleep_millis(const int milliseconds)
{
    const struct timespec ts = {
        milliseconds / 1000,              // seconds
        (milliseconds % 1000) * 1000000   // nanoseconds
    };

    int result = 0;
    do
    {
        result = nanosleep(&ts, NULL);
    } while (result);
}

void clean_up(pthread_t* philosophers, struct Fork* forks, struct PhilosopherData* data)
{
    free(philosophers);
    free(forks);
    free(data);
}

