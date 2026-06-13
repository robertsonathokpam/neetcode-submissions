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
    bool canAttendMeetings(vector<Interval>& nums) {
         sort(nums.begin(),nums.end(),[](auto& x,auto&y){
             return x.start<y.start;
             if(x.start==y.start){
                return x.end>y.end;
             } 
         });

         for(int i=1;i<nums.size();i++){
            if(nums[i-1].end>nums[i].start){
                return false;
            }
         }
         return true;
    }
};
