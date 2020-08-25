#include<bits/stdc++.h> 
using namespace std; 
struct Process 
{ 
// course code
   int ccode;
// class duration
   int duration; 
//priority
	int priority; 
//prefered arrival time
   int arrival_time; 
};


// sort the processes based on arrival time
bool sortProcesses(Process a, Process b)
{
	return (a.arrival_time < b.arrival_time);

}

// sort the processes based on priority
bool sortProcesses2(Process a, Process b) 
{ 
    return (a.priority < b.priority); 
} 
  
// Function for finding the waiting time  
void findWaitingTime(Process proc[], int n, 
                     int wt[]) 
{ 
    // waiting time for first process is 0 
    wt[0] = 0; 
  
    // calculating waiting time 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  proc[i-1].duration + wt[i-1] ; 
} 
  
// Function for calculating turnaround time 
void findTurnAroundTime( Process proc[], int n, 
                         int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding  bt[i] + wt[i] 
    for (int  i = 0; i < n ; i++) 
        tat[i] = proc[i].duration + wt[i]; 
} 
  
//Function for calculating average time 
void findavgTime(Process proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    //Function for finding waiting time of all processes 
    findWaitingTime(proc, n, wt); 
  
    //Function to find turn around time for all processes 
    findTurnAroundTime(proc, n, wt, tat); 
  
    //Display processes along with all details 
    cout << "\nProcesses  "<< " duration  "
         << " Waiting time  " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn 
    // around time 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << proc[i].ccode << "\t\t"
             << proc[i].duration << "\t    " << wt[i] 
             << "\t\t  " << tat[i] <<endl; 
    } 
  
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
} 
  
void priorityScheduling(Process proc[], int n) 
{ 
    // Sort processes by priority 
    sort(proc, proc + n, sortProcesses); 
  
    findavgTime(proc, n); 
} 
  
// Driver code 
int main() 
{ 
    Process proc[] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}};
    int n = sizeof proc / sizeof proc[0]; 
    priorityScheduling(proc, n); 
    return 0; 
}

