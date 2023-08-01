"""
Source: https://rb.gy/bc80o
Date: 2023/8/1
Skill:
Ref:
Runtime: 1756 ms, faster than 34.04%
Memory Usage: 16.34 MB, less than 84.04%
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
    def getMinSwaps(self, num: str, k: int) -> int:
        def next_permutation(nums: List[int]) -> None:
            idx, idx2 = len(nums) - 1, len(nums) - 1
            while idx - 1 >= 0 and nums[idx] <= nums[idx - 1]:
                idx -= 1
            if idx == 0:
                nums.sort()
                return
            idx -= 1
            while nums[idx2] <= nums[idx]:
                idx2 -= 1
            nums[idx], nums[idx2] = nums[idx2], nums[idx]
            nums[idx + 1:] = sorted(nums[idx + 1:])

        num_list, res, sz = [], 0, len(num)
        for c in num:
            num_list.append(int(c))
        original_num_list = num_list.copy()
        for _ in range(k):
            next_permutation(num_list)
        for i in range(sz):
            num, idx = 0, 0
            while original_num_list[idx] != num_list[i]:
                if original_num_list[idx] != -1:
                    num += 1
                idx += 1
            res += num
            original_num_list[idx] = -1

        return res


if __name__ == "__main__":
    s = Solution()
