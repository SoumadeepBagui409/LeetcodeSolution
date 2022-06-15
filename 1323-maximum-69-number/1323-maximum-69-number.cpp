class Solution {
public:
    int maximum69Number (int num) {
        string g = to_string(num);
        for(int i = 0; i<g.size();i++){
            if(g[i]=='6'){ g[i]='9';break;}
        }
        int ans = 0;
        for(int i = 0; i < g.size(); i++){
            ans = ans *10 + (g[i]-'0');
        }
        return ans;
    }
};