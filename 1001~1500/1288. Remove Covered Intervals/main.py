"""
Source: https://leetcode.com/problems/remove-covered-intervals/
Date: 2022/2/20
Constraints: 
    1 <= intervals.length <= 1000
    intervals[i].length == 2
    0 <= li <= ri <= 10^5
    All the given intervals are unique.
"""

from typing import List
        
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        