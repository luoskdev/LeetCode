/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-24
 * Email		: luoshikai@gmail.com
 *************************************/
 
/************************************** 
 * Given a set of non-overlapping intervals, insert a new interval into the 
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their 
 * start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * 
 * Example 2:
 *Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in 
 * as [1,2],[3,10],[12,16].
 * 
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *************************************/
 
 
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
    {
        vector<Interval> res;
        int i = 0;
        while (i < intervals.size() && intervals[i].end < newInterval.start)
        {
            res.push_back(intervals[i++]);
        }
        
        if (i == intervals.size() || newInterval.end < intervals[i].start)
        {
            res.push_back(newInterval);
        }
        else
        {
            res.push_back(intervals[i]);
            res.back().start = min(newInterval.start, res.back().start);
            int j = i;
            while (j < intervals.size() && newInterval.end > intervals[j].end)
            {
                ++j;
            }
            if (j == intervals.size() || newInterval.end < intervals[j].start)
            {
                res.back().end = newInterval.end;
                i = j;
            }
            else
            {
                res.back().end = max(newInterval.end, intervals[j].end);
                i = j + 1;
            }
        }
        while (i < intervals.size())
        {
            res.push_back(intervals[i++]);
        }
        
        return res;
    }
};