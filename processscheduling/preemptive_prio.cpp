#include <iostream>
using namespace std;

int main() {
    int n, i, j, time = 0, largest;
    int a[20], b[20], p[20], remaining_burst[20], completed = 0;
    float tat = 0, wt = 0;
    
    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the arrival time, burst time and priority:\n";
    for (i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        remaining_burst[i] = b[i];
    }

    p[19] = -1;

    int ct[20];

    for (time = 0; completed != n; time++) {
        largest = 19;

        for (i = 0; i < n; i++) {
            if (a[i] <= time && remaining_burst[i] > 0 && p[i] > p[largest]) {
                largest = i;
            }
        }

        remaining_burst[largest]--;

        if (remaining_burst[largest] == 0) {
            completed++;
            ct[largest] = time + 1;
            tat += ct[largest] - a[largest];
            wt += ct[largest] - a[largest] - b[largest];
        }
    }

    cout << "Average Turnaround Time = " << tat / n << endl;
    cout << "Average Waiting Time = " << wt / n << endl;

    return 0;
}