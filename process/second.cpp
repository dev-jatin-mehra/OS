#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pid_t p = fork();
    int evensum = 0;
    int oddsum = 0;
    if (p > 0)
    {
        cout << "Parent Process:" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] % 2 == 0)
                evensum += arr[i];
        }
        cout << "evensum: " << evensum << endl;
    }
    else if (p == 0)
    {
        cout << "Child Process:" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] % 2 == 1)
                oddsum += arr[i];
        }
        cout << "oddsum: " << oddsum << endl;
    }
    else
    {
        cout << "Fork Not Woking !" << endl;
    }
    return 0;
}
/*OUTPUT:
    "C:\Users\jatin\OneDrive\Pictures\Screenshots\Screenshot 2024-09-27 100445.png"
 */