"""
Source: https://leetcode.com/problems/binary-search/
Date: 2023/3/17
Skill:
Runtime: 244 ms, faster than 67.75%
Memory Usage: 15.4 MB, less than 59.76%
Time complexity:
Space complexity:
Constraints:

"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid

        return left if nums[left] == target else -1


if __name__ == "__main__":
    s = Solution()
