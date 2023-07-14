"""
Source: https://rb.gy/2tzcw
Date: 2023/7/14
Skill:
Ref:
Runtime: 650 ms, faster than 89.15%
Memory Usage: 35.95 MB, less than 77.52%
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
    def destroyTargets(self, nums: List[int], space: int) -> int:
        cnt = Counter(num % space for num in nums)
        most_num = max(cnt.values())
        return min(num for num in nums if cnt[num % space] == most_num)


if __name__ == "__main__":
    s = Solution()
    nums, space = [6, 2, 5], 100
    res = s.destroyTargets(nums, space)
    print(res)
