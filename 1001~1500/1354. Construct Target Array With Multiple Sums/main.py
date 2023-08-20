"""
Source: https://rb.gy/nvc8x
Date: 2023/8/20
Skill:
Runtime: 51 ms, faster than 81.71%
Memory Usage: 14.2 MB, less than 29.27%
Time complexity:
Space complexity:
Constraints:
    1 <= target.length <= 5 * 10 ** 4
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def isPossible(self, target: List[int]) -> bool:
        cur_sum, sz, heap = sum(target), len(target), []
        for num in target:
            heap.append(-num)
        heapify(heap)
        while cur_sum > sz:
            num = -heappop(heap)
            prev_num = num - (cur_sum - num)
            if prev_num < 1:
                return False

            heappush(heap, -prev_num)
            cur_sum -= num - prev_num
        return heap == [-1 for _ in range(sz)]


if __name__ == "__main__":
    s = Solution()
