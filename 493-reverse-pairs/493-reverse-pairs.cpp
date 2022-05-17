class Solution {
public:
    void merge(vector<int> &ans,int st,int mid ,int ed){
        int st1 = st;
        int j = mid + 1;
        int k = 0;
        vector<int> val(ed-st+1,0);
        while(st1<=mid and j<=ed){
            if(ans[st1]<ans[j]){
                val[k] = ans[st1];
                st1++;
            }else {val[k] = ans[j];j++;}
            k++;
        }
        while(st1<=mid){
            val[k] = ans[st1];
            st1++;
            k++;
        }
        while(j<=ed){
            val[k] = ans[j];
            j++;
            k++;
        }
        k = 0;
        for(int i = st;i<=ed;i++,k++)ans[i] = val[k];
    }
    int cal(vector<int> &ans,int st,int ed){
        if(st>=ed)return 0;
        int mid = (st+ed)/2;
        int op1 = cal(ans,st,mid);
        int op2 = cal(ans,mid+1,ed);
        int k = mid + 1;
        int val = 0;
        for(int i = st;i<=mid;i++){
            while(k<=ed and (long)ans[i]>(long)2*ans[k]){
                k++;
            }
            val+=(k-mid-1);
        }
        merge(ans,st,mid,ed);
        return op1+op2+val;
    }
    int reversePairs(vector<int>& nums) {
        int ans = cal(nums,0,nums.size()-1);
        return ans;
    }
};