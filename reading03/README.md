Reading 03
==========

1. Max-heap: the value of each node is lteq the value of its parent.

A is a maximum binary heap, but B and C are not because in both cases, the largest value is not the root node.

2. O(log(n)) - Reheapification is done to ensure that the binary heap is still in sorted order.

3. Selection soft of {9, 6, 0, 0, 7}
0, 9, 6, 0, 7
0, 0, 9, 6, 7
0, 0, 6, 9, 7
0, 0, 6, 7, 9


4. Insertion sort of {9, 6, 0, 0, 7}
6, 9, 0, 0, 7
0, 6, 9, 0, 7
0, 0, 6, 9, 7
0, 0, 6, 7, 9
