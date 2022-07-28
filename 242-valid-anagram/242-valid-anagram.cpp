class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        map<char,int> sFreq,tFreq;
        for(auto x:s){
            sFreq[x]++;
        }
        for(auto x:t){
            tFreq[x]++;
        }
        for(auto x:sFreq){
            if(tFreq[x.first]!=x.second){
                return false;
            }
        }
        return true;
    }
};