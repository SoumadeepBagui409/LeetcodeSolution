class Solution {
public:
    long long getDescentPeriods(vector<int>& arr) {
        long long int length = 0;
        int prev = 0;
        for(int i = 1;i<arr.size();i++){
            
             if(arr[prev]-arr[i]!=1){
                prev++;
            }else if(arr[prev]-arr[i]==1){
                 int j = prev;
                while(i<arr.size() && arr[j]-arr[i]==1){
                    j++;
                    i++;
                }
                 //cout<<i<<" "<<prev<<"\n";
                long long int diff = i-prev;
                length+=diff*(diff-1)/2;
                 prev = j+1;
                 
            }
        }
        //cout<<"\n";
        return length+arr.size();
    }
};