"""
Source: https://leetcode.com/problems/k-closest-points-to-origin/
Date: 2023/1/21
Skill:
Runtime: 698 ms, faster than 99.84%
Memory Usage: 20.4 MB, less than 39%
Time complexity:
Space complexity:
Constraints:
    1 <= k <= points.length <= 10^4
"""

from typing import List
from collections import defaultdict

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points.sort(key=lambda x: x[0]*x[0]+x[1]*x[1])
        res, sz = [], len(points)
        for i in range(k):
            res.append(points[i])
        return res