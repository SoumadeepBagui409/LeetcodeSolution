class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int cnt = 1;
        for(int i =1;i<nums.size();i++){
            if(val!=nums[i]){
                cnt--;
                if(cnt==0){ val = nums[i];cnt = 1;}
            }else cnt++;
        }
         return val;
    }
   
};