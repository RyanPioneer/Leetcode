"""
Source: https://leetcode.com/problems/gas-station/
Date: 2023/1/7
Skill:
Ref:
Runtime: 728 ms, faster than 70.56%
Memory Usage: 19.3 MB, less than 49.17%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        start, local_sum, total_sum = 0, 0, 0
        for index in range(len(gas)):
            total_sum += gas[index] - cost[index]
            local_sum += gas[index] - cost[index]
            if local_sum < 0:
                local_sum = 0
                start = index+1

        return -1 if total_sum < 0 else start
