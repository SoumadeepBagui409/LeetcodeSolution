class Solution {
public:
    int singleNumber(vector<int>& num) {
        vector<long long int> nums;
        for(auto x:num)nums.push_back(x);
        vector<int>bits(34,0);
        for(int i = 32;i>=0;i--){
            
            for(int j = 0;j<nums.size();j++){
                if(nums[j]<0)bits[33]++;
                if(nums[j]<0)nums[j]*=-1;
                if(nums[j]&(1LL<<i))bits[i]++;
            }
        }
        //for(int i =0;i<31;i++)cout<<bits[i]<<" ";
        long long int ans = 0;
        long long int cnt = 1;
        for(int i =0;i<33;i++){
            if(bits[i]%3!=0)ans+=cnt;
            cnt = cnt*2;
        }
        if(bits[33]%3!=0)ans*=-1;
        return ans;
    }
};