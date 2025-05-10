#include <iostream>
using namespace std;

class fcfs {
    public:
    int burst_tm, arv_tm, wait_tm;
    char pid;
};
int main() {
    int n, carry;
    cout << "Enter the no. of proccesses: \n";cin>>n;
    fcfs temp;
    fcfs *f = new fcfs[n];
    for(int i=0; i<n; i++) {
        cout << "Enter the process id: ";cin>>f[i].pid;
        cout << "Enter the arrival time: ";cin>>f[i].arv_tm;
        cout << "Enter the burst time: ";cin>>f[i].burst_tm;
        system("clear");
    }

    int k = 0;
    int flag = 1;

    while(k!=0) {
        if(f[k].arv_tm == 0) {
            flag = 0;
            break;
        }
        k++;
    }
    if(!flag) {
        cout << "Enter all values of arrival time as no arrival time is 0\n";
        return 1;
    }
    for(k=0; k<n; k++) {
        temp = f[k];
        for(int i=k+1; i<n; i++) {
            if(temp.arv_tm > f[i].arv_tm) {
                temp = f[i];
                f[i] = f[k];
                f[k] = temp;
            }
        }
    }


    cout << "Entered info as follow: \n";
    int avg_wait_tm = 0;
    int avg_around_tm = 0;
    int sum = 0;
    
    for (k=0; k<n; k++) {
        f[k].wait_tm = sum - f[k].arv_tm;
        if(f[k].wait_tm < 0) {
            f[k].wait_tm = 0;
        }
        sum += f[k].burst_tm;
        avg_wait_tm += f[k].wait_tm;
        avg_around_tm += f[k].wait_tm + f[k].burst_tm;
    }

    avg_around_tm /= n;
    avg_wait_tm /= n;
    
    cout << "Process\t Arrival Time\t Burst Time\t Wait Time" << endl;
    for(k=0; k<n; k++){
        cout << f[k].pid << "\t\t" << f[k].arv_tm << "\t\t" << f[k].burst_tm << "\t\t" << f[k].wait_tm << endl; 
    }
    cout << "Average Turn Around Time: " << avg_around_tm << endl;
    cout << "Average Waiting Time: " << avg_wait_tm << endl;
    return 0;
}
