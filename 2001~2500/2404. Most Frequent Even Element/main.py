"""
Source: https://rb.gy/z2ryl
Date: 2023/7/26
Skill:
Ref:
Runtime: 302 ms, faster than 34.87%
Memory Usage: 16.66 MB, less than 91.87%
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
    def mostFrequentEven(self, nums: List[int]) -> int:
        mydict, res, sz = defaultdict(int), -1, len(nums)
        for num in nums:
            if num % 2 == 1:
                continue
            mydict[num] += 1
            if res == -1 or mydict[num] > mydict[res] or (mydict[num] == mydict[res] and num < res):
                res = num

        return res


if __name__ == "__main__":
    s = Solution()
