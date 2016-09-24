Reading 05
==========

1. Binary search trees must be sorted; heaps just require nodes to be always less than (for a min heap) or greater than (for a max heap) their children.

Yes, because a heap could happe to be in sorted order and also be a binary search tree.

2. I would do an in-order recursive traversal of the binary  search tree. The complexity of this would be O(n).

3. Search: Average- O(log(n)) Worst- O(n)
Insertion: Average- O(log(n)) Worst- O(n)
Removal: Average- O(log(n)) Worst- O(n)

If the nodes are in order, then the tree essentially degenerates to a linked list, making the worst-case scenario longer.

4. B-trees can have more than two children, and are ideal for large databases since they are optimized for systems that read/write large blocks of data.
