#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void calculateCompletionTime(struct Process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;
    int shortest_job = -1;

    while (completed_processes < n) {
        shortest_job = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (shortest_job == -1 || processes[i].remaining_time < processes[shortest_job].remaining_time) {
                    shortest_job = i;
                }
            }
        }

        if (shortest_job == -1) {
            current_time++;
            continue;
        }

        processes[shortest_job].remaining_time--;
        current_time++;

        if (processes[shortest_job].remaining_time == 0) {
            processes[shortest_job].completion_time = current_time;
            completed_processes++;
        }
    }
}

void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
}

void calculateWaitingTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void calculateAverageTimes(struct Process processes[], int n, float *average_waiting_time, float *average_turnaround_time) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    *average_waiting_time = (float)total_waiting_time / n;
    *average_turnaround_time = (float)total_turnaround_time / n;
}

void displayProcessDetails(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
            processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main() {
    int n;
    struct Process processes[MAX_PROCESSES];
    float average_waiting_time, average_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival_times[MAX_PROCESSES];
    int burst_times[MAX_PROCESSES];

    printf("Enter the arrival time for each process (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrival_times[i]);
    }

    printf("Enter the burst time for each process (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst_times[i]);
    }

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].arrival_time = arrival_times[i];
        processes[i].burst_time = burst_times[i];
        processes[i].remaining_time = burst_times[i];
    }

    calculateCompletionTime(processes, n);
    calculateTurnaroundTime(processes, n);
    calculateWaitingTime(processes, n);
    calculateAverageTimes(processes, n, &average_waiting_time, &average_turnaround_time);

    displayProcessDetails(processes, n);

    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

    return 0;
}

