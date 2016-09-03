Reading 02
==========

1. Minimum height: O(log(n)) 
Maximum height: O(n)

2. [ R | O | G | U | E | O | N | E ]

This works best when the tree is a complete binary tree, since no space is waster in that case.

3. W, Y, R, D, B, I, O, F, U, L, A, R, A, E, D : breadth-first
Data structure used: queue - first-in, first-out, so I would add the nodes in breadth-order, then traverse the array in order left-to-right.

Depth first: W, Y, D, F, U, B, L, A, R, I, R, A, O, E, D
Data structure used: stack - Stacks are last in, first out, so I'd add the nodes to the stack bottom-right first, then when pop them off they're in depth-first traversal order.

4. struct Node {
    int          value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};


Benefits of using smart pointers include automatic destruectors/memory deallocation, and reference counting.
