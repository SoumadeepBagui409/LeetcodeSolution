class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        while(i<nums.size()){
            if(nums[i]==0)i++;
            else break;
        }
        while(j>=0){
            if(nums[j]==2)j--;
            else break;
        }
        for(int k = i; k<=j and i<j; k++){
            if(nums[k]==0){
                swap(nums[k], nums[i]);
                i++;
            }else if(nums[k]==2){
                swap(nums[k],nums[j]);
                j--;
                k--;
            }
        }
    }
};