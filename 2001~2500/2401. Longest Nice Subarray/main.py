"""
Source: https://leetcode.com/problems/longest-nice-subarray/
Date: 2023/2/7
Skill: Sliding Window
Runtime: 759 ms, faster than 50%
Memory Usage: 28.8 MB, less than 94.42%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        left, right, count, res, sz = 0, 1, nums[0], 1, len(nums)
        while right < sz:
            if count&nums[right] != 0:
                res = max(res, right-left)
                while count&nums[right] != 0:
                    count -= nums[left]
                    left += 1

            count += nums[right]
            right += 1

        return max(res, right-left)


if __name__ == "__main__":
    s = Solution
    fruits = [3,3,3,1,2,1,1,2,3,3,4]
