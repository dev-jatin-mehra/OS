#include <bits/stdc++.h>
using namespace std;
int pageFaults(int pages[], int n, int capacity) {
    unordered_set<int> s;
    queue<int> indexes;
    vector<vector<int>> frameStates(capacity, vector<int>(n, -1));
    int page_faults = 0;
    for (int i = 0; i < n; i++) {
        if (s.size() < capacity) {
            if (s.find(pages[i]) == s.end()) {
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        } else {
            if (s.find(pages[i]) == s.end()) {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            } }
        queue<int> tempQueue = indexes;
        for (int j = 0; j < capacity; j++) {
            if (!tempQueue.empty()) {
                frameStates[j][i] = tempQueue.front();
                tempQueue.pop();
            } else {
                frameStates[j][i] = -1;
            } } }
    cout << "Pages:\n";
    for (int i = 0; i < n; i++) {
        cout << pages[i] << " ";
    }
    cout << "\n\n";
    cout << "Page Frames:\n";
    for (int i = 0; i < capacity; i++) {
        for (int j = 0; j < n; j++) {
            if (frameStates[i][j] != -1) {
                cout << frameStates[i][j] << " ";
            } else {
                cout << "  ";
            }}
        cout << endl;
    }
    cout << "\nPage Faults (FIFO) = " << page_faults << endl;
    return page_faults;
}
int main() {
	int size;
	cin >> size;
	int pages[size];
	for(int i=0;i<size;i++){
		cin>>pages[i];
	}
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames;
	cout<<"Enter the number of frames:";
	cin>>frames;
    cout << "FIFO Page Replacement Algorithm\n\n";
    pageFaults(pages, n, frames);
    return 0;
}
