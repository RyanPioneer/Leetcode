"""
Source: https://leetcode.com/problems/sort-an-array/
Date: 2023/3/1
Skill: Merge Sort
Ref:
Runtime: 1858 ms, faster than 56.78%
Memory Usage: 35.1 MB, less than 5.24%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 5 * 10^4
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge_sort(l, r):
            if l > r:
                return []
            elif l == r:
                return [nums[l]]
            else:
                sorted_left, sorted_right = merge_sort(l, (l+r)//2), merge_sort((l+r)//2+1, r)
                cur, left, right, left_size, right_size = l, 0, 0, (l+r)//2 - l + 1, r - (l+r)//2
                while left < left_size and right < right_size:
                    if sorted_left[left] <= sorted_right[right]:
                        nums[cur] = sorted_left[left]
                        cur += 1
                        left += 1
                    else:
                        nums[cur] = sorted_right[right]
                        cur += 1
                        right += 1

                while left < left_size:
                    nums[cur] = sorted_left[left]
                    cur += 1
                    left += 1

                while right < right_size:
                    nums[cur] = sorted_right[right]
                    cur += 1
                    right += 1

                return nums[l:r+1].copy()

        return merge_sort(0, len(nums)-1)


if __name__ == "__main__":
    s = Solution()
    nums = [5, 2, 3, 1]
    res = s.sortArray(nums)
    print(res)
