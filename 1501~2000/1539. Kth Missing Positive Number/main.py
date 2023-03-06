"""
Source: https://leetcode.com/problems/kth-missing-positive-number/
Date: 2023/3/6
Skill:
Runtime: 48 ms, faster than 88.93%
Memory Usage: 13.9 MB, less than 80.43%
Time complexity:
Space complexity:
Constraints:
    1 <= arr.length <= 1000
    1 <= arr[i] <= 1000
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
    def findKthPositive(self, arr: List[int], k: int) -> int:
        cur_num = 0
        for num in arr:
            if num - cur_num > k:
                return cur_num + k
            else:
                k -= num - cur_num - 1
                cur_num = num
        return cur_num + k


if __name__ == "__main__":
    s = Solution()
