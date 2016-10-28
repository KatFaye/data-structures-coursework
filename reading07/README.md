Reading 07
==========

1. Hash functions map data of an arbitrary size to data of a fixed size. They detect duplicate records.

2. A collision is when two distinct piece of data have the same hash value. In separate chaining, all keys that map to the same hash value are stored in a list (bucket).

3. Good hash function:
a) Determinism - given input always generates ame hash value
b) uniformity - every value should be generated with roughly the same probability
c) defined and variable range
d) continuous - two inputs that differ by little should map to equal/nearly equal hash values
e) non-invertible - can't reconstruct data from hash value alone

4. Complexity:
Search - average: O(1) worst: O(N)
Insert - average: O(1) worst: O(N)
Remove - average: O(1) worst: O(N)

In the worst case, all N items hash to the same list and you have to do a linear search of that list.
