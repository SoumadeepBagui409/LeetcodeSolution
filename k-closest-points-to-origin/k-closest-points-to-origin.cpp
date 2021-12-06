class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        int dist1 =a[0]*a[0]+a[1]*a[1];
        int dist2 = b[0]*b[0]+b[1]*b[1];
        //cout<<dist1<<" "<<dist2<<"\n";
        if(dist1<dist2){
            return true;
        }
        return false;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        sort(points.begin(),points.end(),cmp);
        vector<vector<int>> val(k,vector<int>(2));
        for(int i = 0;i<k;i++){
            val[i][0] = points[i][0];
            val[i][1] = points[i][1];
        }
        return val;
    }
        
   
    
};