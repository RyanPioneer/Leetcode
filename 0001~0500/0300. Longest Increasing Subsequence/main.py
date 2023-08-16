"""
Source: https://rb.gy/e26re
Date: 2023/8/16
Skill:
Ref:
Runtime: 80 ms, faster than 91.54%
Memory Usage: 16.72 MB, less than 33.05%
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
    def lengthOfLIS(self, nums: List[int]) -> int:
        sz = len(nums)
        dp, max_len = [sys.maxsize for _ in range(sz + 1)], 0
        dp[0] = -sys.maxsize
        for num in nums:
            if num > dp[max_len]:
                max_len += 1
                dp[max_len] = num
            else:
                pos = bisect_right(dp, num)
                if pos <= max_len and dp[pos - 1] < num:
                    dp[pos] = num
        for i in range(sz, 0, -1):
            if dp[i] != sys.maxsize:
                return i
        return 0


if __name__ == "__main__":
    s = Solution()
    nums = [4, 10, 4, 3, 8, 9]
    res = s.lengthOfLIS(nums)
    print(res)
