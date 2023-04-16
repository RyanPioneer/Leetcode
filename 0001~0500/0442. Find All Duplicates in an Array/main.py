"""
Source: https://leetcode.com/problems/find-all-duplicates-in-an-array/
Date: 2023/4/16
Skill: indexing sort
Ref:
Runtime: 414 ms, faster than 14.49%
Memory Usage: 21.1 MB, less than 89.69%
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
from bisect import bisect_left, bisect_right


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        sz, res = len(nums), []
        for i in range(sz):
            while nums[i] != i + 1 and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

        for i in range(sz):
            if nums[i] != i + 1:
                res.append(nums[i])

        return res


if __name__ == "__main__":
    s = Solution()
    nums = [1, 1, 2]
    res = s.findDuplicates(nums)
