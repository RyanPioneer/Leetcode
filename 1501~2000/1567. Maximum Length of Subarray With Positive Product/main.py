"""
Source: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
Date: 2023/4/19
Skill:
Ref:
Runtime: 619 ms, faster than 74.34%
Memory Usage: 28.9 MB, less than 31.22%
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
    def getMaxLen(self, nums: List[int]) -> int:
        pos, neg, res = 0, 0, 0
        for num in nums:
            if num == 0:
                pos, neg = 0, 0
            elif num > 0:
                pos += 1
                if neg > 0:
                    neg += 1
                res = max(res, pos)
            else:
                neg, pos = pos + 1, neg + 1 if neg > 0 else 0
                res = max(res, pos)

        return res


if __name__ == "__main__":
    s = Solution()
    nums = [-16, 0, -5, 2, 2, -13, 11, 8]
    res = s.getMaxLen(nums)
