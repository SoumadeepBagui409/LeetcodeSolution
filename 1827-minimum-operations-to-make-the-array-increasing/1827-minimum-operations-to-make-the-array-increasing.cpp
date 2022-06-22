class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 1;i<nums.size();i++){
            int diff = nums[i] - nums[i-1];
            if(diff<=0){
                diff = -1*diff;
                diff++;
                ans+=diff;
                nums[i]+=diff;
            }
        }
        return ans;
    }
};