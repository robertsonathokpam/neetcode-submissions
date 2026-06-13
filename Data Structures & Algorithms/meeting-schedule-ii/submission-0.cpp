/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& nums) {
        int n=0;
        for(auto  num:nums){
            n=max(n,num.end);
        }
        vector<int>arr(n+1,0);
        for(auto num:nums){
           arr[num.start]+=1;
           arr[num.end]-=1;
        }
        int maxi=0;

        for(int i=1;i<=n;i++){
            arr[i]+=arr[i-1];
            maxi=max(maxi,arr[i]);
        }

        return maxi; 
    }
};
