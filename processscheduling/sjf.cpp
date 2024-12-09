#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10], b[10], x[10], time = 0, remain = 0, smallest, tat[10], wt[10], ct[10];
    int n;
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
        x[i] = b[i]; 
    }
    b[9] = 9999;
    for (time = 0; remain != n;)
    {
        smallest = 9;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= time && b[i] < b[smallest] && b[i] > 0)
            {
                smallest = i;
            }
        }

        if (smallest == 9)
        {
            time++;
            continue;
        }

        
        time += b[smallest];
        ct[smallest] = time;
        tat[smallest] = ct[smallest] - a[smallest];
        wt[smallest] = tat[smallest] - x[smallest];
        b[smallest] = 0;
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
