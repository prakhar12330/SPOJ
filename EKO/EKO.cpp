/*
Problem Statement:Lumberjack Mirko needs to chop down M metres of wood.
It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire.
However, Mirko is only allowed to cut a single row of trees.
Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that
height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact).
Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of
20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be
15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the
fourth tree (7 metres of wood in total).
Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary.
That‟s why he wants to set his sawblade as high as possible.
Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood
*/
#include <bits/stdc++.h>

using namespace std;

bool ifPossible(long long int tree[],int N,int M,long long int barrier)
{
   long long woodObtained=0;
   for(int i=0;i<N;i++)
   {
       if(tree[i]>=barrier)
       {
       woodObtained+=(tree[i]-barrier);
       }
   }
   return woodObtained>=M;
}
int main()
{
    // Input N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).
    cout << "Enter The value Of N (the number of trees, 1 <= N <= 1 000 000) and M (Mirkos required wood amount, 1<= M <= 2 000 000 000) " << endl;
    long long int N,M;
    cin>>N>>M;
    // Input N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres)
    cout << "Enter N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres)"<< endl;
    long long int tree[N];
    for(int i=0;i<N;i++)
    {
       cin>>tree[i];
    }
    long long int lo=tree[0];
    long long int hi =tree[N-1];
    for(int j=0;j<N;j++)
    {
        lo=min(lo,tree[j]);
        hi=max(hi,tree[j]);
    }
    long long int res=-1;
    while(lo<=hi)
    {
        long long int mid=(lo+hi)/2;
        if(ifPossible(tree,N,M,mid))
        {
            res=mid;
            lo=mid+1;
        }
        else
        {
           hi=mid-1;
        }
    }
    cout<<res<<endl;
    
    return 0;
}