class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
     for(int i =31;i>=0;i--){
         int ones = 0;
         int zeroes = 0;
         for(int j = 0;j<nums.size();j++){
             if(nums[j]&(1<<i))ones++;
             else zeroes++;
         }
         ans+=zeroes*ones;
     }
        return ans;
    }
};