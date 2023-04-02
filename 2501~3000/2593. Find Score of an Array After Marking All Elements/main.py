"""
Source: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/
Date: 2023/3/30
Skill:
Runtime: 1572 ms, faster than 32.93%
Memory Usage: 33.5 MB, less than 90.53%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^6
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def findScore(self, nums: List[int]) -> int:
        res, heap, sz = 0, [], len(nums)
        heapify(heap)
        for i in range(sz):
            heappush(heap, (nums[i], i))
        while heap:
            num, pos = heappop(heap)
            if nums[pos] != -1:
                res += num
                if pos > 0:
                    nums[pos - 1] = -1
                if pos + 1 < sz:
                    nums[pos + 1] = -1

        return res


if __name__ == "__main__":
    s = Solution()
