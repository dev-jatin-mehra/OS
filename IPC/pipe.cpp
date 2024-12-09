#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main()
{
    int pipefd[2];
    pid_t pid;
    char buffer[100];
    if (pipe(pipefd) == -1)
    {
        perror("Pipe Failed !");
        exit(1);
    }
    pid = fork();
    if (pid < 0)
    {
        perror("Fork Failed !");
        exit(1);
    }
    else if (pid == 0)
    {
        close(pipefd[1]);
        read(pipefd[0], buffer, sizeof(buffer));
        cout << "Child Process: Received Message:" << buffer << endl;
        // cout << "Child Process:Name =jatin , SiD = 220112473, pID =" << getpid() << endl;
        close(pipefd[0]);
    }

    else
    {
        close(pipefd[0]);
        const char *message = "Hello Fom rhe Parent Process !";
        write(pipefd[1], message, strlen(message) + 1);
        cout << "Parent Process: Sent Message:" << message << endl;
        // cout << "Parent Process:Name =jatin , SiD = 220112473, pID =" << getpid() << endl;
        close(pipefd[1]);
    }

    return 0;
}