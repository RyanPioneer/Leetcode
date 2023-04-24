"""
Source: https://leetcode.com/problems/last-stone-weight/
Date: 2023/4/24
Skill:
Ref:
Runtime: 29 ms, faster than 83.46%
Memory Usage: 13.8 MB, less than 47.65%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = []
        heapify(heap)
        for stone in stones:
            heappush(heap, -stone)
        while len(heap) > 1:
            num1, num2 = heappop(heap) * -1, heappop(heap) * -1
            if num1 == num2:
                continue
            else:
                num = abs(num1 - num2)
                heappush(heap, -num)

        return -heap[0] if heap else 0


if __name__ == "__main__":
    s = Solution()
