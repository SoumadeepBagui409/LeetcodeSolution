class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
   sort(num.begin(),num.end());
        int n = num.size();
        vector<vector<int>> ans;
        for(int i= 0;i<n;i++){
            for(int j = i+1;j<n;j++){
               int st = j+1;
                int ed = n-1;
                int sum = target - num[i] - num[j];
                while(st<ed){
                    if(num[st]+num[ed]<sum){
                        st++;
                    }else if(num[st]+num[ed] == sum){
                        ans.push_back({num[i],num[j],num[st],num[ed]});
                        int upto = num[st];
                        while(st<ed && num[st]==upto)st++;
                        upto = num[ed];
                        while(st<ed && num[ed]==upto)ed--;
                        
                    }else{
                        ed--;
                    }
                }
            }
        }
            set<vector<int>> val;
            for(auto x:ans){
                val.insert(x);
            }
            ans.clear();
            for(auto x:val){
                ans.push_back(x);
            }
        
        return ans;
        
    }
};