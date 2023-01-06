"""
Source: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
Date: 2023/1/5
Skill: Greedy
Runtime: 1444 ms, faster than 72.23%
Memory Usage: 59.9 MB, less than 70.29%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key = lambda x: x[1])
        right, res, sz = points[0][1], 1, len(points)
        for index in range(1, sz):
            if points[index][0] > right:
                right = points[index][1]
                res += 1

        return res


if __name__ == "__main__":
    s = Solution