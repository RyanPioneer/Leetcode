"""
Source: https://leetcode.com/problems/simplify-path/
Date: 2023/4/12
Skill:
Ref:
Runtime: 27 ms, faster than 94.52%
Memory Usage: 14.1 MB, less than 5.75%
Time complexity:
Space complexity:
Constraints:
    1 <= path.length <= 3000
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def simplifyPath(self, path: str) -> str:
        path_list, q, res = path.split("/"), deque(), ""
        for i in path_list:
            if i == ".." and q:
                q.pop()
            elif i != "" and i != ".." and i != ".":
                q.append(i)

        while q:
            directory = q.popleft()
            res += "/" + directory

        return res if len(res) > 0 else "/"


if __name__ == "__main__":
    s = Solution()
