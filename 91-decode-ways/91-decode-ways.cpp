class Solution {
public:
        int numDecodings(string s) {
        vector<int> cache(s.size(),0);
            if(s[0]!='0')
            cache[0] = 1;
            if(s.size()>1){
                if(s[1]=='0'){
                    if( (s[0]-'0')*10+(s[1]-'0')<=26 and s[0]!='0'){
                    cache[1]++;
                }
                }
                else{
                    cache[1]+=cache[0];
                    if(s[0]!='0' and (s[0]-'0')*10+(s[1]-'0')<=26)cache[1]++;
                }
            }
        for(int i = 2; i<s.size();i++){
            if(s[i] == '0'){
                if(i-2>=0 and (s[i-1]-'0')*10+(s[i]-'0')<=26 and s[i-1]!='0'){
                    cache[i] += cache[i-2];
                }
            }else{
                cache[i]+=cache[i-1];
                if(i-2>=0 and (s[i-1]-'0')*10+(s[i]-'0')<=26 and s[i-1]!='0'){
                    cache[i]+=cache[i-2];
                }
            }
        }
        return cache[s.size()-1];
    }
};