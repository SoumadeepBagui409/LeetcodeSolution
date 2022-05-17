class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        int st = 0;
        int ed = nums.size()-1;
        vector<int> ans;
        vector<pair<int,int>> val;
        
        for(int i =0;i<nums.size();i++){
            val.push_back(make_pair(nums[i],i));
        }
        
        sort(val.begin(),val.end());
    
        while(st<=ed){
            if(val[st].first+val[ed].first<target){
                st++;
            }else if(val[st].first+val[ed].first>target){
                ed--;
            }else{
                ans.push_back(val[st].second);
                ans.push_back(val[ed].second);
                st++;
                ed--;
                break;
            }
        }
        return ans;
    }
};