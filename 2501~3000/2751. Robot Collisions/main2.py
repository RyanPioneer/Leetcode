"""
Source: https://rb.gy/di0sp
Date: 2023/7/8
Skill:
Ref:
Runtime: 1414 ms, faster than 57.31%
Memory Usage: 37.7 MB, less than 84.78%
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
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        order, stack, res = [i for i in range(len(positions))], [], []
        order.sort(key=lambda x: positions[x])
        for i in order:
            if directions[i] == "L":
                flag = True
                while len(stack) > 0 and directions[stack[-1][0]] == "R":
                    if stack[-1][1] > healths[i]:
                        stack[-1][1] -= 1
                        flag = False
                        break
                    elif stack[-1][1] < healths[i]:
                        stack.pop()
                        healths[i] -= 1
                    else:
                        stack.pop()
                        flag = False
                        break
                if flag:
                    stack.append([i, healths[i]])
            else:
                stack.append([i, healths[i]])

        stack.sort(key=lambda x: x[0])
        for i in range(len(stack)):
            res.append(stack[i][1])
        return res


if __name__ == "__main__":
    s = Solution()

