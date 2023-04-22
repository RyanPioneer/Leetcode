"""
Source: https://leetcode.com/problems/wiggle-subsequence/
Date: 2023/4/21
Skill:
Ref:
Runtime: 34 ms, faster than 78.2%
Memory Usage: 13.9 MB, less than 65.32%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        sz, res, pos = len(nums), 1, 1
        while pos < sz and nums[pos] == nums[pos - 1]:
            pos += 1
        if pos == sz:
            return res
        else:
            res = 2
        flag = 1 if nums[pos] > nums[pos - 1] else 0
        while pos + 1 < sz:
            pos += 1
            if nums[pos] == nums[pos - 1]:
                continue
            elif nums[pos] > nums[pos - 1]:
                if flag == 1:
                    continue
                else:
                    res += 1
                    flag = 1
            else:
                if flag == 0:
                    continue
                else:
                    res += 1
                    flag = 0

        return res


if __name__ == "__main__":
    s = Solution()
    nums = [33, 53, 12, 64, 50, 41, 45, 21, 97, 35, 47, 92, 39, 0, 93, 55, 40, 46, 69, 42, 6, 95, 51, 68, 72, 9, 32, 84,
            34, 64, 6, 2, 26, 98, 3, 43, 30, 60, 3, 68, 82, 9, 97, 19, 27, 98, 99, 4, 30, 96, 37, 9, 78, 43, 64, 4, 65,
            30, 84, 90, 87, 64, 18, 50, 60, 1, 40, 32, 48, 50, 76, 100, 57, 29, 63, 53, 46, 57, 93, 98, 42, 80, 82, 9,
            41, 55, 69, 84, 82, 79, 30, 79, 18, 97, 67, 23, 52, 38, 74, 15]
    res = s.wiggleMaxLength(nums)
