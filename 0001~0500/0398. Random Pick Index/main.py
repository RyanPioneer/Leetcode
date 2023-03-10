"""
Source: https://leetcode.com/problems/random-pick-index/
Date: 2023/3/10
Skill:
Runtime: 397 ms, faster than 32.85%
Memory Usage: 24.2 MB, less than 70.58%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 2 * 10^4
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

    def __init__(self, nums: List[int]):
        self.nums, self.my_dict = nums, defaultdict(list)
        for i in range(len(self.nums)):
            self.my_dict[self.nums[i]].append(i)


    def pick(self, target: int) -> int:
        import random
        return self.my_dict[target][random.randint(0, len(self.my_dict[target])-1)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)


if __name__ == "__main__":
    s = Solution()
