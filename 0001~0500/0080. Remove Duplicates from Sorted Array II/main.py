"""
Source: https://rb.gy/i3kz2
Date: 2023/7/29
Skill:
Ref:
Runtime: 60 ms, faster than 94.55%
Memory Usage: 16.41 MB, less than 17.52%
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
    def removeDuplicates(self, nums: List[int]) -> int:
        cur_idx, sz, idx = 0, len(nums), 0
        while idx < sz:
            if idx == sz - 1 or nums[idx] != nums[idx + 1]:
                nums[cur_idx] = nums[idx]
                cur_idx += 1
                idx += 1
            else:
                nums[cur_idx] = nums[cur_idx + 1] = nums[idx]
                cur_idx += 2
                idx += 2
                while idx < sz and nums[idx] == nums[idx - 1]:
                    idx += 1
        return cur_idx


if __name__ == "__main__":
    s = Solution()
