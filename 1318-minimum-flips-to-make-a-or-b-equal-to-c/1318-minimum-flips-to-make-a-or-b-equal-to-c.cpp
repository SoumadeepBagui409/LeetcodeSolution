class Solution {
public:
    int minFlips(int a, int b, int c) {
        vector<int> arr(32,0);
        vector<int> brr(32,0);
        vector<int> crr(32,0);
        for(int i =31;i>=0;i--){
            arr[i] = (a&(1<<i))==(1<<i);
            brr[i] = (b&(1<<i))==(1<<i);
            crr[i] = (c&(1<<i))==(1<<i);
        }
        // for(int i =0;i<32;i++)cout<<arr[i]<<" ";
        // cout<<"\n";
        // for(int j = 0;j<32;j++)cout<<brr[j]<<" ";
        // cout<<"\n";
        // for(int j = 0;j<32;j++)cout<<crr[j]<<" ";
        // cout<<"\n";
        int cnt = 0;
        for(int i = 0;i<=31;i++){
            if(crr[i]==1){
                if(arr[i]==0 and brr[i]==0)cnt++;
            }
            else if(crr[i]==0){
                if(arr[i]^brr[i]){
                    cnt++;
                }else if(arr[i]&brr[i]){
                    cnt+=2;
                }
            }
        }
        return cnt;
        
    }
};