#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    cout << "\n Kernel version is : "; 
    cout << system("cat /proc/sys/kernel/osrelease");

    cout << "\n CPU space: ";
    cout << system("cat /proc/cpuinfo |awk 'NR==3, NR==4{print}' \n");

    cout << "\n Amount of cpu time since system was last booted is : ";
    cout << system("cat /proc/uptime \n");

    cout << "\n The configured memory is : ";
    cout << system("cat /proc/meminfo | awk 'NR == 1 {print $2}' \n");

    cout << "\n Amount of free memory : ";
    cout << system("cat /proc/meminfo | awk 'NR == 2{print $2}' \n");
    
    cout << "\n Amount of used memory is : ";
    cout << system("cat /proc/meminfo | awk '{if (NR==1) a=$2; if(NR==2) b=$2 } END {print a-b}' \n");
    cout << endl;
    return 0;
}