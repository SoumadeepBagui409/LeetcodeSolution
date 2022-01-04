class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for(auto x:nums)cnt+=(x==val);
        int j,n;
        j = nums.size()-1;
        while(j>=0 && nums[j]==val)j--;
        for(int i =0;i<=j;i++){
            if(nums[i]==val){
                for(int k = i+1;k<=j;k++){
                    swap(nums[k],nums[k-1]);
                }
                j--;i--;
            }
        }
        return nums.size()-cnt;
    }
};