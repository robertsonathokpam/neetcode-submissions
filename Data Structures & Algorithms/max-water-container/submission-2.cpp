class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int l=0,r=n-1;
        int area=0;
        while(l<r){
            int k=min(h[l],h[r])*(r-l);
            area=max(area,k);
            if(h[l]>h[r]){
                r--;
            }else l++;
        }
        return area;
    }
};
