class Solution {
public:
    static bool cmp(int a,int b){
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string s = "";
        for(auto x:nums){
            s+=to_string(x);
        }
        int i = 0;
        while(i<s.size() && s[i]=='0')i++;
        
        if(i==0)return s;
        else return s.substr(i-1);
    }
};