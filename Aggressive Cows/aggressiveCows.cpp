/*

 Problem Statement : There is a new barn with N stalls and C(2<=C<=N) cows.The stalls are located
 on a straight line at positions x1,…., xN(0 <= xi <= 1, 000, 000, 000).
 We want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible.
 What is the largest minimum distance ?

*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
bool ispossible(int s[],int n,int cows,int minDist)
{
    int cowslstpsn=s[0];
    int cntcows=1;
    for(int i=1;i<n;i++)
    {
        if(s[i]-cowslstpsn>=minDist)
        {
            cntcows++;
            cowslstpsn=s[i];
        }
    }
    if (cntcows >= cows)
        return true;
    return false;
}
int main()
{
    int numStalls=5; //number of stalls in the barns
    int cows=3;
    int stalls[]={1,2,4,8,9};
    sort(stalls,stalls+numStalls);
    int maxrange = stalls[numStalls] - stalls[0]; // The maximum value of the range //
    int minrange=stalls[0];//The minimum value of the range //
    int lo=minrange;
    int hi=maxrange;
    while(lo<=hi)
    {
        int mid=lo+hi/2;
        if(ispossible(stalls,numStalls,cows,mid))
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    cout<<"The largest minimum distance is:"<<hi<<endl;

}