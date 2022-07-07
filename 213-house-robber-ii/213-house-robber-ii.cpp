class Solution {
public:
    int ans(vector<int> &arr,int idx,int end,vector<int>&cache){
        if(idx>=end){
            return 0;
        }
        if(cache[idx]!=-1){
            return cache[idx];
        }
        int op1,op2;
        op1 = arr[idx] + ans(arr,idx+2,end,cache);
        op2 = ans(arr,idx+1,end,cache);
        return cache[idx] = max(op1,op2);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int> cache(nums.size(),-1);
        int ans1 = ans(nums,0,nums.size()-1,cache);
        vector<int> cache1(nums.size()+1,-1);
        int ans2 = ans(nums,1,nums.size(),cache1);
        return max(ans1,ans2);
    }
};