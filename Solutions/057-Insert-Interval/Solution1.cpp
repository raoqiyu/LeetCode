/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        vector<Interval> ret;
        if(n == 0){
            ret.push_back(newInterval);
            return ret;
        }
        auto i = intervals.begin();
        for(; i != intervals.end(); i++){
            if(i->end < newInterval.start){
                ret.push_back(*i);
            }else if(i->start <= newInterval.end){
                newInterval.start = min(newInterval.start, i->start);
                newInterval.end   = max(newInterval.end, i->end);
            }else{
                break;
            }
        }
        ret.push_back(newInterval);
        for(; i != intervals.end(); i++)
            ret.push_back(*i);
            
        return ret;
    }
};
