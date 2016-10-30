Reading 08
==========

1. If a collision is found, then the insertion point is incremented by 1 (or some other value) if linear probing is being used until an empty bucket is found into which the value can be inserted.

2. N/K, where n is the number of entries and K is the number of buckets. The larger the number, the slower the hash table is (or it might not even work). More memory is also used the larger this number is.

3. 
0 - 68
1 - 14
2 - 2
3 - 3
4 - 72
5 - 13
6 - 56
7 - 7
8 - 78
9 - 79

4. Search - Average: O(1); worst: O(n)
Insert - Average: O(1); worst: O(n)
Remove - Average: O(1); Worst: O(n)

In the worst case, you will have to traverse the entire hash table to find the item you are looking for, or an empty space to insert.

