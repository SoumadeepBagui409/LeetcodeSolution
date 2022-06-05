class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            int j = i;
            bool inside = false;
            while(j<nums.size() and nums[j]-nums[i]<=k){
                j++;
                inside = true;
            }
            if(inside){
                ans++;
            }
            i = j-1;
        }
        return ans;
    }
};