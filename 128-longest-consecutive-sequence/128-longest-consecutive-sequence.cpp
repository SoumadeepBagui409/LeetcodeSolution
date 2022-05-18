class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> val;
        int cnt  = 0;
        for(int i = 0;i<nums.size();i++){
            val.insert(nums[i]);
        }
        
        for(int i = 0;i<nums.size();i++){
                if(val.find(nums[i]-1)==val.end()){
                    int value = nums[i]+1;
                    int currCnt = 1;
                    while(val.find(value)!=val.end()){
                        currCnt++;
                        value++;
                    }
                    cnt = max(cnt,currCnt);
                }
        }
        return cnt;
    }
};