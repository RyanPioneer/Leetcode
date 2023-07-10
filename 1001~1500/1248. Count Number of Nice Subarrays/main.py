"""
Source: https://rb.gy/7ktyx
Date: 2023/7/10
Skill:
Ref:
Runtime: 804 ms, faster than 74.75%
Memory Usage: 24 MB, less than 37.13%
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
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        left, right, sz, odd_num, res = 0, 0, len(nums), 0, 0
        while right < sz:
            while right < sz and odd_num < k:
                if nums[right] % 2 == 1:
                    odd_num += 1
                right += 1
            if odd_num == k:
                left_num, right_num = 1, 1
                while right < sz and nums[right] % 2 == 0:
                    right += 1
                    right_num += 1
                while nums[left] % 2 == 0:
                    left += 1
                    left_num += 1
                left += 1
                odd_num -= 1
                res += left_num * right_num
        return res


if __name__ == "__main__":
    s = Solution()
