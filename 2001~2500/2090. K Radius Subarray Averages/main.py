"""
Source: https://rb.gy/8v3q4
Date: 2023/7/11
Skill:
Ref:
Runtime: 1663 ms, faster than 38.75%
Memory Usage: 35.2 MB, less than 23.36%
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
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        if k == 0:
            return nums
        res, cur_sum, sz = [-1 for _ in range(len(nums))], 0, len(nums)
        if k * 2 >= sz:
            return res
        for i in range(k * 2 + 1):
            cur_sum += nums[i]
        for i in range(k, sz - k):
            res[i] = cur_sum // (2 * k + 1)
            if i < sz - k - 1:
                cur_sum -= nums[i-k]
                cur_sum += nums[i+k+1]
        return res


if __name__ == "__main__":
    s = Solution()
