class Solution {
public:
    bool matchStr(map<char,int> &val1,map<char,int> &val2){
        for(auto x:val2){
            if(val1[x.first]<x.second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
      sort(t.begin(),t.end());
        vector<pair<int,char>> checker;
        for(int i = 0;i<s.length();i++){
            if(binary_search(t.begin(),t.end(),s[i])){
                checker.push_back({i,s[i]});
            }
        }
        map<char,int> val1,val2;
        for(auto x:t){
            val2[x]++;
        }
        int initial = -1;
        int value = INT_MAX;
        string str1 = "";
        for(int i =0;i<checker.size();i++){
            if(initial == -1){
                initial = i;
            }
              auto curr = checker[i];
                val1[curr.second]++;
            
                
                while(initial<=i && matchStr(val1,val2)){
                    if(checker[i].first-checker[initial].first+1<value){
                    value = checker[i].first-checker[initial].first+1;
                        str1 = s.substr(checker[initial].first,value);
                }
                   // cout<<checker[initial].first<<" "<<checker[i].first<<" "<<value<<"\n";
                    auto curr = checker[initial];
                    val1[curr.second]--;
                    initial++;
                }
            
        }
        return str1;
        
    }
};