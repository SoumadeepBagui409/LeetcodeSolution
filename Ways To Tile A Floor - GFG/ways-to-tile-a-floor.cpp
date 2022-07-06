// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int numberOfWay(long long int N,vector<long long int> &cache){
        if(N==0){
            return 1;
        }
        if(cache[N]!=-1){
            return cache[N];
        }
        int op1,op2;
        op1 = op2 = 0;
        if(N-1>=0){
            op1 = numberOfWay(N-1,cache);
        }
        if(N-2>=0){
            op2 = numberOfWay(N-2,cache);
        }
        
        return cache[N] = (op1+op2)%(1000000007);
    }
    long long numberOfWays(long long N) {
        vector<long long int> cache(N+1,-1);
        return numberOfWay(N,cache); 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}  // } Driver Code Ends