class Solution {
public:
    int fn(int rate,vector<int>& p){
        int time=0;
        for(int i=0;i<p.size();i++){
            time+=(rate+p[i]-1)/rate;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        int s=1,e=*max_element(p.begin(),p.end());
        int res=0;
        while(s<=e){
            int mid=(s+e)>>1;
            if(fn(mid,p)<=h){
                res=mid;
                e=mid-1;
            }else s=mid+1;
        }
        return res;
    }
};
