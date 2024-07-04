# https://leetcode.com/problems/clone-n-ary-tree/description/

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':
        return self.clone(root)

    def clone(self, root):
        if not root:
            return None

        cloned = Node(root.val)

        if root.children:
            cloned.children = []

            for child in root.children:
                cloned.children.append(self.clone(child))

        return cloned