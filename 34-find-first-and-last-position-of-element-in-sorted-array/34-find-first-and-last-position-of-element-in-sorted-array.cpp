class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int str = -1;
        int st = 0;
        int ed = nums.size()-1;
        while(st<=ed){
            int mid = (st+ed)/2;
            if( nums[mid]>=target)ed = mid - 1;
            else st = mid + 1;
        }
        if(st<nums.size() and nums[st]==target)str = st;
        st = 0;
        ed =  nums.size() - 1;
        while(st<=ed){
            int mid = (st+ed)/2;
            if( nums[mid]>target)ed = mid - 1;
            else st = mid + 1;
        }
        int end = -1;
        if(ed>=0 and nums[ed]==target)end = ed;
        vector<int> val;
        val.push_back(str);
        val.push_back(end);
        return val;
    }
};