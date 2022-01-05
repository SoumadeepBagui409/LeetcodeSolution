class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<pair<int,int>> chk;
        int n = nums.size();
        for(int i =0;i<n;i++){
            for(int j = i+1 ;j<n;j++){
                if(chk.find({nums[i],nums[j]})!=chk.end()){
                    continue;
                }
                int sum = nums[i]+nums[j];
                
                int fnd = 0-sum;
                int st = j+1;
                int ed = n - 1;
                while(st<=ed){
                    int mid = (st+ed)/2;
                    if(nums[mid]<fnd){
                        st = mid + 1;
                    }else if(fnd==nums[mid]){
                        chk.insert({nums[i],nums[j]});
                        ans.push_back({nums[i],nums[j],nums[mid]});
                        break;
                    }else{
                        ed =  mid - 1;
                    }
                }
            }
        }

        return ans;
    }
};