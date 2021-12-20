class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(auto x:words){
            bool pos =true;
            int s = 0;
            int e = x.size()-1;
            while(s<e){
                if(x[s]!=x[e]){
                    pos =false;
                    break;
                }
                s++;
                e--;
            }
            if(pos)return x;
        }
        
        return "";
    }
};