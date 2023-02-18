"""
Source: https://leetcode.com/problems/defanging-an-ip-address/
Date: 2023/2/18
Skill:
Runtime: 28 ms, faster than 84.14%
Memory Usage: 13.8 MB, less than 40.59%
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
    def defangIPaddr(self, address: str) -> str:
        return address.replace(".", "[.]")



if __name__ == "__main__":
    s = Solution