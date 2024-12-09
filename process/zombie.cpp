#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main()
{
    pid_t pid = fork();
    if (pid > 0)
    {
        sleep(50);
    }
    else
    {
        exit(0);
    }
    return 0;
}