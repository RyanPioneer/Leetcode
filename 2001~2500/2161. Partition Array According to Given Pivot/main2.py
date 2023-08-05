"""
Source: https://rb.gy/c17vb
Date: 2023/8/5
Skill:
Runtime: 1097 ms, faster than 97.16%
Memory Usage: 33.52 MB, less than 52.70%
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
        left, right, cnt = [], [], 0
        for num in nums:
            if num < pivot:
                left.append(num)
            elif num == pivot:
                cnt += 1
            else:
                right.append(num)
        return left + [pivot for _ in range(cnt)] + right


if __name__ == "__main__":
    s = Solution()
