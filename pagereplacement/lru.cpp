#include <bits/stdc++.h>
using namespace std;
bool checkHit(int incoming_page, int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
    {
        if (incoming_page == queue[i])
            return true;
    }
    return false;
}
void printFrame(int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
        cout << queue[i] << "\t";
}
int main()
{
    int incomingStream[20];
    int n, f;
    cout << "LRU Page Replacement Algorithm\n";
    cout << "Enter the number of pages: ";
    cin >> n;
    cout << "Enter the incoming page stream:\n";
    for (int i = 0; i < n; i++)
        cin >> incomingStream[i];
    cout << "Enter the number of frames: ";
    cin >> f;
    int queue[f];
    int distance[n];
    int occupied = 0;
    int pageFaults = 0;
    cout << "Page\t Frame1\t Frame2\t Frame3\n";
    for (int i = 0; i < n; i++)
    {
        cout << incomingStream[i] << ":\t\t";
        if (checkHit(incomingStream[i], queue, occupied))
        {
            printFrame(queue, occupied);
        }
        else if (occupied < f)
        {
            queue[occupied] = incomingStream[i];
            pageFaults++;
            occupied++;
            printFrame(queue, occupied);
        }
        else
        {
            int maxDistance = INT_MIN;
            int index = 0;
            for (int j = 0; j < f; j++)
            {
                distance[j] = 0;
                for (int k = i - 1; k >= 0; k--)
                {
                    distance[j]++;
                    if (queue[j] == incomingStream[k])
                        break;
                }
                if (distance[j] > maxDistance)
                {
                    maxDistance = distance[j];
                    index = j;
                }
            }
            queue[index] = incomingStream[i];
            printFrame(queue, occupied);
            pageFaults++;
        }
        cout << "\n";
    }
    cout << "Page Faults: " << pageFaults << endl;
    return 0;
}
/*Input:
Enter the number of pages: 8
Enter the incoming page stream:
7 0 1 2 0 3 0 4
Enter the number of frames: 3 */
/* Output:
Page Frame1 Frame2 Frame3
7: 7
0: 7 0  
1: 7 0 1
2: 2 0 1
0: 2 0 1
3: 2 0 3
0: 2 0 3
4: 4 0 3
Page Faults: 6 */
