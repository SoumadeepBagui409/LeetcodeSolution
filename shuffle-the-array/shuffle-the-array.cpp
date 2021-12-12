class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr(2*n);
        int start = 0;
        for(int i = 0;i<n;i++){
            arr[start]=nums[i];
            arr[start+1] = nums[i+n];
            start+=2;
        }
        return arr;
    }
};