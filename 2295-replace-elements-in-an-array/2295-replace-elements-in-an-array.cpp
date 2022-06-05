class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int,int> ValPairIdx;
        for(int i = 0;i<nums.size();i++){
            ValPairIdx[nums[i]] = i;
        }
        for(auto x:operations){
            int elementInNums = x[0];
            int addNewElement = x[1];
            int indexOfElement = ValPairIdx[elementInNums];
            nums[indexOfElement] = addNewElement;
            ValPairIdx.erase(elementInNums);
            ValPairIdx[addNewElement] = indexOfElement;
        }
        return nums;
    }
};