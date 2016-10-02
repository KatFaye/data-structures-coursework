Reading 06
==========

1. For two given nodes x and y where x is y's parent, y becomes x's parent and retains its original right subtree.

2. a) A node is either red or black.
b) if a node is red, then both its children are black
c) Every path from a given node to any of its descendant null nodes contains the same number of black nodes

3. A binary search is performed and a random priority is given for the new node, x's position in the tree. A new node is created as a leaf for where x should be placed, then a tree rotation is performed between x and its parent.

4.
Red-Black
search: Average- O(log(n)) Worst- O(log(n))
insert: Average- O(log(n)) Worst- O(log(n))
remove: Average- O(log(n)) Worst- O(log(n))

Treap:
Search: Average- O(log(n)) Worst- O(n)
Insert: Average- O(log(n)) Worst- O(n)
Remove: Average- O(log(n)) Worst- O(n)
Treap is not guaranteed to be balanced.