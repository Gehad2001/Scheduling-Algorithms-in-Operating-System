//Gehad mohammad sabry (G5)
#include<iostream>
using namespace std;

int main()
{
    	 cout<<"      SJF (non preemptive) scheduling     "<<endl<<endl;
  int waiting_time[15],turn_around_time[15];
  float total_waiting_time=0,total_turn_around_time=0;
  int n,i,j,process[10],burst_time[10],temp;
  cout<<"Enter number of processes"<<endl;
  cin>>n;
  cout<<"Enter burst_time of processes"<<endl;
  for(i=0;i<n;i++)
   {
     process[i]=i+1;
     cout<<"Process["<<i+1<<"]: ";
     cin>>burst_time[i];
   }
  for(i=0;i<n-1;i++)
   {
     for(j=0;j<n-i-1;j++)
      {
        if(burst_time[j]>burst_time[j+1])
          {
            temp=burst_time[j];
            burst_time[j]=burst_time[j+1];
            burst_time[j+1]=temp;
            temp=process[j];
            process[j]=process[j+1];
            process[j+1]=temp;
           }
        }
    }
   waiting_time[0]=0;  
   for(i=1;i<n;i++)
    {
      waiting_time[i]=0;
      for(j=0;j<i;j++)
       {
         waiting_time[i]+=burst_time[j];
       }
    }
   for(i=0;i<n;i++)
    {
      turn_around_time[i]=burst_time[i]+waiting_time[i];
      total_waiting_time+=waiting_time[i];
      total_turn_around_time+=turn_around_time[i];
    }
   cout<<"Process\t\tBurst time\t\tWaiting time\t\tTurn around time"<<endl;
   for(i=0;i<n;i++)
   {
    cout<<process[i]<<"\t\t\t"<<burst_time[i]<<"\t\t\t"<<waiting_time[i]
    <<"\t\t\t"<<turn_around_time[i]<<endl;
   }
   cout<<"Average waiting time:"<<total_waiting_time/n<<endl;
   cout<<"Average Turnaround time:"<<total_turn_around_time/n;
   
   return 0;
    
}