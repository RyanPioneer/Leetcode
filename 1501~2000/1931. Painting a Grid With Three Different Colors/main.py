"""
Source: https://rb.gy/p9ph8
Date: 2023/8/11
Skill:
Ref:
Runtime: 3800 ms, faster than 11.46%
Memory Usage: 16.7 MB, less than 63.54%
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
    def colorTheGrid(self, m: int, n: int) -> int:
        mod, cand = 10 ** 9 + 7, []
        for i in range(3 ** m):
            num, prev_num, flag = i // 3, i % 3, True
            for j in range(m - 1):
                cur_num = num % 3
                num //= 3
                if cur_num == prev_num:
                    flag = False
                    break
                else:
                    prev_num = cur_num
            if flag:
                cand.append(i)

        dp, sz = [1 for _ in range(len(cand))], len(cand)

        for _ in range(n - 1):
            dp2 = [0 for _ in range(sz)]
            for i in range(sz):
                for j in range(sz):
                    num, num2, flag = cand[i], cand[j], True
                    for _ in range(m):
                        if num % 3 == num2 % 3:
                            flag = False
                            break
                        else:
                            num //= 3
                            num2 //= 3
                    if flag:
                        dp2[i] += dp[j]
            dp = dp2

        return sum(dp) % mod


if __name__ == "__main__":
    s = Solution()
