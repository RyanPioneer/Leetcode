"""
Source: https://rb.gy/k8zcn
Date: 2023/7/11
Skill:
Ref:
Runtime: TLE
Memory Usage:
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
    def checkArray(self, nums: List[int], k: int) -> bool:
        sz, left, arr = len(nums), 0, [0 for i in range(len(nums))]
        while left < sz - k + 1:
            if arr[left] > nums[left]:
                return False
            elif arr[left] == nums[left]:
                left += 1
            else:
                diff = nums[left] - arr[left]
                for i in range(k):
                    arr[left + i] += diff
                left += 1

        for i in range(sz - 1, sz - k, -1):
            if arr[i] != nums[i]:
                return False

        return True


if __name__ == "__main__":
    s = Solution()
