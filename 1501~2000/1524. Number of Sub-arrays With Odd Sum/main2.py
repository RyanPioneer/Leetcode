"""
Source: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
Date: 2023/4/7
Skill:
Ref:
Runtime: 1191 ms, faster than 69.6%
Memory Usage: 18.2 MB, less than 71.29%
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


class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        presum, even_num, odd_num, sz, res, MOD  = 0, 0, 0, len(arr), 0, 10 ** 9 + 7
        for i in range(sz):
            presum += arr[i]
            if presum % 2:
                res += even_num + 1
                odd_num += 1
            else:
                res += odd_num
                even_num += 1

        return res % MOD


if __name__ == "__main__":
    s = Solution()
    arr = [2, 4, 6]
    res = s.numOfSubarrays(arr)
