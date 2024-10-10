#include<iostream>
#include<unistd.h>
using namespace std;
int main(){
    pid_t p = fork();
    if(p>0){
        cout<<"Parent Process Created !"<<endl;
    }
    else if(p==0){
        cout<<"Child Process Created !"<<endl;
    }
    else{
        cout<<"Fork Not Working !"<<endl;
    }
    // return 0;
}

/*OUTPUT:
    "C:\Users\jatin\OneDrive\Pictures\Screenshots\Screenshot 2024-09-27 100244.png"
*/




