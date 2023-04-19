"""
Source: https://leetcode.com/problems/subarray-product-less-than-k/
Date: 2023/4/19
Skill:
Ref:
Runtime: 692 ms, faster than 70.55%
Memory Usage: 16.5 MB, less than 57.20%
Time complexity:
Space complexity:
Constraints:
    1 <= nums[i] <= 1000
    0 <= k <= 10^6
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k == 0 or k == 1:
            return 0
        left, right, sz, res, product = 0, 0, len(nums), 0, 1
        while right < sz:
            product *= nums[right]
            while product >= k and left < sz:
                product //= nums[left]
                left += 1
            res += right - left + 1
            right += 1

        return res


if __name__ == "__main__":
    s = Solution()
