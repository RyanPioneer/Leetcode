"""
Source: https://rb.gy/7fit6
Date: 2023/7/23
Skill:
Ref:
Runtime: 1020 ms, faster than 16.67%
Memory Usage: 30.61 MB, less than 100.00%
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
    def maxArrayValue(self, nums: List[int]) -> int:
        res, sz, cur_val = nums[-1], len(nums), nums[-1]
        for i in range(sz - 2, -1, -1):
            num = nums[i]
            if num <= cur_val:
                cur_val += num
            else:
                cur_val = num
            res = max(res, cur_val)

        return res


if __name__ == "__main__":
    s = Solution()
