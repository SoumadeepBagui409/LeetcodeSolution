// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       vector<int> freq(n+1,0);
        int *a = new int[2];
        for(int i = 0;i<n;i++)freq[arr[i]]++;
        int cnt = 1;
        while(cnt<=n){
            if(freq[cnt]!=0 and freq[cnt]%2==0)a[0] = cnt;
            else if(freq[cnt]==0)a[1] = cnt;
            cnt++;
        }
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends