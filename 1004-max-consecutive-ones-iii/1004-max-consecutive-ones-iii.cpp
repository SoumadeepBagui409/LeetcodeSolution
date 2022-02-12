class Solution {
public:
    int max(int x,int y){
        return (x>y)?x:y;
    }
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0;
        queue<int> val;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){

                val.push(nums[i]);
            if(nums[i]==0)
                cnt++;
            while(cnt>k and val.size()>0){
                int temp = val.front();
                if(temp==0)cnt--;
                val.pop();
            }
            ans = max(ans,val.size());
        }
        ans = max(ans,val.size());
        return ans;
    }
};