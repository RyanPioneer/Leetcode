"""
Source: https://rb.gy/h3fmu
Date: 2023/7/14
Skill:
Ref:
Runtime: 1140 ms, faster than 15.73%
Memory Usage: 36.18 MB, less than 11.32%
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
    def makeSubKSumEqual(self, arr: List[int], k: int) -> int:
        visited, sz, res = set(), len(arr), 0
        for i in range(k):
            num, nums = i, []
            while num not in visited:
                visited.add(num)
                nums.append(arr[num])
                num = (num + k) % sz

            nums.sort()
            length = len(nums)
            for j in range(length):
                res += abs(nums[j] - nums[length // 2])

        return res


if __name__ == "__main__":
    s = Solution()
    arr, k = [1, 4, 1, 3], 2
    res = s.makeSubKSumEqual(arr, k)
