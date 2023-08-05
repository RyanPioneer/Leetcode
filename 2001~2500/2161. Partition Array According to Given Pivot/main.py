"""
Source: https://rb.gy/c17vb
Date: 2023/8/5
Skill:
Runtime: 1181 ms, faster than 89.49%
Memory Usage: 34.04 MB, less than 10.65%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less_num, equal_num, sz = 0, 0, len(nums)
        for i in range(sz):
            if nums[i] < pivot:
                less_num += 1
            elif nums[i] == pivot:
                equal_num += 1

        idx1, idx2, idx3, res = 0, less_num, less_num + equal_num, [0 for _ in range(sz)]
        for num in nums:
            if num < pivot:
                res[idx1] = num
                idx1 += 1
            elif num == pivot:
                res[idx2] = num
                idx2 += 1
            else:
                res[idx3] = num
                idx3 += 1
        return res


if __name__ == "__main__":
    s = Solution()
