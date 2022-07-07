// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int ans(long long int n,vector<int> &arr,int i,vector<vector<int>>&cache){
           
           if(i>2 || n<0)return 0;
           
           if(n==0)return 1;
           
            if(cache[n][i]!=-1){
                return cache[n][i];
            }
            
          long long int op1,op2;
          op1 = ans(n-arr[i],arr,i,cache);
          op2 = ans(n,arr,i+1,cache);
          return cache[n][i] = op1 + op2;
}
long long int count(long long int n)
{
    vector<int> arr = {3,5,10};
    vector<vector<int>> cache(n+1,vector<int>(3,-1));
        return ans(n,arr,0,cache);
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends