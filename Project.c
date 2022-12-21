#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#include <math.h>

// To implement first come first serve scheduling

void fcfs(int, int[], int[], int[]);

// To implement round robin scheduling

void rr(int, int[], int[], int[], int);

// To implement shortest runtime first

void srtf(int, int[], int[], int[]);

// To calculate turn around time

void turn_around(int, int[], int[]);

// To calculate the CPU usage

void cpu_usage(int, int[], int);

// For duplicating arrays

void copy_array(int, int[], int[]);

int main(int argc, char *argv[])

{

    // Size of the array

    int size = 0;

    // Time quantum of the scheduling

    int quantum;

    // Information read from the read file

    int pid[20], arrival_time[20], burst_time[20];

    // Variable for the read file

    FILE *file;

    // Sets the file to read

    file = fopen(argv[1], "r");

    if ((argc < 3) || (argc > 4))

    {

        printf("Usage: proj2 input_file FCFS|RR|SRJF [quantum]n");
    }

    else

    {

        if (file)

        {

            while (!feof(file))

            {

                fscanf(file, "%d %d %d", &pid[size], &arrival_time[size], &burst_time[size]);

                size += 1;
            }
        }
    }
}
// No process in the queue, queue is empty

if (size == 0)

{

    goto empty_queue;
}

printf("Schdeuling Algorithm: ");

// First-Come-First-Serve

if (!strcmp(argv[2], "FCFS"))
{

    {

        printf("FCFSn");

        fcfs(size, pid, burst_time, arrival_time);
    }

    else if (!strcmp(argv[2], "RR"))

    {

        if (argc == 4)

        {

            printf("RRn");

            quantum = atoi(argv[3]);

            rr(size, pid, burst_time, arrival_time, quantum);
        }

        else

        {

            printf("...n Invalid Entryn");
        }
    }

    else if (!strcmp(argv[2], "SRTF"))

    {

        printf("SRTFn");

        srtf(size, pid, burst_time, arrival_time);
    }

    else

    {

        printf("USAGE: FCFS, RR, SRTFn");
    }
}

/* end of run */

return 0;

empty_queue : printf("nProcess queue is empty. End of run.n");
{
}

// SRTF: To implement shortest run-time first

void srtf(int size, int pid[], int burst_time[], int arrival_time[])

    int i,
    j, n, k, time, result;

int temp_burst[size], waiting[size], response_time[size];

int turnaround_time[size], wait_time[size];

float float_result;

bool done, processed[size];

// Duplicates burst_time array

copy_array(size, burst_time, temp_burst);

printf("Total of %d tasks are read. Press 'enter' to start...", size);

getchar();

printf("==================================================================n");

// Initializes all processed to false

for (i = 0; i < size; ++i)

{

    processed[i] = false;
}

// Initializes the response time

for (i = 0; i < size; ++i)

{

    response_time[i] = -1;
}

// Initializes the wait time

for (i = 0; i < size; ++i)

{

    wait_time[i] = 0;
}
