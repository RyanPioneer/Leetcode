"""
Source: https://rb.gy/9z9sh
Date: 2023/8/23
Skill:
Runtime: 6048 ms, faster than 7.06%
Memory Usage: 17.52 MB, less than 10.61%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 100
    -100 <= matrix[i][j] <= 100
    -10^5 <= k <= 10^5
"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left
import heapq
import functools


class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], t: int) -> int:
        m, n, res = len(matrix), len(matrix[0]), -sys.maxsize

        def helper(arr):
            from sortedcontainers import SortedList
            sl, presum, result = SortedList(), 0, -sys.maxsize
            sl.add(0)
            for i in range(n):
                presum += arr[i]
                pos = bisect_left(sl, presum - t)
                if pos < len(sl):
                    result = max(result, presum - sl[pos])
                sl.add(presum)
            return result

        for i in range(m):
            nums = [0 for _ in range(n)]
            for j in range(i, m):
                for k in range(n):
                    nums[k] += matrix[j][k]
                res = max(res, helper(nums))
        return res


if __name__ == "__main__":
    s = Solution()
