"""
Source: https://rb.gy/ixs95
Date: 2023/7/27
Skill:
Ref:
Runtime: 86 ms, faster than 83.83%
Memory Usage: 18.05 MB, less than 58.14%
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
    def findPairs(self, nums: List[int], k: int) -> int:
        if k == 0:
            cnt, res = Counter(nums), 0
            for key, val in cnt.items():
                if val > 1:
                    res += 1
            return res

        nums = list(set(nums))
        nums.sort()
        sz, right, res = len(nums), 0, 0
        for i in range(sz):
            while right < sz and nums[right] - nums[i] < k:
                right += 1
            if right == sz:
                break
            if nums[right] - nums[i] == k:
                res += 1
                right += 1
        return res


if __name__ == "__main__":
    s = Solution()
    nums, k = [i for i in range(1, 6)], 1
    res = s.findPairs(nums, k)
