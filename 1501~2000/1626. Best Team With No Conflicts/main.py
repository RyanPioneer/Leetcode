"""
Source: https://leetcode.com/problems/best-team-with-no-conflicts/
Date: 2023/1/31
Skill: Dynamic Programming
Runtime: 3226 ms, faster than 26.24%
Memory Usage: 14.1 MB, less than 83.69%
Time complexity:
Space complexity:
Constraints:
    1 <= scores.length, ages.length <= 1000
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        def compare(x, y):
            if ages[x] < ages[y] or (ages[x] == ages[y] and scores[x] <= scores[y]):
                return -1
            else:
                return 1

        nums, sz = [i for i in range(len(scores))], len(scores)
        sorted_nums = sorted(nums, key=functools.cmp_to_key(compare))
        dp = [scores[sorted_nums[i]] for i in range(sz)]
        for i in range(1, sz):
            for j in range(i):
                if (ages[sorted_nums[j]] == ages[sorted_nums[i]] or
                        scores[sorted_nums[j]] <= scores[sorted_nums[i]]):
                    dp[i] = max(dp[i], dp[j]+scores[sorted_nums[i]])

        return max(dp)

if __name__ == '__main__':
    s = Solution
    scores, ages = [1,1,1,1,1,1,1,1,1,1], [811,364,124,873,790,656,581,446,885,134]
    res = s.bestTeamScore(s, scores, ages)