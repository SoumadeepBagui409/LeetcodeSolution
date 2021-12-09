class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int cnt = 0;
        for(auto x:operations){
            if(x[1]=='+')cnt++;
            else cnt--;
        }
        return cnt;
    }
};