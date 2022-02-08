/*
Problem Statement:IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
The subcommittee members are asked to go to food connection and get P(P<=1000) pratas packed for the function. 
The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8). A cook with a rank R can cook 1 prata in the 
first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on(he can only cook a complete prata)
( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the
next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have
enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program 
to help him out.
*/
#include<bits/stdc++.h>


using namespace std;

bool ifPossible(int prt,int n,int a[],int barrier)
{
    int parta=0;
    int time=0;
    for(int i=0;i<n;i++)
    {
        time=a[i];
        int j=2;
        while(time<=barrier)
        {
            parta++;
            time+=(a[i]*j);
            j++;
        }
        if(parta>=prt)return true;
    }
    return false;
}


int main()
{
    // first line tells the number of test cases
    int t;
    cout<<"Enter the number of test cases:"<<endl;
    cin>>t;
    while(t--)
    {
        int prt;
        cin>>prt;
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int lo=0;
        int hi=1e8;
        int res=0;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(ifPossible(prt,n,a,mid))
            {
                 res=mid;
                 hi=mid-1;
            }
            else
            {
                 lo=mid+1;
            }
        }
        cout<<res<<endl;
    }

}