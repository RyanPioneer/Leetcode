"""
Source: https://rb.gy/okmbm
Date: 2023/7/26
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
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int:
        sz, res, heap, time = len(nums1), 0, [], k1 + k2
        heapify(heap)
        for i in range(sz):
            res += (nums1[i] - nums2[i]) ** 2
            heappush(heap, -abs(nums1[i] - nums2[i]))
        while time > 0:
            diff1 = heappop(heap)
            diff2 = heappop(heap)
            if diff1 == 0:
                break
            elif diff1 == diff2:
                res += 2 * diff1 + 1
                heappush(heap, diff1)
                heappush(heap, diff1 + 1)
                time -= 1
            elif diff2 - diff1 >= time:
                res += 2 * diff1 * time + time ** 2
                break
            else:
                res += 2 * diff1 * (diff2 - diff1) + (diff2 - diff1) ** 2
                heappush(heap, diff2)
                heappush(heap, diff2)
                time -= (diff2 - diff1)

        return res


if __name__ == "__main__":
    s = Solution()
    nums1, nums2, k1, k2 = [1, 4, 10, 12], [5, 8, 6, 9], 10, 12
    res = s.minSumSquareDiff(nums1, nums2, k1, k2)
