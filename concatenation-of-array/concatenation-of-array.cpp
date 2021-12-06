class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> temp(2*nums.size());
        for(int i = 0;i<nums.size();i++){
            temp[i] = temp[i+nums.size()] = nums[i];
        }
        return temp;
    }
};