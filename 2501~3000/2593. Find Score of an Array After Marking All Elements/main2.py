"""
Source: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/
Date: 2023/3/30
Skill:
Runtime: 1165 ms, faster than 74.49%
Memory Usage: 31.8 MB, less than 97.59%
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
        res, arr, sz = 0, sorted([(num, idx) for idx, num in enumerate(nums)]), len(nums)
        for i in range(sz):
            if nums[arr[i][1]] != -1:
                res += arr[i][0]
                nums[arr[i][1]] = -1
                if arr[i][1] > 0:
                    nums[arr[i][1] - 1] = -1
                if arr[i][1] + 1 < sz:
                    nums[arr[i][1] + 1] = -1

        return res


if __name__ == "__main__":
    s = Solution()
