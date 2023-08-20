"""
Source: https://rb.gy/i9heb
Date: 2023/8/20
Skill:
Runtime: 384 ms, faster than 76.84%
Memory Usage: 43.61 MB, less than 25.99%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        group_in_order, group_members, indegree = defaultdict(list), defaultdict(set), [0 for _ in range(n)]
        for i in range(len(group)):
            if group[i] == -1:
                group[i] = m
                m += 1
            group_members[group[i]].add(i)
            for neighbor in beforeItems[i]:
                if group[i] == group[neighbor]:
                    indegree[i] += 1
                    group_in_order[neighbor].append(i)

        def topology_sort(group_id):
            res, q = [], deque()
            for member in group_members[group_id]:
                if indegree[member] == 0:
                    q.append(member)
            while q:
                cur = q.popleft()
                res.append(cur)
                for next_pos in group_in_order[cur]:
                    indegree[next_pos] -= 1
                    if indegree[next_pos] == 0:
                        q.append(next_pos)

            if len(res) < len(group_members[group_id]):
                return []
            else:
                return res

        group_list = [[] for _ in range(m)]
        for i in range(m):
            if len(group_members[i]) > 0:
                sorted_list = topology_sort(i)
                if not sorted_list:
                    return []
                group_list[i] = sorted_list

        group_relation, indegree = defaultdict(list), [0 for _ in range(m)]
        for i in range(n):
            for neighbor in beforeItems[i]:
                if group[i] != group[neighbor]:
                    indegree[group[i]] += 1
                    group_relation[group[neighbor]].append(group[i])

        group_order, q = [], deque()
        for i in range(m):
            if indegree[i] == 0:
                q.append(i)
        while q:
            cur = q.popleft()
            group_order.append(cur)
            for next_group in group_relation[cur]:
                indegree[next_group] -= 1
                if indegree[next_group] == 0:
                    q.append(next_group)

        if len(group_order) < m:
            return []
        res = []
        for i in range(len(group_order)):
            group_id = group_order[i]
            res += group_list[group_id]
        return res


if __name__ == "__main__":
    s = Solution()
    n, m, group, beforeItems = 8, 2, [-1, -1, 1, 0, 0, 1, 0, -1], [[], [6], [5], [6], [3, 6], [], [], []]
    res = s.sortItems(n, m, group, beforeItems)
    print(res)
