"""
Source: https://rb.gy/xq8ty
Date: 2023/7/13
Skill:
Ref:
Runtime: 924 ms, faster than 61.64%
Memory Usage: 16.4 MB, less than 21.26%
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
        people, cookie_num, res = [0 for _ in range(k)], len(cookies), sys.maxsize
        cookies.sort(reverse=True)

        def dfs(cookie, zero_count):
            nonlocal res
            if cookie_num - cookie < zero_count:
                return
            if cookie == cookie_num:
                res = min(res, max(people))
                return
            for i in range(k):
                if people[i] == 0:
                    zero_count -= 1
                people[i] += cookies[cookie]
                dfs(cookie+1, zero_count)
                people[i] -= cookies[cookie]
                if people[i] == 0:
                    zero_count += 1

        dfs(0, k)
        return res


if __name__ == "__main__":
    s = Solution()
