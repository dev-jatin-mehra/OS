#include <iostream>
#include <vector>
using namespace std;
int main() {
    cout << "Banker's Algorithm" << endl;
    int P, R;
    cout << "Enter the number of processes: ";
    cin >> P;
    cout << "Enter the number of resources: ";
    cin >> R;
    vector<int> available(R);
    cout << "Enter the available resources vector:\n";
    for (int i = 0; i < R; i++)
        cin >> available[i];
    vector<vector<int>> allot(P, vector<int>(R));
    vector<vector<int>> max(P, vector<int>(R));
    vector<vector<int>> need(P, vector<int>(R));
    cout << "Enter the allocation matrix:\n";
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            cin >> allot[i][j];
        }
    }
    cout << "Enter the max matrix:\n";
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            cin >> max[i][j];
        }
    }
    cout << "Resource need:\n";// Calculate the Need matrix
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allot[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> work = available;
    vector<int> safeSequence(P);
    vector<bool> finish(P, false);
    int ind = 0;
    for (int k = 0; k < P; k++) {
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool flag = true;
                for (int j = 0; j < R; j++) {
                    if (need[i][j] > work[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    safeSequence[ind++] = i;
                    for (int y = 0; y < R; y++)
                        work[y] += allot[i][y];
                    finish[i] = true;
                }
            }
        }
    }
    cout << "\nFollowing is the Safe Sequence:\n";
    for (int i = 0; i < P; i++)
        cout << " P" << safeSequence[i];
    cout << endl;

    return 0;
}
