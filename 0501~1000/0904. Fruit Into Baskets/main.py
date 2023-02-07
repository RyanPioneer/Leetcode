"""
Source: https://leetcode.com/problems/fruit-into-baskets/
Date: 2023/2/7
Skill: Sliding Window
Runtime: 875 ms, faster than 86.98%
Memory Usage: 20 MB, less than 80.52%
Time complexity:
Space complexity:
Constraints:
    1 <= fruits.length <= 10^5
    0 <= fruits[i] < fruits.length
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        left, right, sz = 0, 1, len(fruits)
        res, two_set, num2idx = 0, set(), {}
        two_set.add(fruits[0])
        num2idx[fruits[0]] = left
        while right < sz:
            if fruits[right] not in two_set:
                two_set.add(fruits[right])
                num2idx[fruits[right]] = right
                while right+1 < sz and fruits[right+1] in two_set:
                    right += 1
                    num2idx[fruits[right]] = right
                res = max(res, right-left+1)
                break
            else:
                num2idx[fruits[0]] = right
                right += 1

        if right == sz or right == sz-1:
            return sz

        while right < sz:
            target = sum(two_set) - fruits[right]
            two_set.remove(target)
            left = num2idx[target]+1
            two_set.add(fruits[right+1])
            while right+1 < sz and fruits[right+1] in two_set:
                right += 1
                num2idx[fruits[right]] = right
            res = max(res, right - left + 1)
            if right == sz-1:
                return res


if __name__ == "__main__":
    s = Solution
    fruits = [3,3,3,1,2,1,1,2,3,3,4]
    res = s.totalFruit(s, fruits)
    print(res)