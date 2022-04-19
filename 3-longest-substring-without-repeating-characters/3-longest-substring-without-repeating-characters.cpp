class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            map<char,int> checker;
            int j;
            for( j = i;j<s.size();j++){
                if(checker.find(s[j])!=checker.end()){
                    ans = max(ans,j-i);
                    break;
                }else checker[s[j]]++;
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};