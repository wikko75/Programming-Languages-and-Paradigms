#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h> 


struct Fork
{
    int id;
    pthread_mutex_t mutex;
};


struct PhilosopherData 
{
    int philosopher_idx;
    int meals_to_eat;
    int no_of_philosophers;
};



void* eat(void* forks_array);

void clean_up(pthread_t* philosophers, struct Fork* forks, struct PhilosopherData* data);

void join_philosopher_threads(pthread_t* philosophers_array, int no_of_philosophers);

void sleepMillis(int milliseconds);

// pointer to forks array
static struct Fork* forks = NULL;


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
    forks = (struct Fork*) malloc(sizeof(struct Fork) * no_of_philosophers);

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

    for (int i = 0; i < no_of_philosophers; ++i)
    {
        data[i].philosopher_idx = i;
        data[i].meals_to_eat = 5;
        data[i].no_of_philosophers = no_of_philosophers;
        pthread_create(&philosophers[i], NULL, eat, (void*)(data + i));
    }

    join_philosopher_threads(philosophers, no_of_philosophers);

    printf("\nAll philosophers have finished all of their meals :) \n");
    clean_up(philosophers, forks, data);

    return 0;
}


void* eat(void *data_array)
{
    struct PhilosopherData* philosopher_data = (struct PhilosopherData*) data_array;
    const int philosopher_idx = philosopher_data->philosopher_idx;
    const int left_fork = philosopher_data->philosopher_idx;
    const int right_fork = (left_fork + 1) % philosopher_data->no_of_philosophers;
    int* meals_left = &philosopher_data->meals_to_eat;

    while (1)
    {  
        sleepMillis(100);
        printf("Philosopher %d wants to eat (%d meals to eat left)\n", philosopher_idx, *meals_left);
        
        // try to take left fork
        if (pthread_mutex_trylock(&forks[left_fork].mutex) == 0)
        {
            // try to take right fork
            if (pthread_mutex_trylock(&forks[right_fork].mutex) == 0)
            {
                // eat the meal
                *meals_left -= 1;

                printf("Philosopher %d just ate his meal (%d meals to eat left)\n", philosopher_idx, *meals_left);

                // put down right fork
                pthread_mutex_unlock(&forks[right_fork].mutex);
                // put down left fork
                pthread_mutex_unlock(&forks[left_fork].mutex);
            }
            else
            {
                // put down left fork
                pthread_mutex_unlock(&forks[left_fork].mutex);
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

void sleepMillis(const int milliseconds)
{
    const struct timespec ts = {
        milliseconds / 1000,              // seconds
        (milliseconds % 1000) * 1000000   // nanoseconds
    };
    // ts.tv_sec = milliseconds / 1000;
    // ts.tv_nsec = (milliseconds % 1000) * 1000000;

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



// TODO Cleanup & code organization