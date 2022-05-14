class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort( intervals.begin(), intervals.end(),cmp);
        vector<vector<int>> value;
        int st = intervals[0][0];
        int ed = intervals[0][1];
        for(int i = 0;i<intervals.size();i++){
            if(intervals[i][0]<=ed){
                ed = max(ed,intervals[i][1]);
                st = min(st,intervals[i][0]);
                continue;
            }
            
            vector<int> ans;
            ans.push_back(st);
            ans.push_back(ed);
            value.push_back(ans);
            st = intervals[i][0];
            ed = intervals[i][1];
            
            
        }
            vector<int> ans;
            ans.push_back(st);
            ans.push_back(ed);
            value.push_back(ans);
            return value;
    }
};