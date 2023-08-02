"""
Source: https://rb.gy/uxomq
Date: 2023/8/2
Skill:
Ref:
Runtime: 1601 ms, faster than 44.35%
Memory Usage: 40.74 MB, less than 8.87%
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
    def numberOfPairs(self, nums1: List[int], nums2: List[int], diff_num: int) -> int:
        diff, sz, res = [], len(nums1), 0
        for i in range(sz):
            diff.append(nums1[i] - nums2[i])

        def helper(left, right):
            nonlocal res
            if left >= right:
                return
            mid = (left + right) // 2
            helper(left, mid)
            helper(mid + 1, right)
            idx = left
            for i in range(mid + 1, right + 1):
                while idx <= mid and diff[idx] <= diff[i] + diff_num:
                    idx += 1
                res += idx - left
            sorted_arr, idx1, idx2 = [], left, mid + 1
            while idx1 <= mid and idx2 <= right:
                if diff[idx1] <= diff[idx2]:
                    sorted_arr.append(diff[idx1])
                    idx1 += 1
                else:
                    sorted_arr.append(diff[idx2])
                    idx2 += 1
            while idx1 <= mid:
                sorted_arr.append(diff[idx1])
                idx1 += 1
            while idx2 <= right:
                sorted_arr.append(diff[idx2])
                idx2 += 1
            diff[left: right + 1] = sorted_arr

        helper(0, sz - 1)
        return res


if __name__ == "__main__":
    s = Solution()
