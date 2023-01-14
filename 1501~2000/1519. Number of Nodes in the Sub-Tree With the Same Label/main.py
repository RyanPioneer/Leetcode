"""
Source: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
Date: 2023/1/13
Skill:
Ref:
Runtime: 2442 ms, faster than 84.25%
Memory Usage: 197.9 MB, less than 34.93%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 10^5
"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        graph, res = defaultdict(list), [0 for _ in range(n)]
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        def post_order(root, parent):
            label_num = [0 for _ in range(26)]
            for child in graph[root]:
                if child != parent:
                    child_label_num = post_order(child, root)
                    for i in range(26):
                        label_num[i] += child_label_num[i]

            label_num[(ord(labels[root]) - ord('a'))] += 1
            res[root] = label_num[(ord(labels[root]) - ord('a'))]
            return label_num

        post_order(0, -1)
        return res







