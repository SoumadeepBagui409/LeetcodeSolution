class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> ans;
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                int st = j+1;
                int ed = n - 1;
                int need = target - nums[i] - nums[j];
                while(st<=ed){
                    int mid = (st + ed)/2;
                    if(nums[mid]<need){
                        st = mid + 1;
                    }else{
                        ed = mid - 1;
                    }
                }   
                if(st>j && st<n){
                    ans.push_back({abs(target - (nums[i]+nums[j]+nums[st])),nums[i]+nums[j]+nums[st]});
                    //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[st]<<"\n";
                }
                if(ed>j && ed<n){
                    ans.push_back({abs(target - (nums[i]+nums[j]+nums[ed])),nums[i]+nums[j]+nums[ed]});
                     //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[ed]<<"\n";
                }
            }
        }
        sort(ans.begin(),ans.end());
        // for(auto x:ans){
        //     cout<<x.first<<" "<<x.second<<"\n";
        // }
        
        
        return ans[0].second;
        
    }
};