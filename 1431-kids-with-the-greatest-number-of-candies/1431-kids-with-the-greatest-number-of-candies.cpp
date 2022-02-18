class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        for(int i =0;i<candies.size();i++){
            int temp = candies[i] + extraCandies;
            bool isGreater = true;
            for(int j =0;j<candies.size();j++){
                if(temp<candies[j] and j!=i){
                    ans.push_back(false);
                    isGreater = false;
                    break;
                }
            }
            if(isGreater)ans.push_back(true);
        }
        return ans;
    }
};