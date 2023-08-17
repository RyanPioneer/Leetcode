"""
Source: https://rb.gy/wqplj
Date: 2023/8/17
Skill:
Ref:
Runtime: 5946 ms, faster than 15.00%
Memory Usage: 18.57 MB, less than 77.50%
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
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        sz, total, adj, res = len(nums), 0, [set() for _ in range(len(nums))], sys.maxsize
        for num in nums:
            total ^= num

        for edge in edges:
            adj[edge[0]].add(edge[1])
            adj[edge[1]].add(edge[0])

        def find_sum(root):
            visited = [False for _ in range(sz)]
            num, q = 0, deque([root])
            visited[root] = True
            while q:
                cur = q.popleft()
                num ^= nums[cur]
                for next in adj[cur]:
                    if not visited[next]:
                        visited[next] = True
                        q.append(next)
            return num

        def dfs(cur, parent, one_sum, two_sum):
            nonlocal res
            cur_sum = nums[cur]
            for next in adj[cur]:
                if next != parent:
                    num = dfs(next, cur, one_sum, two_sum)
                    cur_sum ^= num
                    res = min(res, max(one_sum, num, two_sum ^ num) - min(one_sum, num, two_sum ^ num))
            return cur_sum

        def helper(one, two):
            adj[one].remove(two)
            one_sum = find_sum(one)
            adj[one].add(two)
            two_sum = total ^ one_sum
            dfs(two, one, one_sum, two_sum)

        for edge in edges:
            helper(edge[0], edge[1])
            helper(edge[1], edge[0])
        return res


if __name__ == "__main__":
    s = Solution()

