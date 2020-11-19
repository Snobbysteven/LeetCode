/**
Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.

**Example 1:**

```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

```

**Example 2:**

```
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

```

**Constraints:**

- `1 <= intervals.length <= 104`
- `intervals[i].length == 2`
- `0 <= starti <= endi <= 104`

*/



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int s1 = intervals[0][0];
        int e1 = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= e1) {
                s1 = min(intervals[i][0], s1);
                e1 = max(intervals[i][1], e1); 
            }else{
                result.push_back({s1, e1});
                s1 = intervals[i][0];
                e1 = intervals[i][1];
            }
            
        }
        result.push_back({s1, e1});


    return result;
        
    }
};
