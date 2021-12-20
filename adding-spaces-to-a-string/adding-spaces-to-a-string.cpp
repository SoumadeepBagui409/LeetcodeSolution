class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        sort(spaces.begin(),spaces.end());
        int i = 0;
        string s1 ="";
        int j = 0;
        for(auto x:s){
            if(i<spaces.size() && spaces[i]==j){
                s1+=" ";
                i++;
            }
            s1+=x;
            j++;
        }
        return s1;
        
    }
};