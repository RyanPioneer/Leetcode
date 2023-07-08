"""
Source: https://rb.gy/2err3
Date: 2023/7/8
Skill:
Ref:
Runtime: 48 ms, faster than 84.42%
Memory Usage: 16.4 MB, less than 89.90%
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
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        myset, sz, res = set(), len(nums), []
        for i in range(2 ** sz):
            num = []
            for j in range(sz):
                flag = i & 1 << j
                if flag:
                    num.append(nums[j])
            num.sort()
            myset.add(tuple(num))
        for i in myset:
            res.append(i)
        return res


if __name__ == "__main__":
    s = Solution()

