class Solution {
public:

    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> sortit;
        for(auto x : nums1){
            sortit.insert(x);
        }
        vector<int> ans(nums1.size());
        
        for(int i=0;i<nums1.size();i++){
            auto it = sortit.upper_bound(nums2[i]);
            if(it==sortit.end()){
                it = sortit.begin();
            }
            ans[i] = *it;
            sortit.erase(it);
        }
        return ans;
    }
};