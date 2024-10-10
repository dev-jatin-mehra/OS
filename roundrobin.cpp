#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t_qt;
    int bt[100],rt[100],ct[100],tat[100],wt[100];
    int at[100]={0};
    int total_tat=0,total_wt=0;
    float atat=0,awt=0;

    cout<<"Enter the number of process: "<<endl;
    cin>>n;
    cout<<"Enter the time Quantum: "<<endl;
    cin>>t_qt;
    for(int i=0;i<n;i++){
        cout<<"Enter the burst time of  P"<<i+1<<endl;
        cin>>bt[i];
        rt[i]=bt[i];
    }

    int t=0;
    bool done;
    while(true){
        done =true;
        for(int i=0;i<n;i++){
            if(rt[i]>0){
                done = false;
                if(rt[i]>t_qt){
                    t+=t_qt;
                    rt[i]-=t_qt;
                }
                else{
                    t+=rt[i];
                    ct[i]=t;
                    tat[i]=(t-at[i]);
                    wt[i]=tat[i]-bt[i];
                    rt[i]=0;
                }
            }
          
        }
          if(done) break;
    }

    cout<<"Process\tBT\tTAT\tWT"<<endl;
    for(int i=0;i<n;i++){
        total_tat+=tat[i];
        total_wt+=wt[i];
        cout<<i+1<<'\t'<<bt[i]<<'\t'<<ct[i]<<'\t'<<wt[i]<<endl;
    }
    atat=(float)total_tat/n;
    awt=(float)total_wt/n;
    cout<<"Average TAT = "<<atat<<endl;
    cout<<"Average WT = "<<awt<<endl;
    return 0;
}


/*

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, b[20], a[20], rt[20] = {0}, i , j, t[20] = {0}, w[20] = {0}, tq;

	int remain,count,time = 0, flag = 0;

	float sat = 0, swt = 0;

	printf("Enter the no. of processes:\n");
	scanf("%d", &n);

	remain = n;

	printf("Enter the at and bt- \n");

	for(i=0;i<n;i++)
	{
		printf("Process %d\n",i);
		scanf("%d %d", &a[i], &b[i]);
		rt[i] = b[i];
	}

	printf("Enter the time quantum:\n");
	scanf("%d" ,&tq);

	for(count = 0; remain!=0;)
	{
		if(rt[count] <= tq && rt[count]>0)
		{
			time += rt[count];
			rt[count] = 0;
			flag = 1;
		}
		else if(rt[count] > 0)
		{
			rt[count] = rt[count] - tq;
			time += tq;
		}

		if(rt[count] == 0 && flag == 1)
		{
			printf("%d\t%d\t%d\n",count,time - a[count], time - a[count] - b[count]);
			remain--;
			sat += time - a[count];
			swt += time - a[count] - b[count];
			flag = 0;
		}

		if(count == n-1)
			count = 0;
		else if(a[count + 1] <= time)
			count++;
		else
			count = 0;
	}

	printf("Avg. tat = %f\n", sat/n);
	printf("Avg. wt = %f\n", swt/n);


	printf("\n");
	return 0;
}

*/