"""
Source: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
Date: 2023/2/8
Skill: Prefix Sum, Monotonic Queue, Sliding Window
Runtime: 1383 ms, faster than 49.87%
Memory Usage: 28.5 MB, less than 42.93%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
    -10^5 <= nums[i] <= 10^5
    1 <= k <= 10^9
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        presum, sz, q, res = [0 for _ in range(len(nums)+1)], len(nums), deque([0]), math.inf
        for i in range(1, sz+1):
            presum[i] = presum[i-1] + nums[i-1]

        for i in range(1, sz+1):
            while q and presum[q[-1]] > presum[i]:
                q.pop()
            while q and presum[i] - presum[q[0]] >= k:
                res = min(res, i - q[0])
                q.popleft()
            q.append(i)

        return res if res != math.inf else -1


if __name__ == "__main__":
    s = Solution