"""
Source: https://rb.gy/51y3g
Date: 2023/8/4
Skill:
Ref:
Runtime: 230 ms, faster than 39.79%
Memory Usage: 17.78 MB, less than 63.36%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        q1, q2, sz = deque([0]), deque([len(nums) - 1]), len(nums)
        for i in range(1, sz):
            while q1 and nums[i] < nums[q1[-1]]:
                q1.pop()
            q1.append(i)
            while q2 and nums[sz - 1 - i] > nums[q2[-1]]:
                q2.pop()
            q2.append(sz - 1 - i)

        left, right = 0, 0
        while q1 and q1[0] == left:
            q1.popleft()
            left += 1
        while q2 and q2[0] == sz - 1 - right:
            q2.popleft()
            right += 1

        return sz - left - right if left != sz else 0


if __name__ == "__main__":
    s = Solution()
