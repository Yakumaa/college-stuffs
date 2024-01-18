#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};

int compare(const void *, const void *);
void jobSequencing(struct Job[], int);

int main(){
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    struct Job jobs[n];
    cout << "Enter the deadline and profit of each job: ";
    for (int i = 0; i < n; i++)
    {
        jobs[i].id = i + 1;
        cin >> jobs[i].deadline >> jobs[i].profit;
    }
    jobSequencing(jobs, n);

    return 0;
}

int compare(const void *a, const void *b){
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

void jobSequencing(struct Job jobs[], int n){
    // Sort jobs in decreasing order of profit
    qsort(jobs, n, sizeof(struct Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        jobs[i].deadline > maxDeadline ? maxDeadline = jobs[i].deadline : maxDeadline;

    int slots[maxDeadline]; // array to store job slots
    for (int i = 0; i < maxDeadline; i++)
        slots[i] = -1;

    int totalProfit = 0;
    int numJobs = 0;
    for (int i = 0; i < n; i++){
        int deadline = jobs[i].deadline;
        // find a slot before the deadline for the current job
        while (deadline > 0 && slots[deadline - 1] != -1)
            deadline--;
        // if a slot is found, assign the job to the slot
        if (deadline > 0)
        {
            slots[deadline - 1] = i;
            totalProfit += jobs[i].profit;
            numJobs++;
        }
    }

    cout << "Maximum profit: " << totalProfit << endl;
    cout << "Number of jobs: " << numJobs << endl;
    cout << "Maximum profit sequence of jobs : ";
    for (int i = 0; i < maxDeadline; i++){
        (slots[i] != -1) ? cout << jobs[slots[i]].id << " " : cout << "";
    }
    cout << endl;
}

// {{4, 20}, {1, 10}, {1, 40}, {1, 30}};