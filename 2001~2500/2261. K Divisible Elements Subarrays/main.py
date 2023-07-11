"""
Source: https://rb.gy/tvygd
Date: 2023/7/11
Skill:
Ref:
Runtime: 484 ms, faster than 60.84%
Memory Usage: 30.6 MB, less than 31.56%
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
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        res, sz = set(), len(nums)
        for i in range(sz):
            cur_num, elements_num = tuple(), 0
            for j in range(i, sz):
                cur_num += (nums[j],)
                if nums[j] % p == 0:
                    elements_num += 1
                if elements_num > k:
                    break
                res.add(cur_num)
        return len(res)


if __name__ == "__main__":
    s = Solution()
