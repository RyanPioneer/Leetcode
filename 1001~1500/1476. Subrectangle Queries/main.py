"""
Source: https://rb.gy/ftxv2
Date: 2023/7/21
Skill:
Ref:
Runtime: 203 ms, faster than 35.33%
Memory Usage: 18.3 MB, less than 86.50%
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


class SubrectangleQueries:

    def __init__(self, rectangle: List[List[int]]):
        self.rectangle = rectangle

    def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int, newValue: int) -> None:
        for i in range(row1, row2 + 1):
            for j in range(col1, col2 + 1):
                self.rectangle[i][j] = newValue

    def getValue(self, row: int, col: int) -> int:
        return self.rectangle[row][col]


# Your SubrectangleQueries object will be instantiated and called as such:
# obj = SubrectangleQueries(rectangle)
# obj.updateSubrectangle(row1,col1,row2,col2,newValue)
# param_2 = obj.getValue(row,col)


if __name__ == "__main__":
    s = Solution()

