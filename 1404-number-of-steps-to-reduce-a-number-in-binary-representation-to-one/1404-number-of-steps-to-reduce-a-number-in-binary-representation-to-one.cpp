class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        while(s.size()!=1){
            //cout<<s<<" ";
            if(s[s.size()-1]=='0'){
                s.pop_back();
                cnt++;
            }else{
                cnt++;
                bool carry = true;
                for(int i = 0;i<s.size();i++){
                    if(s[s.size()-i-1]=='1'){
                        s[s.size()-i-1] = '0';
                    }else{
                        s[s.size()-i-1] = '1';
                        carry = false;
                        break;
                    }
                }
                if(carry){
                    reverse(s.begin(),s.end());
                    s+='1';
                    reverse(s.begin(),s.end());
                }
            }
        }
        return cnt;
    }
};