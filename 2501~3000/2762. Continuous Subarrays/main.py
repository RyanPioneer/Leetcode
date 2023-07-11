"""
Source: https://rb.gy/3qz5l
Date: 2023/7/11
Skill:
Ref:
Runtime: 905 ms, faster than 76.24%
Memory Usage: 26.8 MB, less than 56.11%
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
    def continuousSubarrays(self, nums: List[int]) -> int:
        q1, q2, res, left = deque(), deque(), 0, 0
        for i in range(len(nums)):
            while q1 and nums[q1[-1]] <= nums[i]:
                q1.pop()
            q1.append(i)
            while q2 and nums[q2[-1]] >= nums[i]:
                q2.pop()
            q2.append(i)
            while q1 and q2 and nums[q1[0]] - nums[q2[0]] > 2:
                if q1[0] == left:
                    q1.popleft()
                if q2[0] == left:
                    q2.popleft()
                left += 1
            res += i - left + 1
        return res


if __name__ == "__main__":
    s = Solution()
