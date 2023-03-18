"""
Source: https://leetcode.com/problems/flood-fill/
Date: 2023/3/17
Skill:
Runtime: 82 ms, faster than 42.1%
Memory Usage: 13.9 MB, less than 85.18%
Time complexity:
Space complexity:
Constraints:

"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if color == image[sr][sc]:
            return image
        m, n = len(image), len(image[0])
        original_color = image[sr][sc]
        directions = [0, 1, 0, -1, 0]
        q = deque([(sr, sc)])
        image[sr][sc] = color

        def check_feasible(x, y):
            return 0 <= x < m and 0 <= y < n

        while q:
            cur_x, cur_y = q.popleft()
            for i in range(len(directions) - 1):
                next_x, next_y = cur_x + directions[i], cur_y + directions[i + 1]
                if not check_feasible(next_x, next_y) or \
                        image[next_x][next_y] != original_color:
                    continue
                image[next_x][next_y] = color
                q.append((next_x, next_y))

        return image


if __name__ == "__main__":
    s = Solution()
