class Solution {
public:
    int atMostk(vector<int> nums,int k){
        if(k==0)
            return 0;
        map<int,int> tvl;
        int ans = 0;
        int left = 0;
        for(int i = 0;i<nums.size();i++){
            tvl[nums[i]]++;
            
            while(left<i and tvl.size()>k){
                tvl[nums[left]]--;
                if(tvl[nums[left]]==0){
                    tvl.erase(nums[left]);
                }
                left++;
            }
            ans+=i-left+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostk(nums,k)-atMostk(nums,k-1);
    }
};