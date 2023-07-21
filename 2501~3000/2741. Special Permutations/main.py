"""
Source: https://rb.gy/pbsgk
Date: 2023/7/21
Skill:
Ref:
Runtime: 5977 ms, faster than 18.07%
Memory Usage: 228.96 MB, less than 5.04%
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
    def specialPerm(self, nums: List[int]) -> int:
        MOD, memoization, sz = 10 ** 9 + 7, defaultdict(int), len(nums)

        def dfs(state, idx, cur_num):
            if idx == sz:
                return 1
            if (state, idx, cur_num) in memoization:
                return memoization[(state, idx, cur_num)]
            total_num = 0
            for i in range(sz):
                cur_state = (1 << i) & state
                if cur_state == 0:
                    num = nums[i]
                    if cur_num == -1 or num % cur_num == 0 or cur_num % num == 0:
                        total_num += dfs(state + (1 << i), idx + 1, num)

            memoization[(state, idx, cur_num)] = total_num
            return memoization[(state, idx, cur_num)] % MOD

        return dfs(0, 0, -1)


if __name__ == "__main__":
    s = Solution()
