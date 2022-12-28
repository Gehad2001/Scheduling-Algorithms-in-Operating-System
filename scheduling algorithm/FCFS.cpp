//Gehad mohammad sabry (G5)

#include<iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;
 
    // waiting time
    for (int i = 0; i < n ; i++)
    {
        wt[i] =  bt[i-1] + wt[i-1];
    }
}

void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
    // turnaround time 
    for (int i = 0; i < n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
 

void findAverageTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt);
 
    findTurnAroundTime(processes, n, bt, wt, tat);
 
    // show processes 
    cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
 
    // calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turnaround time = "<< (float)total_tat / (float)n;
}
 

int main()
{
    cout<<"      FCFS scheduling    "<<endl<<endl;
    int * processes ;
    cout<<"Enter the numbers of processes : ";
    int n =0;
    cin >> n;
      cout<<"Enter the id of processes : "<<endl;
    processes = new int[n]; 
   for(int i = 0; i < n; i++){
           cin>>processes[i];
   }
    int * burst_time ;
    cout<<"Enter the burst_time of processes : "<<endl;
  
   for(int i = 0; i < n; i++){
           cin>>burst_time[i];
   }
 
    findAverageTime(processes, n,  burst_time);
    
    return 0;
}