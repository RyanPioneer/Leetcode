"""
Source: https://rb.gy/6u3n8
Date: 2023/8/2
Skill:
Ref:
Runtime: 855 ms, faster than 100.00%
Memory Usage: 38.45 MB, less than 73.15%
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
    def beautifulSubarrays(self, nums: List[int]) -> int:
        mymap, res, state = defaultdict(int), 0, 0
        mymap[state] = 1
        for num in nums:
            state ^= num
            res += mymap[state]
            mymap[state] += 1
        return res


if __name__ == "__main__":
    s = Solution()
