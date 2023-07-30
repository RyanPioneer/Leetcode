"""
Source: https://rb.gy/gaxjs
Date: 2023/7/30
Skill:
Ref:
Runtime: 115 ms, faster than 100.00%
Memory Usage: 16.71 MB, less than 100.00%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        target, sz, right, count, num2freq, res = len(set(nums)), len(nums), 0, 0, defaultdict(int), 0
        for i in range(sz):
            while right < sz and count < target:
                if num2freq[nums[right]] == 0:
                    count += 1
                num2freq[nums[right]] += 1
                right += 1
            if count == target:
                res += sz - right + 1
            num2freq[nums[i]] -= 1
            if num2freq[nums[i]] == 0:
                count -= 1
        return res


if __name__ == "__main__":
    s = Solution()
    nums = [5 for _ in range(4)]
    res = s.countCompleteSubarrays(nums)
