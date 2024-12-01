#include <iostream>
#include <vector>
using namespace std;

void bestFit(vector<int>& blockSize, int m, vector<int>& processSize, int n) {
    vector<int> allocation(n, -1);
    
    for (int i = 0; i < n; i++) {
        int best = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (best == -1 || blockSize[best] > blockSize[j])
                    best = j;
            }
        }
        if (best != -1) {
            allocation[i] = best;
            blockSize[best] -= processSize[i];
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
    int m, n;
    cout << "Best Fit Allocation\n";
    cout << "Enter the number of blocks: ";
    cin >> m;

    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> blockSize(m);
    vector<int> processSize(n);

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

    bestFit(blockSize, m, processSize, n);
    return 0;
}
