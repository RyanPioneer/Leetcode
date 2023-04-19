"""
Source: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
Date: 2023/4/19
Skill:
Ref:
Runtime: 8161 ms, faster than 45.77%
Memory Usage: 26.8 MB, less than 76.16%
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
    def numSubseq(self, nums: List[int], target: int) -> int:
        MOD, left, right, res, sz = 10 ** 9 + 7, 0, len(nums) - 1, 0, len(nums)
        nums.sort()
        while left <= right:
            if nums[left] * 2 > target:
                break
            while right > left and nums[right] > target - nums[left]:
                right -= 1
            res += 2 ** (right - left)
            left += 1

        return res % MOD


if __name__ == "__main__":
    s = Solution()
