"""
Source: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/
Date: 2023/2/7
Skill:
Runtime: 2629 ms, faster than 58.24%
Memory Usage: 28.5 MB, less than 54.40%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
    0 <= nums[i] <= 10^9
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        count, sz, res, tail = [0 for _ in range(32)], len(nums), [], len(nums)-1

        def check_valid(num):
            for i in range(32):
                if (num>>i)&1 and count[i] == 1:
                    return False

            return True

        for head in range(sz-1, -1, -1):
            for i in range(32):
                if (nums[head]>>i)&1:
                    count[i] += 1

            while tail > head and check_valid(nums[tail]):
                for i in range(32):
                    if (nums[tail] >> i) & 1:
                        count[i] -= 1
                tail -= 1

            res.append(tail-head+1)

        return res[::-1]


if __name__ == "__main__":
    s = Solution