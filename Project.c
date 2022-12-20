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
