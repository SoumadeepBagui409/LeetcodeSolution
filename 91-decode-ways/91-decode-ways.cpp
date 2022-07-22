class Solution {
public:
    int cal(string s,int idx,vector<int> &cache){
        if(s[idx]=='0')return 0;
        if(idx==s.size())return 1;
        if(idx>s.size())return 0;
        if(cache[idx]!=-1)return cache[idx];
        int op1,op2;
        op1 = op2 = 0;
        op1 = cal(s,idx+1,cache);
        if(idx+1<s.size() and (s[idx]-'0')* 10+(s[idx+1]-'0')<=26)
        op2 = cal(s,idx+2,cache);
        return cache[idx] = op1 + op2;
    }
    int numDecodings(string s) {
        vector<int> cache(s.size()+1,-1);
        return cal(s,0,cache);
    }
};