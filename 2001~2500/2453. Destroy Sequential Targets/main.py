"""
Source: https://rb.gy/2tzcw
Date: 2023/7/14
Skill:
Ref:
Runtime: 727 ms, faster than 41.08%
Memory Usage: 43.15 MB, less than 21.71%
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
    def destroyTargets(self, nums: List[int], space: int) -> int:
        mydict, min_value, most_key = defaultdict(int), defaultdict(int), 0
        for num in nums:
            most_key = num % space
            mydict[most_key] += 1
            if most_key not in min_value:
                min_value[most_key] = num
            else:
                min_value[most_key] = min(min_value[most_key], num)
        for key in mydict.keys():
            if mydict[key] > mydict[most_key] or (mydict[key] == mydict[most_key]
                                                  and min_value[key] < min_value[most_key]):
                most_key = key
        return min_value[most_key]


if __name__ == "__main__":
    s = Solution()
    nums, space = [6, 2, 5], 100
    res = s.destroyTargets(nums, space)
    print(res)
