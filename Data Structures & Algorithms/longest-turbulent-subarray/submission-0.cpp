class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        //if(n==1) return 1;
        int maxi=1,cnt=1;
        char c='.';
        for(int i=0;i+1<n;i++){
            if(arr[i]<arr[i+1]){
                if(c=='>'){
                    cnt++;
                }else cnt=2;
                c='<';
            }else if(arr[i]>arr[i+1]){
                if(c=='<'){
                    cnt++;
                }else cnt=2;
                c='>';
            }else{
                cnt=1;
                c='.';
            }
            maxi=max(cnt,maxi);
        }
        
        return maxi;
    }
};