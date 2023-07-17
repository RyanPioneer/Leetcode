"""
Source: https://rb.gy/318du
Date: 2023/7/17
Skill: Merge sort
Ref:
Runtime: 3217 ms, faster than 53.31%
Memory Usage: 104.18 MB, less than 5.22%
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
    def countSmaller(self, nums: List[int]) -> List[int]:
        sorted_nums, sz, cnt = list(enumerate(nums)), len(nums), [0 for _ in range(len(nums))]

        def divide_and_conquer(left, right):
            if left >= right:
                return
            mid = (left + right) // 2
            divide_and_conquer(left, mid)
            divide_and_conquer(mid + 1, right)
            l, r, tmp = left, mid + 1, []
            while l <= mid and r <= right:
                if sorted_nums[l][1] <= sorted_nums[r][1]:
                    cnt[sorted_nums[l][0]] += r - (mid+1)
                    tmp.append(sorted_nums[l])
                    l += 1
                else:
                    tmp.append(sorted_nums[r])
                    r += 1
            while l <= mid:
                cnt[sorted_nums[l][0]] += r - (mid + 1)
                tmp.append(sorted_nums[l])
                l += 1
            while r <= right:
                tmp.append(sorted_nums[r])
                r += 1
            sorted_nums[left:right + 1] = tmp.copy()

        divide_and_conquer(0, sz - 1)
        return cnt


if __name__ == "__main__":
    s = Solution()

