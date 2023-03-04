"""
Source: https://leetcode.com/problems/find-k-closest-elements/
Date: 2023/3/4
Skill:
Runtime: 293 ms, faster than 86.18%
Memory Usage: 15.5 MB, less than 75.78%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        low, high, res = 0, len(arr) - k, []
        while low < high:
            mid = (low + high) // 2
            if x - arr[mid] > arr[mid + k] - x:
                low = mid + 1
            else:
                high = mid

        for i in range(k):
            res.append(arr[low + i])

        return res


if __name__ == "__main__":
    s = Solution()
