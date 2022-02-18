class Solution {
public:
    int minimumSum(int num) {
        vector<int> arr(4);
        int i =0;
        while(num){
            arr[i] = num%10;
            num/=10;
            i++;
        }
        sort(arr.begin(),arr.end());
        int ans = INT_MAX;
        
    
        for(int i =1;i<pow(2,4)-1;i++){
            int temp = i;
            int j = 0;
            int val = 0;
            while(temp){
                if(temp&1){
                    val = val*10+arr[j];
                }
                temp=temp>>1;
                j++;
            }
            temp = i;
            j = 0;
            int chk =1;
            int val2 = 0;
            while(j<4){
                if((temp&chk)==0){
                    val2 = val2*10+arr[j];
                }
                j++;
                chk = chk<<1;
            }
        ans = min(ans,val+val2);
        }    

        return ans;
    }
};