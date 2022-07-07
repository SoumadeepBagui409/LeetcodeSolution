// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int ans(int n,int *arr,vector<int> &cache,int idx){
        if(idx>=n || n == 0){
            return 0;
        }
        
        if(cache[idx]!=-1){
            return cache[idx];
        }
        
        int op1,op2;
        op1 = op2 = 0;
        
        op1 = arr[idx] + ans(n,arr,cache,idx+2);
        op2 = ans(n,arr,cache,idx+1);
        
        return cache[idx] = max(op1,op2);
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> cache(n+1,-1);
        return ans(n,arr,cache,0);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends