#include<iostream>
#include<stdio.h>
using namespace std;
class sjf
{      
    public:
        int burst_tm;
        int arv_tm; 
        int wait_tm;
        int temp;
        char pid;

    sjf()
    {
        temp=0;
        //status=0;
    }
};
int main()
{
    int n,sum=0,carry=0;
    float avg_wait_tm=0,avg_around_tm=0;
    cout<<"Enter the no. of processes:\n";
    cin>>n;

    sjf temp;
    sjf *f=new sjf[n];
    for( int i=0;i<n;i++)
    {
        cout<<"Enter the process id:\n";
        cin>>f[i].pid;
        cout<<"Enter the burst timing:\n";
        cin>>f[i].burst_tm;
        cout<<"Enter the arrival timing:\n";
        cin>>f[i].arv_tm;
    
    }

    int k1=0,flag=1;
    while(k1<n)
    {
        if(f[k1].arv_tm==0)
        {
            flag=0;
            break;
        }
        k1++;
    }
    if(flag==1)
    {
        cout<<"enter all values of arival time as no arrival time is 0\n";
        return 1;
    }


    for(int k=0;k<n;k++)
    {
        temp=f[k];
        for(int i=k+1;i<n;i++)
        {
            if(temp.arv_tm>f[i].arv_tm)
            {
                temp=f[i];
                f[i]=f[k];
                f[k]=temp;
            }
            //cout<<"f[0]: "<<f[0].pid<<endl;
        }
    }

    for(int k=0;k<n;k++)
    {
        cout<<"pid: "<<f[k].pid<<endl<<"Burst time: "<<f[k].burst_tm<<endl<<"arrival time: "<<f[k].arv_tm<<endl<<"Waiting time: "<<f[k].wait_tm<<endl;
    }

    cout<<"Entered info is as follows:\n";
    carry=f[0].arv_tm;
    int i=0;
    for(int k=1;k<n;k++)
    {
        if(f[k].arv_tm==carry)
        {
            if(f[i].burst_tm>f[k].burst_tm)
                                                            i=k;
        }
        else
        {
            cout<<"carry break\n";
            break;
        }
    }

    int j,tem=0,k,b;
    do
    {
        j=0;
        if((f[i].arv_tm<=sum)&&(f[i].temp!=1))
        {
            f[i].wait_tm=sum-f[i].arv_tm;
            f[i].temp=1;
            sum+=f[i].burst_tm;
        }
        else
        {
            if(tem==0)
            {
                sum=f[i].arv_tm;
                tem=1;
            }
            f[i].wait_tm=sum-f[i].arv_tm;
            f[i].temp=1;
            sum+=f[i].burst_tm;
        }
        flag=1;
        for(int k=0;k<n;k++)
        {
            if(f[k].arv_tm<=sum)
            {
                //flag=0;
                if(f[k].temp==1)
                    j++;
                else if((f[k].burst_tm<f[i].burst_tm)||(f[i].temp==1))
                {
                    flag=0;
                    i=k;
                }
            }
        }
                        
        if((flag==1)&&(j!=n-1))
        {
            for(b=i;b<n;b++)
            if(!f[b].temp)
            {
                carry=f[b].arv_tm;
                i=b;
                break;
            }
            for(int t=b+1;t<n;t++)
            {
                if(f[t].arv_tm==carry)
                {
                    if(f[t].burst_tm<f[i].burst_tm)
                        i=t;
                }
                else
                break;
            }
        }
}while(j!=n);
                                                                                        
                                    
    for(k=0;k<n;k++)
    {
        cout<<"pid: "<<f[k].pid<<endl<<"Burst time: "<<f[k].burst_tm<<endl<<"arrival time: "<<f[k].arv_tm<<endl<<"Waiting time: "<<f[k].wait_tm<<endl;
        avg_wait_tm+=f[k].wait_tm;
        avg_around_tm+=f[k].wait_tm+f[k].burst_tm;
    }
    avg_around_tm/=n;
    avg_wait_tm/=n;
    cout<<"average turn around time:\n"<<avg_around_tm<<endl<<"average waiting time:\n"<<avg_wait_tm<<endl;

    //cout<<"average turn around time:\n"<<avg_around_tm<<endl<<"average waiting time:\n"<<avg_wait_tm<<endl;
    getchar();
    getchar();
    getchar();
    return 0;
}