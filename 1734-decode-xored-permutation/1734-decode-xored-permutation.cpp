class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
       int ans = 0;
        int n= encoded.size();
        for(int i = 1;i<=n+1;i++)ans^=i;
        for(int i = encoded.size()-1;i>=0;i-=2){
            ans^=encoded[i];
        }
        vector<int> val;
        val.push_back(ans);
        for(int i = 0;i<n;i++){
            val.push_back(encoded[i]^val[val.size()-1]);
        }
        return val;
        
    }
};
 
    