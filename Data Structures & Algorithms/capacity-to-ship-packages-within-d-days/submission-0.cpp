class Solution {
public:
    bool fn(int lim,vector<int>&w,int days){
        int sum=0;
        int cnt=1;
        for(int i=0;i<w.size();i++){
            //sum+=w[i];
            if(sum+w[i]>lim){
                sum=w[i];
                cnt++;
            }else sum+=w[i];
        }
        return cnt<=days; 
    }
    int shipWithinDays(vector<int>& w, int days) {
        int s=0,e=0;
        for(int i=0;i<w.size();i++){
            e+=w[i];
            s=max(s,w[i]);
        }
        int res=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(fn(mid,w,days)){
                res=mid;
                e=mid-1;
            }else s=mid+1;
        }
        return res;
    }
};