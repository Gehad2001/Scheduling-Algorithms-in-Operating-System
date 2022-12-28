//Gehad mohammad sabry (G5)
#include<iostream>
using namespace std;
int main()
{
    	 cout<<"      SRTF (preemptive) scheduling     "<<endl<<endl;
    int a[10],b[10],x[10];
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;

    cout<<"Enter the number of Processes: "<<endl; 
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Enter arrival time of process"<<"["<<i+1<<"]:";  
        cin>>a[i];
    }
    cout<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"Enter burst_time of process "<<"["<<i+1<<"]:"; 
        cin>>b[i];
    }
    for(i=0; i<n; i++)
        x[i]=b[i];

    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" 
    <<"\t"<<"turnaround-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"Average waiting time ="<<avg/n<<endl;
    cout<<"Average Turnaround time ="<<tt/n<<endl;
}