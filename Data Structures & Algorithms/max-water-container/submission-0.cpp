class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int area=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               area=max(area, min(h[i],h[j])*(j-i));
            }
        }
        return area;
    }
};
