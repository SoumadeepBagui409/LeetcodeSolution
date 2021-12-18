class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = n-1;i>=2;i--){
            if(nums[i]<nums[i-1]+nums[i-2]){
                return nums[i]+nums[i-1]+nums[i-2];
            }
        }
        return 0;
    }
};