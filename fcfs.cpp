#include<bits/stdc++.h>
using namespace std;

int main(){

    int n=5;
    int p[]={1,2,3,4,5};
    int at[] = {0,2,4,5,7};
    int bt[] = {3,2,1,8,4};
    float total_wt=0,total_tat = 0;
    int tat[n],ct[n],wt[n];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=bt[i];
        ct[i]=sum;
    }
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        total_tat+=tat[i];
    }
    for(int i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        total_wt+=wt[i];
    }

    cout<<"Average turn around time:"<<fixed<<setprecision(3)<<total_tat/n<<endl;
    cout<<"Average waiting time:"<<fixed<<setprecision(3)<<total_wt/n;

}