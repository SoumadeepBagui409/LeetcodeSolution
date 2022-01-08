class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int cnt = 0;
        for(auto x:sentences){
            int temp = 0;
            for(auto y : x){
                if(y==' '){
                 temp++;   
                }
            }
            temp++;
            cnt = max(cnt,temp);
        }
        return cnt;
    }
    
};