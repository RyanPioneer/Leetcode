"""
Source: https://rb.gy/s24gi
Date: 2023/7/22
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
    def tallestBillboard(self, rods: List[int]) -> int:
        rods.insert(0, 0)
        sz, length = sum(rods) // 2 + 1, len(rods)
        dp = [-sys.maxsize for _ in range(2 * sz + 1)]
        dp[sz] = 0
        for i in range(length - 1):
            dp2 = dp.copy()
            for j in range(-sz, sz + 1):
                height = rods[i + 1]
                if height + j <= 0:
                    dp[height + j + sz] = max(dp[height + j + sz], dp2[j + sz])
                elif height + j <= sz:
                    num = height + j if j < 0 else height
                    dp[height + j + sz] = max(dp[height + j + sz], dp2[j + sz] + num)
                if j - height >= 0:
                    dp[j - height + sz] = max(dp[j - height + sz], dp2[j + sz])
                elif j - height >= -sz:
                    num = height - j if j > 0 else height
                    dp[j - height + sz] = max(dp[j - height + sz], dp2[j + sz] + num)

        return dp[sz] if dp[sz] > 0 else 0


if __name__ == "__main__":
    s = Solution()
    nums = [1, 2, 3, 4, 5, 6]
    res = s.tallestBillboard(nums)
