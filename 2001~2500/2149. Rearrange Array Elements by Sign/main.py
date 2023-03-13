"""
Source: https://leetcode.com/problems/rearrange-array-elements-by-sign/
Date: 2023/3/13
Skill:
Runtime: 41 ms, faster than 34.65%
Memory Usage: 13.8 MB, less than 67.72%
Time complexity:
Space complexity:
Constraints:
    2 <= nums.length <= 2 * 10^5
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
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos, neg, cur, sz, flag = 0, 0, 0, len(nums), 1
        while cur < sz:
            if flag:
                if nums[cur] < 0:
                    pos = max(pos, cur + 1)
                    while nums[pos] < 0:
                        pos += 1
                    nums[cur], nums[pos] = nums[pos], nums[cur]
            else:
                if nums[cur] > 0:
                    neg = max(neg, cur + 1)
                    while nums[neg] > 0:
                        neg += 1
                    nums[cur], nums[neg] = nums[neg], nums[cur]

            cur += 1
            flag = (flag + 1) % 2

        return nums
        

if __name__ == "__main__":
    s = Solution()
