class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x = nums.size()-1;
        while(x!=0 && nums[x]<=nums[x-1]){
            x--;
        }
        if(x-1>=0){
            for(int y=nums.size()-1;y>=x;y--){
                if(nums[y]>nums[x-1]){
                    swap(nums[y],nums[x-1]);
                    break;
                }
            }
            
        }
        reverse(nums.begin()+x,nums.end());
    
    }
};