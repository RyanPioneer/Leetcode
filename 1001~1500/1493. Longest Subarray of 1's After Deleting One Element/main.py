"""
Source: https://rb.gy/036or
Date: 2023/7/5
Skill:
Ref:
Runtime: 363 ms, faster than 78.50%
Memory Usage: 18.9 MB, less than 71.60%
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
    def longestSubarray(self, nums: List[int]) -> int:
        res, prev_num, sz, idx = 0, 0, len(nums), 0
        while idx < sz and nums[idx] == 1:
            res += 1
            prev_num += 1
            idx += 1
        if idx == sz:
            return res - 1
        while idx < sz:
            idx += 1
            cur_num = 0
            while idx < sz and nums[idx] == 1:
                cur_num += 1
                idx += 1
            res = max(res, prev_num + cur_num)
            prev_num = cur_num
        return res


if __name__ == "__main__":
    s = Solution()
