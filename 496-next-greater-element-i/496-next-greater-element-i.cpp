class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> val;
     for(int i = 0;i<nums1.size();i++){
         bool found =false;
         int ans = -1;
         for(int j = 0;j<nums2.size();j++){
            if(nums1[i]==nums2[j]){
                found = true;
            }
             
             if(found and nums2[j]>nums1[i]){
                 ans = nums2[j];
                 break;
             }
            
         }
          val.push_back(ans);
     }
        return val;
    }
};