// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    long long numberOfSubsequences(int N, long long A[]){
        int cnt = 0;
        for(int i =0;i<N;i++){
            if(1.0*(int(log2(A[i]))+1) == log2(A[i])+1){
                cnt++;
            }
        }
        return pow(2,cnt)-1;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        long long A[N];
        for(int i=0;i<N;++i){
            cin >> A[i];
        }
        Solution ob;
        cout << ob.numberOfSubsequences(N,A) << endl;
    }
    return 0; 
}   // } Driver Code Ends