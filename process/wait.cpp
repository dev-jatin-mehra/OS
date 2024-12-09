#include <bits/stdc++.h>

using namespace std;

int main()
{
    pid_t cpid;
    if (fork() == 0)
    {
        exit(0);
    }
    else
    {
        cpid = wait(NULL);
    }
    cout << "Parent PID=" << getpid() << endl;
    cout << "Child PID=" << cpid << endl;
    return 0;
}