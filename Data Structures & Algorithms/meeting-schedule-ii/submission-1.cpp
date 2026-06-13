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
       /* for(auto  num:nums){
            n=max(n,num.end);
        }
        */
        //vector<int>arr(n+1,0);
        map<int,int>arr;
        for(auto num:nums){
           arr[num.start]+=1;
           arr[num.end]-=1;
        }
        int maxi=0;
        int curr=0;
        for(auto [k,v]:arr){
            curr+=v;
            maxi=max(maxi,curr);
        }
        return maxi; 
    }
};
