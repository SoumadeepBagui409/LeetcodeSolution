class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> val1,val2;
        for(auto x:nums1)val1.insert(x);
        for(auto x:nums2)val2.insert(x);
        vector<int> ans;
        for(auto x:val1){
            if(val2.find(x)!=val2.end())ans.push_back(x);
        }
        return ans;
    }
};