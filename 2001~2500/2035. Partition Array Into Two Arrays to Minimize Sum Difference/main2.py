"""
Source: https://rb.gy/ozvjm
Date: 2023/7/24
Skill:
Ref:
Runtime: 2382 ms, faster than 5.01%
Memory Usage: 17.05 MB, less than 62.56%
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
    def minimumDifference(self, nums: List[int]) -> int:
        sz, length = 0, len(nums)
        for num in nums:
            sz += abs(num)
        dp = [[-2 for _ in range(2 * sz + 1)] for _ in range(length)]
        res = [[[] for _ in range(2 * sz + 1)] for _ in range(length)]
        dp[0][sz + nums[0]] = 1
        res[0][sz + nums[0]] = [nums[0]]
        dp[0][sz - nums[0]] = -1
        res[0][sz - nums[0]] = [-nums[0]]
        for i in range(length - 1):
            height = nums[i + 1]
            for j in range(-sz, sz + 1):
                if j + height <= sz and dp[i][j + sz] != -2:
                    num = 1
                    if dp[i][j + sz] == -1 or dp[i][j + sz] == 2:
                        num = 2
                    if num >= dp[i + 1][j + height + sz]:
                        res[i + 1][j + height + sz] = res[i][j + sz].copy()
                        res[i + 1][j + height + sz].append(height)
                    dp[i + 1][j + height + sz] = max(dp[i + 1][j + height + sz], num)
                if j - height >= -sz and dp[i][j + sz] != -2:
                    num = -1
                    if dp[i][j + sz] == 1 or dp[i][j + sz] == 2:
                        num = 2
                    if num >= dp[i + 1][j - height + sz]:
                        res[i + 1][j - height + sz] = res[i][j + sz].copy()
                        res[i + 1][j - height + sz].append(-height)
                    dp[i + 1][j - height + sz] = max(dp[i + 1][j - height + sz], num)

        for i in range(sz + 1):
            if dp[-1][sz + i] == 2:
                print(res[-1][sz + i])
                return i
            if dp[-1][sz - i] == 2:
                print(res[-1][sz - i])
                return i


if __name__ == "__main__":
    s = Solution()
    nums = [76, 8, 45, 20, 74, 84, 28, 1]
    # nums = [3, 9, 7, 3]
    res = s.minimumDifference(nums)
    print(res)
