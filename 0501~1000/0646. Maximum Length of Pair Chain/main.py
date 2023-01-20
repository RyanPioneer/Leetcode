"""
Source: https://leetcode.com/problems/maximum-length-of-pair-chain/description/
Date: 2023/1/20
Skill: Greedy
Ref:
Runtime: 208 ms, faster than 92.41%
Memory Usage: 14.3 MB, less than 98.98%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key = lambda x: x[0])
        cur_idx, res = 0, 0
        for idx in range(1, len(pairs)):
            if pairs[cur_idx][1] < pairs[idx][0]:
                res += 1
                cur_idx = idx
            elif pairs[cur_idx][1] > pairs[idx][1]:
                cur_idx = idx

        return res+1