"""
Source: https://rb.gy/rpd7y
Date: 2023/7/26
Skill:
Ref:
Runtime: 1178 ms, faster than 49.29%
Memory Usage: 30.42 MB, less than 62.61%
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
    def minOperations(self, nums: List[int], x: int) -> int:
        sz, total, left, right, cur_sum, res = len(nums), sum(nums), 0, 0, 0, sys.maxsize
        if total < x:
            return -1
        if total == x:
            return sz
        while right < sz:
            while right < sz and cur_sum + nums[right] <= total - x:
                cur_sum += nums[right]
                right += 1
            if cur_sum == total - x:
                res = min(res, sz - (right - left))
            cur_sum -= nums[left]
            left += 1

        return res if res < sys.maxsize else -1


if __name__ == "__main__":
    s = Solution()
