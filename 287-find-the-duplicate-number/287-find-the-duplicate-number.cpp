class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> arr(nums.size(),0);
        for(auto x:nums){
            arr[x-1]++;
        }
        int i = 0;
        for(auto x:arr){
            if(x>1){
                return i+1;
            }
            i++;
        }
        return -1;
    }
};