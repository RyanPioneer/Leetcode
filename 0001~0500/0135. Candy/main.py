"""
Source: https://leetcode.com/problems/candy/?envType=study-plan-v2&envId=top-interview-150
Date: 2023/7/7
Skill:
Ref:
Runtime: 183 ms, faster than 30.97%
Memory Usage: 19.1 MB, less than 99.82%
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
    def candy(self, ratings: List[int]) -> int:
        nums = [1 for _ in range(len(ratings))]
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1]:
                nums[i] = nums[i-1] + 1
        for i in range(len(ratings) - 2, -1, -1):
            if ratings[i] > ratings[i+1]:
                nums[i] = max(nums[i], nums[i+1] + 1)
        return sum(nums)


if __name__ == "__main__":
    s = Solution()

