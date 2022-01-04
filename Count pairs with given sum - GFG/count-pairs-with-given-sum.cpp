// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        map<int,int> freq;
        int cnt = 0;
        for(int i = 0;i<n;i++)freq[arr[i]]++;
        for(int i = 0;i<n;i++){
            int snd = k-arr[i];
            if(snd!=arr[i] && freq[snd]!=0){
               cnt+=freq[arr[i]]*freq[snd]; 
            }else if(arr[i]==snd){
                cnt+=freq[arr[i]]*(freq[arr[i]]-1)/2;
            }
            freq[arr[i]] = freq[snd] = 0;
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends