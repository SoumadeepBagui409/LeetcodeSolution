class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words;
        map<string,bool> visited;
        for(auto x:wordList){
            words.insert(x);
            visited[x] = false;
        }
        if(words.find(endWord)==words.end())return 0;
        queue<pair<string,int>> tvl;
        tvl.push({beginWord,0});
        visited[beginWord] = true;
        while(!tvl.empty()){
            auto currWord = tvl.front();
            tvl.pop();
            if(currWord.first==endWord){
                return currWord.second+1;
            }
            string s = currWord.first;
            for(int i = 0;i<s.size();i++){
                for(int j = 0;j<26;j++){
                    s[i] = 'a'+j;
                    if(s!=currWord.first and words.find(s)!=words.end() and !visited[s]){
                        tvl.push({s,currWord.second+1});
                        visited[s] = true;
                    }
                }
                s = currWord.first;
            }
        }
        return 0;
        
    }
};