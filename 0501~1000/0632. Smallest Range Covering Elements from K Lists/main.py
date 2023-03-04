"""
Source: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
Date: 2023/3/4
Skill:
Runtime: 427 ms, faster than 14.45%
Memory Usage: 19.4 MB, less than 97.95%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        sl, res, value2list, sz = SortedList(), [], defaultdict(list), len(nums)
        for i in range(sz):
            value2list[nums[i][0]].append(i)
            sl.add(nums[i].pop(0))

        res = [sl[0], sl[-1]]
        while True:
            list_num = value2list[sl[0]][0]
            value2list[sl[0]].pop(0)
            if len(nums[list_num]) == 0:
                return res
            sl.remove(sl[0])
            value2list[nums[list_num][0]].append(list_num)
            sl.add(nums[list_num].pop(0))
            if sl[-1] - sl[0] < res[1] - res[0]:
                res[0], res[1] = sl[0], sl[-1]


if __name__ == "__main__":
    s = Solution()
    nums = [[4, 10, 15, 24, 26], [0, 9, 12, 20], [5, 18, 22, 30]]
    res = s.smallestRange(nums)
