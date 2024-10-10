#include <iostream>
using namespace std;

int main() 
{
    int a[10], b[10], x[10], i, smallest, remain = 0, time, n, t[10], w[10], ct[10];
    double wt = 0, tt = 0;

    cout << "Enter the number of Processes:\n";
    cin >> n;

    cout << "Enter arrival time\n";
    for(i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter burst time\n";
    for(i = 0; i < n; i++)
        cin >> b[i];

    for(i = 0; i < n; i++).
        x[i] = b[i];  

    b[9] = 9999;  

    for(time = 0; remain != n; time++)
    {
        smallest = 9;  

        for(i = 0; i < n; i++)
        {
            if(a[i] <= time && b[i] < b[smallest] && b[i] > 0)
                smallest = i;
        }

        b[smallest]--;  

        if(b[smallest] == 0)  
        {
            remain++;
            ct[smallest] = time + 1; 
            t[smallest] = ct[smallest] - a[smallest];  
            w[smallest] = t[smallest] - x[smallest]; 
        }
    }

    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    for(i = 0; i < n; i++) {
        cout << i+1 << '\t' << a[i] << '\t' << x[i] << '\t' << ct[i] << '\t' << t[i] << '\t' << w[i] << endl;
        wt += w[i];  
        tt += t[i];  
    }


    cout << "\n\nAverage waiting time = " << wt / n << endl;
    cout << "Average Turnaround time = " << tt / n << endl;

    return 0;
}