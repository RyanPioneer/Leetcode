"""
Source: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
Date: 2023/4/7
Skill:
Ref:
Runtime: 1492 ms, faster than 7.93%
Memory Usage: 25 MB, less than 5.45%
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
        MOD = 10 ** 9 + 7
        presum, even_num, odd_num, sz, res = [0 for _ in range(len(arr))], \
            [0 for _ in range(len(arr))], [0 for _ in range(len(arr))], len(arr), 0

        presum[0] = arr[0]
        if arr[0] % 2:
            odd_num[0] = 1
        else:
            even_num[0] = 1

        for i in range(1, sz):
            presum[i] = presum[i - 1] + arr[i]
            if presum[i] % 2:
                even_num[i] = even_num[i - 1]
                odd_num[i] = odd_num[i - 1] + 1
            else:
                even_num[i] = even_num[i - 1] + 1
                odd_num[i] = odd_num[i - 1]

        for i in range(sz):
            if presum[i] % 2:
                res += even_num[i] + 1
            else:
                res += odd_num[i]

        return res % MOD


if __name__ == "__main__":
    s = Solution()
    arr = [2, 4, 6]
    res = s.numOfSubarrays(arr)
