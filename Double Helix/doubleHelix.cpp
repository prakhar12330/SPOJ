/*
Problem Statement:Two ﬁnite, strictly increasing, integer sequences are given.
Any common integer between the two sequences constitute an intersection point.
Take for example the following two sequences where intersection points are
printed in bold:
First= 3 5 7 9 20 25 30 40 55 56 57 60 62
Second= 1 4 7 11 14 25 44 47 55 57 100
You can ‘walk” over these two sequences in the following way:
You may start at the beginning of any of the two sequences. Now start moving forward.
At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, 
or switching to the other sequence.
The objective is ﬁnding a path that produces the maximum sum of data you walked over.
In the above example, the largest possible sum is 450, 
which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{

while(true)
{
    int n;
    cin>>n;
    if(n==0)break;
    else
    {
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int m;
        cin>>m;
        int b[m];
        for(int j=0;j<m;j++)cin>>b[j];
        int s1=0,s2=0;
        int i=0,j=0;
        int ans=0;
        while(i<n and j<m)
        {
            if(a[i]<b[j])
            {
                s1+=a[i++];
            }
            else if(a[i]>b[j])
            {
               s2+=b[j++];
            }
            else
            {
               ans+=max(s1,s2)+a[i];
               s1=s2=0;
               i++;
               j++;
            }
        }
        while(i<n)
        {
           s1+=a[i++];
        }
        while(j<m)
        {
            s2+=b[j++];
        }
        ans+=max(s1,s2);
        cout<<ans<<endl;
    }
}
return 0;
}