#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv) {
    printf("Hello, World! This is an OpenMP tutorial.\n");

    int thread_id;

    // define loop variable outside of the parallel region to avoid issues with scope and data sharing
    int i;

    // Create a parallel region where each thread will execute the code block
    //#pragma omp parallel

    // private(thread_id) clause specifies that each thread will have its own instance of the variable 'thread_id'
    // #pragma omp parallel private(thread_id)
    // -> thread_id for each thread will be bassically a different variable
    

    // barrier stops all processes from finishing until all processes have reached the barrier
    // critical ensures that only one thread executes the code block at a time

    #pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num(); // Get the thread ID
        
        // create the loop to have each thread print hello
        for (int i = 0; i < omp_get_max_threads(); i++) {
            if (i == omp_get_thread_num()) {
                printf("Hello from process: %d\n", thread_id);
            }
            #pragma omp barrier // Ensure all threads reach this point before any thread continues
        }
    }

    printf("\n\n\n");

    // #pragma omp for parallelizes the loop, distributing iterations among threads
    // test now this in a sum program

    int partial_sum, total_sum;

    #pragma omp parallel private(partial_sum) shared(total_sum)
    {
        partial_sum = 0; 
        total_sum = 0; // Initialize total_sum to 0 before the loop

        #pragma omp for
        for (int i = 0; i <= 1000; i++) {
            partial_sum += i; // Each thread calculates its own partial sum
        }

        // create thread safe region
        #pragma omp critical
        {
            total_sum += partial_sum; // Safely update the total sum with the partial sum from each thread
        }
    }

    printf("Total sum from 0 to 1000 is: %d\n", total_sum);

    return 0;
}