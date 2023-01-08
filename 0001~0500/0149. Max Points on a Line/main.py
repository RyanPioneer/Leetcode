"""
Source: https://leetcode.com/problems/max-points-on-a-line/
Date: 2023/1/8
Skill:
Ref:
Runtime: 110 ms, faster than 80.33%
Memory Usage: 14.1 MB, less than 43.34%
Time complexity:
Space complexity:
Constraints:
    1 <= points.length <= 300
    All the points are unique.
"""

from typing import List, Optional
import math
from collections import defaultdict

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        sz, res = len(points), 1
        if sz == 1: return res
        for i in range(sz):
            myDict = defaultdict(int)
            for j in range(sz):
                if j != i:
                    myDict[math.atan2(points[j][1] - points[i][1],\
                        points[j][0] - points[i][0])] += 1
            res = max(res, max(myDict.values())+1)

        return res