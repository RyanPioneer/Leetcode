class SegmentTreeNode:
    def __init__(self, start, end, val, max_val=None, left=None, right=None):
        self.start = start
        self.end = end
        self.mid = (start + end) // 2
        self.val = val
        self.max_val = max_val
        self.left = left
        self.right = right


class SegmentTree:
    def __init__(self, nums):
        self.n = len(nums)
        self.nums = nums
        self.root = self.build_tree(0, self.n - 1)

    def build_tree(self, start, end):
        if start == end:
            return SegmentTreeNode(start, end, self.nums[start], self.nums[start])
        mid = (start + end) // 2
        left_sub_tree = self.build_tree(start, mid)
        right_sub_tree = self.build_tree(mid + 1, end)
        return SegmentTreeNode(start, end, left_sub_tree.val + right_sub_tree.val,
                               max(left_sub_tree.max_val, right_sub_tree.max_val),
                               left_sub_tree, right_sub_tree)

    def update_delta(self, node, idx, delta):
        if node.start == idx and node.end == idx:
            node.val += delta
            node.max_val += delta
        elif idx <= node.mid:
            node.val -= node.left.val
            self.update_delta(node.left, idx, delta)
            node.val += node.left.val
            node.max_val = max(node.left.max_val, node.right.max_val)
        else:
            node.val -= node.right.val
            self.update_delta(node.right, idx, delta)
            node.val += node.right.val
            node.max_val = max(node.left.max_val, node.right.max_val)

    def query_range_sum(self, node, start, end):
        if node.start == start and node.end == end:
            return node.val
        elif end <= node.mid:
            return self.query_range_sum(node.left, start, end)
        elif start > node.mid:
            return self.query_range_sum(node.right, start, end)
        else:
            return self.query_range_sum(node.left, start, node.mid) + self.query_range_sum(node.right, node.mid + 1, end)

    def query_range_max(self, node, start, end):
        if node.start == start and node.end == end:
            return node.max_val
        elif end <= node.mid:
            return self.query_range_max(node.left, start, end)
        elif start > node.mid:
            return self.query_range_max(node.right, start, end)
        else:
            return max(self.query_range_max(node.left, start, node.mid), self.query_range_max(node.right, node.mid + 1, end))
