class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        for(int i = 1;i<arr.size();i++)arr[i]^=arr[i-1];
        vector<int> ans;
        for(int i = 0;i<q.size();i++){
            if(q[i][0]==0)ans.push_back(arr[q[i][1]]);
            else ans.push_back(arr[q[i][1]]^arr[q[i][0]-1]);
        }
        return ans;
    }
};