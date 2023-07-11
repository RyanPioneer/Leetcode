"""
Source: https://rb.gy/t1mzg
Date: 2023/7/11
Skill:
Ref:
Runtime: 551 ms, faster than 37.90%
Memory Usage: 20.3 MB, less than 6.94%
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
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        sz = len(nums)
        def subarrays_with_at_most_p_distinct(p):
            myset, mydict, left, right, res = set(), defaultdict(int), 0, 1, 0
            myset.add(nums[0])
            mydict[nums[0]] = 1
            while right <= sz:
                while len(myset) > p:
                    mydict[nums[left]] -= 1
                    if mydict[nums[left]] == 0:
                        myset.remove(nums[left])
                    left += 1
                res += right - left
                if right == sz:
                    break
                mydict[nums[right]] += 1
                myset.add(nums[right])
                right += 1
            return res

        return subarrays_with_at_most_p_distinct(k) - subarrays_with_at_most_p_distinct(k-1)



if __name__ == "__main__":
    s = Solution()
