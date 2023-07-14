"""
Source: https://rb.gy/xq8ty
Date: 2023/7/13
Skill:
Ref:
Runtime: 60 ms, faster than 85.22%
Memory Usage: 16.5 MB, less than 21.26%
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
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        people, cookie_num = [0 for _ in range(k)], len(cookies)
        cookies.sort(reverse=True)

        def dfs(cookie, limit, zero_count):
            if cookie == cookie_num:
                return True
            if cookie_num - cookie < zero_count:
                return False
            for i in range(k):
                if people[i] + cookies[cookie] <= limit:
                    if people[i] == 0:
                        zero_count -= 1
                    people[i] += cookies[cookie]
                    if dfs(cookie+1, limit, zero_count):
                        return True
                    people[i] -= cookies[cookie]
                    if people[i] == 0:
                        zero_count += 1
            return False

        lo, hi = 1, sum(cookies)
        while lo < hi:
            for i in range(k):
                people[i] = 0
            mid = (lo + hi) // 2
            if dfs(0, mid, k):
                hi = mid
            else:
                lo = mid + 1

        return lo


if __name__ == "__main__":
    s = Solution()
