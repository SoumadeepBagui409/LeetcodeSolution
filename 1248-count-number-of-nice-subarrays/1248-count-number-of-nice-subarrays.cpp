class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> scanOdd;
        
        for(int i =0;i<nums.size();i++){
            if(nums[i]&1)scanOdd.push_back(i);
        }
        int ans = 0;
        for(int i = 0;i<scanOdd.size();i++){
            int cal;
            
            if(i==0){
                cal = scanOdd[i] + 1;
            }else cal = scanOdd[i]-scanOdd[i-1];
            
            if(i+k-1<=scanOdd.size()-1){
                if(i+k-1==scanOdd.size()-1){
                    cal*=(nums.size()-scanOdd[i+k-1]);
                }else cal*=(scanOdd[i+k]-scanOdd[i+k-1]);
                ans+=cal;
            }
        }
        return ans;
    }
};