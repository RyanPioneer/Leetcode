"""
Source: https://rb.gy/bhk3w
Date: 2023/7/26
Skill:
Ref:
Runtime: 127 ms, faster than 71.60%
Memory Usage: 17.78 MB, less than 69.15%
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
    def majorityElement(self, nums: List[int]) -> List[int]:
        res, mydict, sz = set(), defaultdict(int), len(nums)
        for num in nums:
            mydict[num] += 1
            if mydict[num] > sz // 3 and num not in res:
                res.add(num)
        return list(res)


if __name__ == "__main__":
    s = Solution()
