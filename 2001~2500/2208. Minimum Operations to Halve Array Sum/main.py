"""
Source: https://rb.gy/ofm74
Date: 2023/8/9
Skill:
Ref:
Runtime: 912 ms, faster than 83.33%
Memory Usage: 31.08 MB, less than 82.74%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def halveArray(self, nums: List[int]) -> int:
        total, res, heap, target = sum(nums), 0, [-num for num in nums], sum(nums) / 2
        heapify(heap)
        while target > 0:
            num = heappop(heap)
            target += num / 2
            res += 1
            heappush(heap, num / 2)
        return res


if __name__ == "__main__":
    s = Solution()
