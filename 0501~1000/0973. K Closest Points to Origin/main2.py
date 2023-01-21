"""
Source: https://leetcode.com/problems/k-closest-points-to-origin/
Date: 2023/1/21
Skill: Priority Queue
Runtime: 770 ms, faster than 95.12%
Memory Usage: 20.5 MB, less than 39%
Time complexity:
Space complexity:
Constraints:
    1 <= k <= points.length <= 10^4
"""

from typing import List
from heapq import heapify, heappush, heappop

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap, res = [], []
        heapify(heap)
        for i in range(len(points)):
            heappush(heap, [-(points[i][0] * points[i][0] + points[i][1] * points[i][1]), i])
            if len(heap) > k: heappop(heap)

        for point in heap:
            res.append(points[point[1]])

        return res