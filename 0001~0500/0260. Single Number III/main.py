"""
Source: https://leetcode.com/problems/single-number-iii/description/
Date: 2023/8/15
Skill:
Runtime: 63 ms, faster than 90.98%
Memory Usage: 18.02 MB, less than 74.46%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        res, diff = [0, 0], 0
        for num in nums:
            diff ^= num
        right_most = diff & (-diff)
        for num in nums:
            if num & right_most == 0:
                res[0] ^= num
            else:
                res[1] ^= num
        return res


if __name__ == "__main__":
    s = Solution()
