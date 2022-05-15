class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int edPnt = m;
        int st1 = 0,st2= 0;
        while(st1<nums1.size() and st2<n){
            if(st1>=edPnt and nums1[st1]==0){
                nums1[st1] = nums2[st2];
                st2++;
            }else if(nums1[st1]>nums2[st2]){
                int edPnt1 = edPnt;
                while(edPnt1>st1){
                    swap(nums1[edPnt1],nums1[edPnt1-1]);
                    edPnt1--;
                }
                nums1[st1] = nums2[st2];
                st2++;
                edPnt++;
            }
            st1++;
        }
        }
};