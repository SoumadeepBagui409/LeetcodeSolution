class Solution {
public:
    static bool cmp(int a,int b){
        return abs(a)<abs(b);
    }
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        for(int i =0;i<nums.size();i++){
            nums[i]*=nums[i]; 
        }
        return nums;
    }
};