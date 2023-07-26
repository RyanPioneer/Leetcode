"""
Source: https://rb.gy/okmbm
Date: 2023/7/26
Skill:
Ref:
Runtime: 1218 ms, faster than 52.73%
Memory Usage: 34.22 MB, less than 83.64%
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
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int:
        sz, res, diff, time = len(nums1), 0, [abs(nums1[i] - nums2[i]) for i in range(len(nums1))], k1 + k2
        diff.sort(reverse=True)
        diff.append(0)
        if sum(diff) <= time:
            return 0
        pre_sum, idx = diff[0], 1
        while idx < sz and (pre_sum - diff[idx] * idx) <= time:
            pre_sum += diff[idx]
            idx += 1

        for i in range(idx):
            time -= diff[i] - diff[idx - 1]
            diff[i] = diff[idx - 1]

        for i in range(idx):
            diff[i] -= time // idx

        for i in range(time % idx):
            diff[i] -= 1

        return sum(diff[i] ** 2 for i in range(sz))


if __name__ == "__main__":
    s = Solution()
