"""
Source: https://leetcode.com/problems/max-consecutive-ones-iii/
Date: 2023/4/9
Skill: Sliding window
Ref:
Runtime: 622 ms, faster than 58.26%
Memory Usage: 14.5 MB, less than 93.17%
Time complexity:
Space complexity:
Constraints:
    0 <= k <= nums.length
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left, right, sz, flip_num, res = 0, 0, len(nums), 0, 0
        while right < sz:
            if nums[right] == 0:
                flip_num += 1
            while flip_num > k:
                if nums[left] == 0:
                    flip_num -= 1
                left += 1
            res = max(res, right - left + 1)
            right += 1

        return res


if __name__ == "__main__":
    s = Solution()
