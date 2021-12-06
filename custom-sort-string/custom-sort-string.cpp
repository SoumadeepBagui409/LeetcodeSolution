class Solution {
 int pos[26];
public:
    Solution(){
        for(int i = 0;i<26;i++)pos[i] = 0;
    }
    static bool cmp(pair<char,int> a,pair<char,int>b){
      return a.second<b.second;
    }
    string customSortString(string order, string s) {
        int i = 1;
        vector<pair<char,int>> val;
        for(auto x:order){
            pos[x-'a'] = i;
            i++;
        }
        
        for(int j = 0; j<s.size();j++){
            if(pos[s[j]-'a']==0){
                val.push_back({s[j],i});
                i++;
            }else{
                val.push_back({s[j],pos[s[j]-'a']});
            }
        }
        
        sort(val.begin(),val.end(),cmp);
         s = "";
        for(auto x:val){
            s+=x.first;
        }
        return s;
    }
};