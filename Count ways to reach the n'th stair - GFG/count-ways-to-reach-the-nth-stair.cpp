// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int optimalPath(int n,vector<int> &cache){
        if(n==0){
            return 1;
        }
        if(cache[n]!=-1){
            return cache[n];
        }
        int op1 , op2;
         op1 = op2 = 0;
        if(n-1>=0){
            op1 = optimalPath(n-1,cache);
        }
        if(n-2>=0){
            op2 = optimalPath(n-2,cache);
        }
        return cache[n] = (op1 + op2)%1000000007 ;
    }
    int countWays(int n)
    {
        vector<int> cache(n+1,-1);
        return optimalPath(n,cache);
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends