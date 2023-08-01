"""
Source: https://rb.gy/9v0cn
Date: 2023/7/31
Skill:
Ref:
Runtime: 32 ms, faster than 99.91%
Memory Usage: 16.35 MB, less than 41.68%
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
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        res, num_set = 0, set(nums)
        for num in nums:
            if num - diff in num_set and num + diff in num_set:
                res += 1
        return res


if __name__ == "__main__":
    s = Solution()
