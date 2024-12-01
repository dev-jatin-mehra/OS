#include <bits/stdc++.h>
using namespace std;

void worstFit(vector<int>& blockSize, int m, vector<int>& processSize, int n) {
    vector<int> allocation(n, -1);

    for (int i = 0; i < n; i++) {
        int wst = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (wst == -1 || blockSize[wst] < blockSize[j])
                    wst = j;
            }
        }
        if (wst != -1) {
            allocation[i] = wst;
            blockSize[wst] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }

    cout << "Free Blocks\n";
    for (int i = 0; i < m; i++)
        cout << blockSize[i] << "->";
    cout << endl;
}

int main() {
    cout << "Worst Fit Allocation\n";
    int m, n;
    cout << "Enter number of blocks: ";
    cin >> m;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> blockSize(m), processSize(n);

    cout << "Enter the sizes of the blocks:\n";
    for (int i = 0; i < m; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> blockSize[i];
    }

    cout << "Enter the sizes of the processes:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processSize[i];
    }

    worstFit(blockSize, m, processSize, n);

    return 0;
}
