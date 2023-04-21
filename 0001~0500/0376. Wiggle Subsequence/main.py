"""
Source: https://leetcode.com/problems/wiggle-subsequence/
Date: 2023/4/20
Skill:
Ref:
Runtime: 8161 ms, faster than 45.77%
Memory Usage: 26.8 MB, less than 76.16%
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
        sz, res = len(nums), 1
        dp = [[1 for _ in range(2)] for _ in range(sz)]
        for i in range(1, sz):
            flag = 0
            for j in range(i - 1, -1, -1):
                if dp[i][0] == 1 and nums[j] < nums[i]:
                    flag += 1
                    dp[i][0] = dp[j][1] + 1
                    res = max(res, dp[i][0])
                if dp[i][1] == 1 and nums[j] > nums[i]:
                    flag += 1
                    dp[i][1] = dp[j][0] + 1
                    res = max(res, dp[i][1])
                if flag == 2:
                    break

        return res


if __name__ == "__main__":
    s = Solution()
    nums = [33, 53, 12, 64, 50, 41, 45, 21, 97, 35, 47, 92, 39, 0, 93, 55, 40, 46, 69, 42, 6, 95, 51, 68, 72, 9, 32, 84,
            34, 64, 6, 2, 26, 98, 3, 43, 30, 60, 3, 68, 82, 9, 97, 19, 27, 98, 99, 4, 30, 96, 37, 9, 78, 43, 64, 4, 65,
            30, 84, 90, 87, 64, 18, 50, 60, 1, 40, 32, 48, 50, 76, 100, 57, 29, 63, 53, 46, 57, 93, 98, 42, 80, 82, 9,
            41, 55, 69, 84, 82, 79, 30, 79, 18, 97, 67, 23, 52, 38, 74, 15]
    res = s.wiggleMaxLength(nums)
