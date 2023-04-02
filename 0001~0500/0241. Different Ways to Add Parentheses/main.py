"""
Source: https://leetcode.com/problems/different-ways-to-add-parentheses/
Date: 2023/4/2
Skill:
Runtime: 38 ms, faster than 56.46%
Memory Usage: 13.9 MB, less than 76.79%
Time complexity:
Space complexity:
Constraints:
    1 <= expression.length <= 20
    expression consists of digits and the operator '+', '-', and '*'.
    All the integer values in the input expression are in the range [0, 99].
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        nums, ops, i, sz = [], [], 0, len(expression)
        while i < sz:
            j = i
            while j < sz and expression[j].isnumeric():
                j += 1
            nums.append(int(expression[i:j]))
            if j < sz:
                ops.append(expression[j])
            i = j + 1

        sz = len(nums)
        dp = [[[] for _ in range(sz)] for _ in range(sz)]

        def helper(start, end):
            if len(dp[start][end]) != 0:
                return
            if start == end:
                dp[start][end].append(nums[start])
                return
            for i in range(start, end):
                helper(start, i)
                helper(i + 1, end)
                for num1 in dp[start][i]:
                    for num2 in dp[i + 1][end]:
                        if ops[i] == "+":
                            dp[start][end].append(num1 + num2)
                        elif ops[i] == "-":
                            dp[start][end].append(num1 - num2)
                        else:
                            dp[start][end].append(num1 * num2)

        helper(0, sz - 1)
        return dp[0][sz - 1]


if __name__ == "__main__":
    s = Solution()
