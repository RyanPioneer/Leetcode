"""
Source: https://rb.gy/wq7q3
Date: 2023/7/25
Skill:
Ref:
Runtime: 1912 ms, faster than 50.85%
Memory Usage: 40.9 MB, less than 71.19%
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
    def minimumDifference(self, nums: List[int]) -> int:
        max_heap, min_heap, sz = nums[:len(nums) // 3].copy(), nums[len(nums) * 2 // 3:].copy(), len(nums)
        presum, postsum, res = sum(nums[:sz // 3]), sum(nums[sz * 2 // 3:]), [0 for _ in range(sz // 3 + 1)]
        res[0], res[-1] = presum, -postsum
        for i in range(len(max_heap)):
            max_heap[i] *= -1
        heapify(max_heap)
        heapify(min_heap)
        for i in range(sz // 3):
            presum += nums[sz // 3 + i]
            heappush(max_heap, -nums[sz // 3 + i])
            cur_max = heappop(max_heap)
            presum += cur_max
            res[i + 1] += presum
            postsum += nums[sz * 2 // 3 - 1 - i]
            heappush(min_heap, nums[sz * 2 // 3 - 1 - i])
            cur_min = heappop(min_heap)
            postsum -= cur_min
            res[sz // 3 - 1 - i] -= postsum

        return min(res)


if __name__ == "__main__":
    s = Solution()
    nums = [3, 1, 2]
    res = s.minimumDifference(nums)
