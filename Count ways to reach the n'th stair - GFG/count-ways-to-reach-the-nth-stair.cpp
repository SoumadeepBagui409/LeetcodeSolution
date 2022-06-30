// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        vector<int> cache(n+1,0);
        cache[0] = 1;
        cache[1] = 1;
        
        for(int i = 2; i<=n ; i++){
            if(i-1>=0)cache[i]=(cache[i]+cache[i-1])%(1000000007);
            if(i-2>=0){
                cache[i]=(cache[i]+cache[i-2])%1000000007;
            }
        }        
        return cache[n];
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