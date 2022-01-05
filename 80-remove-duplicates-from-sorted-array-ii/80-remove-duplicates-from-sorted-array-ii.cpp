class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1)return 1;
      int pos = 0;
        int i;
        for( i = 1;i<nums.size();i++){
            int cnt = 1;
            while(i<nums.size() && nums[i]==nums[i-1]){
                cnt++;
                i++;
            }
            if(cnt>=2){
                nums[pos] = nums[i-1];
                pos++;
                nums[pos] = nums[i-1];
                pos++;
            }else if(cnt == 1){
                nums[pos] = nums[i-1];
                pos++;
            }
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            nums[pos] = nums[nums.size()-1];
            pos++;
        }
        return pos;
    }
};