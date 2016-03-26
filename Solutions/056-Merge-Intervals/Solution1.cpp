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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.size() < 1)
            return ret;
        // sort the intervals by start index
        sort(intervals.begin(), intervals.end(), myCmp);
        Interval temp = intervals[0];
        // Scan and Merge
        for(auto i : intervals){
            // If i and temp are overlapping, merge them
            if(i.start <= temp.end)
                temp.end = max(temp.end, i.end);
            else{
            // else store temp, and update it with i
                ret.push_back(temp);
                temp = i;
            }
        }
        ret.push_back(temp);
        return ret;
    }
    
private:
    static bool myCmp(Interval &x, Interval &y)
    {
        return x.start < y.start;
    }
};
