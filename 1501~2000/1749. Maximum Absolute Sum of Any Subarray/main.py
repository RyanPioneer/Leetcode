"""
Source: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
Date: 2023/4/13
Skill: Kadane algorithm, Dynamic Programming
Ref:
Runtime: 522 ms, faster than 57.89%
Memory Usage: 27.6 MB, less than 98.9%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        max_num, min_num, res = 0, 0, 0
        for num in nums:
            max_num = max(max_num + num, num)
            min_num = min(min_num + num, num)
            res = max(res, abs(max_num), abs(min_num))

        return res


if __name__ == "__main__":
    s = Solution()
