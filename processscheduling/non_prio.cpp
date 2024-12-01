#include <iostream>
using namespace std;

int main() {
    int n, i, j, time = 0, largest;
    int a[20], b[20], p[20], completed = 0;
    int completion_time[20], last_completion_time[20];
    float tat = 0, wt = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the arrival time, burst time, and priority:\n";
    for (i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
    }

    p[19] = -1;

    for (time = 0; completed != n; ) {
        largest = 19;

        for (i = 0; i < n; i++) {
            if (a[i] <= time && p[i] > p[largest] && b[i] > 0) {
                largest = i;
            }
        }

        if (largest == 19) {
            time++; 
            continue;
        }
        // start_time[largest] = time; 
        time += b[largest]; 
        completion_time[largest] = time;
        last_completion_time[largest] = time;

        tat += completion_time[largest] - a[largest];
        wt += completion_time[largest] - a[largest] - b[largest];

        b[largest] = 0;
        completed++;
    }

    cout << "Average Turnaround Time = " << tat / n << endl;
    cout << "Average Waiting Time = " << wt / n << endl;

    return 0;
}