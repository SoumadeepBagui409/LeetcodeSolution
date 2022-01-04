// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>arr, int k){
        map<int,int> freq;
        int cnt = 0;
        sort(arr.begin(),arr.end());
        for(int i =0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        set<pair<int,int>> val;
        for(int i = 0;i<arr.size();i++){
            if(k>0 && freq[arr[i]+k]>0 && val.find({arr[i],arr[i]+k})==val.end()){
                
                val.insert({arr[i],arr[i]+k});
            }else if(k==0 && freq[arr[i]+k]>1){
                val.insert({arr[i],arr[i]+k});
            }
            }
            // for(auto x:val){
            //     cout<<x.first<<" "<<x.second<<"\n";
            // }
        return val.size();
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends