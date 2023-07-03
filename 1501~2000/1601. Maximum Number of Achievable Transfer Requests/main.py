"""
Source: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
Date: 2023/7/2
Skill:
Ref:
Runtime: 5934 ms, faster than 8.74%
Memory Usage: 16.4 MB, less than 81.55%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        request_num, max_num = len(requests), 0

        def check_feasible(bitmask):
            net, num = [0 for _ in range(n)], 0
            for i in range(request_num):
                bit = bitmask & (1 << i)
                if bit:
                    net[requests[i][0]] -= 1
                    net[requests[i][1]] += 1
                    num += 1
            for i in range(n):
                if net[i] != 0:
                    return 0
            return num

        for i in range(1, 2 ** request_num):
            max_num = max(max_num, check_feasible(i))

        return max_num


if __name__ == "__main__":
    s = Solution()
