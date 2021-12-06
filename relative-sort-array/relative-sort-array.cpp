class Solution {
    map<int,int> pos;
    static int breakPoint;
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[1]>a[2] && b[1]>b[2]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
        
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int i = 1;
        //breakPoint = arr2.size();
        for(auto x:arr2){
            pos[x] = i;
            i++;
        }
        vector<vector<int>> ans; 
        for(auto x:arr1){
            if(pos[x]==0){
                pos[x] = i++;
            }
            vector<int> all;
            all.push_back(x);
            all.push_back(pos[x]);
            all.push_back(arr2.size());
            ans.push_back(all);
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int> val;
        for(auto x:ans){
            val.push_back(x[0]);
            
        }
        return val;
    }
};