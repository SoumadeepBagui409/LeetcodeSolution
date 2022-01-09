class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> freq;
        int cnt = 0;
        int prev = 0;
        for(int i =0;i<s.size();i++){
            if(freq[s[i]]>0){
                
                while(prev<i && s[prev]!=s[i])
                {
                    
                    freq[s[prev]]--;
                    prev++;
                }
                freq[s[prev]]--;
                prev++;
            }
            freq[s[i]]++;
            cnt = max(cnt,i-prev+1);
        }
        return cnt;
    }
};