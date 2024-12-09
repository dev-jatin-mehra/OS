#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10], b[10], x[10], time = 0, remain = 0, smallest, tat[10], wt[10], ct[10];
    int n, completed[10] = {0};
    cout << "Enter No. of processes: ";
    cin >> n;

    cout << "Enter Arrival Times: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter Burst Times: ";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        x[i] = b[i]; // Keep a copy of Burst Times
    }

    while (remain != n)
    {
        smallest = -1;

        // Find the process with the smallest burst time among ready processes
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= time && !completed[i])
            {
                if (smallest == -1 || b[i] < b[smallest])
                {
                    smallest = i;
                }
            }
        }

        if (smallest == -1) // No process is ready; increment time
        {
            time++;
            continue;
        }

        // Process execution
        time += b[smallest];
        ct[smallest] = time;                        // Completion time
        tat[smallest] = ct[smallest] - a[smallest]; // Turnaround time
        wt[smallest] = tat[smallest] - x[smallest]; // Waiting time
        completed[smallest] = 1;                    // Mark process as completed
        remain++;
    }

    float total_tat = 0, total_wt = 0;
    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << '\t' << a[i] << '\t' << x[i] << '\t' << ct[i] << '\t' << tat[i] << '\t' << wt[i] << endl;
        total_tat += tat[i];
        total_wt += wt[i];
    }

    cout << "\n\nAverage Waiting Time = " << total_wt / n << endl;
    cout << "Average Turnaround Time = " << total_tat / n << endl;

    return 0;
}
