
class Solution {
    vector<vector<string>> val;
public:
    bool isPalindrome(string s){
        int st = 0;
        int ed = s.size()-1;
        while(st<=ed){
            if(s[st]!=s[ed]){
                return false;
            }
            st++;
            ed--;
        }
        return true;
      }
    void generate(vector<string> &sub,string s,int idx){
        
        if(idx==s.size()){
            val.push_back(sub);
            return;
        }
        
        for(int i = idx;i<s.size();i++){
            if(isPalindrome(s.substr(idx,i-idx+1)))
            {
                sub.push_back(s.substr(idx,i-idx+1));
                generate(sub,s,i+1);
                sub.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> sub;
        generate(sub,s,0);
        return val;
    }
};