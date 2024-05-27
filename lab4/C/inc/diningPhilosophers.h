#ifndef DINING_PHILOSOPHERS_H
#define DINING_PHILOSOPHERS_H

#include <pthread.h>


struct Fork
{
    int id;
    pthread_mutex_t mutex;
};


struct PhilosopherData 
{
    int philosopher_idx;
    int meals_to_eat;
    struct Fork* p_left_fork;
    struct Fork* p_right_fork;
};


void* eat(void* philosopher_data);

void clean_up(pthread_t* philosophers, struct Fork* forks, struct PhilosopherData* data);

void join_philosopher_threads(pthread_t* philosophers_array, int no_of_philosophers);

void sleep_millis(int milliseconds);

#endif
