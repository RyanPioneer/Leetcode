"""
Source: https://leetcode.com/problems/longest-consecutive-sequence/
Date: 2023/3/17
Skill:
Runtime: 538 ms, faster than 48.24%
Memory Usage: 48.4 MB, less than 5.2%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        father, sz, res, father2num = {}, len(nums), 0, defaultdict(int)

        def find_father(x):
            if father[x] != x:
                father[x] = find_father(father[x])
            return father[x]

        def union(x, y):
            x_father, y_father = father[x], father[y]
            if x_father < y_father:
                father[y] = x_father
            else:
                father[x] = y_father

        for num in nums:
            father[num] = num
            if num - 1 in father and find_father(num - 1) != find_father(num):
                union(num - 1, num)
            if num + 1 in father and find_father(num + 1) != find_father(num):
                union(num + 1, num)

        for num in nums:
            find_father(num)

        for key, value in father.items():
            father2num[value] += 1

        for key, value in father2num.items():
            res = max(res, value)

        return res


if __name__ == "__main__":
    s = Solution()
