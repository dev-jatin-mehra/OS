#include<bits/stdc++.h>
using namespace std;

int main(){
    int pid = fork();
    if(pid>0){
        cout<<"IN Paernt Process !";
    }
    else if(pid==0{
        sleep(30);
        cout<<"In child Process !";
    }
    return 0;
}