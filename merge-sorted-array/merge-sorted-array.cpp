class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
    int st = 0;
    int st1 = 0;
    vector<int> ans;
    while(st<m && st1<n){
        if(num1[st]<num2[st1]){
            ans.push_back(num1[st]);
            st++;
        }else{
            ans.push_back(num2[st1]);
            st1++;
        }
    }
        while(st<m){
            ans.push_back(num1[st]);
            st++;
        }
        
         while(st1<n){
            ans.push_back(num2[st1]);
            st1++;
        }
        for(int i =0;i<num1.size();i++){
            num1[i] = ans[i];
        }
        
    } 
};