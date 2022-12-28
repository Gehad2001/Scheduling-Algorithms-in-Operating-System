//Gehad mohammad sabry (G5)
 
#include<iostream> 
using namespace std; 
void fWaitingTime(int processes[], int n, 
			int bt[], int wt[], int quantum) 
{ 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 

	int t = 0; 

	while (1) 
	{ 
		bool done = true; 

		for (int i = 0 ; i < n; i++) 
		{ 
			if (rem_bt[i] > 0) 
			{ 
				done = false; 

				if (rem_bt[i] > quantum) 
				{ 
					t += quantum; 
					rem_bt[i] -= quantum; 
				} 
 
				else
				{ 
					t = t + rem_bt[i]; 
					wt[i] = t - bt[i]; 
					
					rem_bt[i] = 0; 
				} 
			} 
		} 

		if (done == true) 
		break; 
	} 
} 
void fTurnAroundTime(int processes[], int n, 
						int bt[], int wt[], int tat[]) 
{ 

	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 


void findavgTime(int processes[], int n, int bt[], 
									int quantum) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	fWaitingTime(processes, n, bt, wt, quantum); 
	
	fTurnAroundTime(processes, n, bt, wt, tat); 

	// show processes 
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 

	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
} 

int main() 
{ 
	 cout<<"      Round Robin scheduling     "<<endl<<endl;
    int * processes ;
    cout<<"Enter the numbers of processes : ";
    int n =0;
    cin >> n;
      cout<<"Enter the id's of processes : "<<endl;
    processes = new int[n]; 
   for(int i = 0; i < n; i++){
           cin>>processes[i];
   }

	int * burst_time ;
    cout<<"Enter the burst_time of processes : "<<endl;
  
   for(int i = 0; i < n; i++){
           cin>>burst_time[i];
   }

	int quantum ; 
	cout<<"enter Time quantum"<<endl;
	cin>>quantum;
	findavgTime(processes, n, burst_time, quantum); 
	return 0; 
} 