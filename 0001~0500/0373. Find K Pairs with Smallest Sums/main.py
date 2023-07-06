"""
Source: https://rb.gy/dcxiw
Date: 2023/7/5
Skill:
Ref:
Runtime: 79 ms, faster than 72.43%
Memory Usage: 17.4 MB, less than 69.22%
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
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        def countSmallerOrEqual(num):
            idx2, cnt, size2 = len(nums2) - 1, 0, len(nums2)
            for idx1 in range(len(nums1)):
                num1 = nums1[idx1]
                while idx2 >= 0 and nums2[idx2] > num - num1:
                    idx2 -= 1
                cnt += idx2 + 1
            return cnt

        lower_bound, upper_bound = nums1[0] + nums2[0], nums1[-1] + nums2[-1]
        while lower_bound < upper_bound:
            mid = (lower_bound + upper_bound) // 2
            cnt = countSmallerOrEqual(mid)
            if cnt < k:
                lower_bound = mid + 1
            else:
                upper_bound = mid
        res = []
        for idx1 in range(len(nums1)):
            num1 = nums1[idx1]
            for idx2 in range(len(nums2)):
                num2 = nums2[idx2]
                if num1 + num2 < lower_bound:
                    res.append([num1, num2])
                else:
                    break

        for idx1 in range(len(nums1)):
            num1 = nums1[idx1]
            for idx2 in range(len(nums2)):
                if len(res) == k:
                    return res
                num2 = nums2[idx2]
                if num1 + num2 < lower_bound:
                    continue
                elif num1 + num2 == lower_bound:
                    res.append([num1, num2])
                else:
                    break

        return res


if __name__ == "__main__":
    s = Solution()
    nums1, nums2, k = [1, 1, 2], [1, 2, 3], 2
    res = s.kSmallestPairs(nums1, nums2, k)
    for i in res:
        print(i[0], i[1])
