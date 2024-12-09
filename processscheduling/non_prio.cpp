#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10], b[10], x[10], time = 0, remain = 0, largest, tat[10], wt[10], ct[10], p[10];
    int n;
    cout << "Enter No. of processes";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        x[i] = b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    p[9] = -1; // prioroty high to low
    float tt = 0, w = 0;
    for (time = 0; remain != n;)
    {
        largest = 9;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= time && p[i] > p[largest] && b[i] > 0)
            {
                largest = i;
            }
        }
        if (largest == 9)
        {
            time++;
            continue;
        }
        remain++;
        time += b[largest];
        ct[largest] = time;
        tat[largest] = ct[largest] - a[largest];
        wt[largest] = tat[largest] - b[largest];
        b[largest] = 0;
    }
    cout << "Process\tAT\tBT\tP\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << '\t' << a[i] << '\t' << x[i] << '\t' << p[i] << '\t' << ct[i] << '\t' << tat[i] << '\t' << wt[i] << endl;
        w += wt[i];
        tt += tat[i];
    }
    cout << "Average Turnaround Time = " << tt / n << endl;
    cout << "Average Waiting Time = " << w / n << endl;
}