"""
Source: https://rb.gy/3jygh
Date: 2023/8/4
Skill:
Ref:
Runtime: 36 ms, faster than 100.00%
Memory Usage: 16.35 MB, less than 58.11%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        presum, nums, res, sz = 0, defaultdict(list), 0, len(arr)
        nums[0].append(-1)
        for i in range(sz):
            presum ^= arr[i]
            if presum in nums:
                for idx in nums[presum]:
                    res += i - idx - 1
            nums[presum].append(i)
        return res


if __name__ == "__main__":
    s = Solution()
