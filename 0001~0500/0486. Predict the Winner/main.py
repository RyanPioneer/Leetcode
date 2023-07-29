"""
Source: https://rb.gy/3rptt
Date: 2023/7/28
Skill:
Ref:
Runtime: 23 ms, faster than 100%
Memory Usage: 16.45 MB, less than 43.57%
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
    def PredictTheWinner(self, nums: List[int]) -> bool:
        dp, sz = [[-1 for _ in range(len(nums))] for _ in range(len(nums))], len(nums)
        for i in range(sz):
            dp[i][i] = nums[i]

        def find_num(left, right):
            if dp[left][right] != -1:
                return dp[left][right]
            if dp[left + 1][right] != -1:
                num1 = nums[left] - dp[left + 1][right]
            else:
                num1 = nums[left] - find_num(left + 1, right)
            if dp[left][right - 1] != -1:
                num2 = nums[right] - dp[left][right - 1]
            else:
                num2 = nums[right] - find_num(left, right - 1)
            dp[left][right] = max(num1, num2)
            return dp[left][right]

        return True if find_num(0, sz - 1) >= 0 else False


if __name__ == "__main__":
    s = Solution()
