// 57. Insert Interval
// Difficulty: Medium
// URL: https://leetcode.com/problems/insert-interval/
//
// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
//
// Two intervals are considered overlapping if they share at least one point.
//
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
//
// Return intervals after the insertion.
//
// Note that you don't need to modify intervals in-place. You can make a new array and return it.
//
//
//
// Example 1:
//
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
//
// Example 2:
//
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//
//
//
// Constraints:
//
// 	  * 0 <= intervals.length <= 104
//
// 	  * intervals[i].length == 2
//
// 	  * 0 <= starti <= endi <= 105
//
// 	  * intervals is sorted by starti in ascending order.
//
// 	  * newInterval.length == 2
//
// 	  * 0 <= start <= end <= 105

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int key = newInterval[0];

        //binary search to find position

        int i = 0;
        int j = n-1;
        int pos = -1;

        while(i<=j){
            int mid = i+(j-i)/2;
            if(intervals[mid][0] >=key){
                pos = mid;
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }

        if(pos>=0){
            intervals.insert(intervals.begin()+pos,newInterval);
        }

        vector<vector<int>> mergedIntervals;

        mergedIntervals.push_back(intervals[0]);

        for(int i = 1;i<n+1;i++){
            vector<int> interval = intervals[i];
            vector<int> prev = mergedIntervals.back();

            if(prev[1]>=interval[0]){
                vector<int> next = {min(prev[0],interval[0]),max(prev[1],interval[1])};

                mergedIntervals.pop_back();
                mergedIntervals.push_back(next);
            }
            else{
                mergedIntervals.push_back(interval);
            }
        }

        return mergedIntervals;
    }
};