"""
Source: https://leetcode.com/problems/xor-queries-of-a-subarray/
Date: 2023/4/16
Skill:
Ref:
Runtime: 381 ms, faster than 80.69%
Memory Usage: 28.8 MB, less than 40.10%
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
from bisect import bisect_left, bisect_right


class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        arr.insert(0, 0)
        pre_xor, res, sz = [arr[i] for i in range(len(arr))], [], len(arr)
        for i in range(1, sz):
            pre_xor[i] ^= pre_xor[i - 1]

        for query in queries:
            res.append(pre_xor[query[1] + 1] ^ pre_xor[query[0]])

        return res


if __name__ == "__main__":
    s = Solution()
