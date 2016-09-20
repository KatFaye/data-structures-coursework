Reading 04
==========

1. Merge sort 
Divide: list is split down the middle into to sub-lists

Conquer: Each sub-list is sorted by 
recursively calling merge sort on each 
half of the list. The sorted lists are 
then merged into a single sorted list.

2. Quick Sort
Parition: Split the array into two parts 
based on a pivot element. This pivot 
element is then used to rearrage the 
array such that said element is in it's 
final place, no element below it is 
greater than it, and no element behind it 
is less than the element.

The pivot choice is important because it 
determines the size of the partitions, 
and the relative amount of swaps that 
will be needed.

3. Stable sorting algorithms always 
preserve the relative order of elements 
with equal keys.

This can allow you to go through multiple 
sorting conditions and preserve the 
relative orders.

Quick sort does not preserve this 
ordering, so is not stable, while merge 
sort does with most implementations, so 
it is stable.

4. Quicksort:
Best: nlog(n)
Average: nlog(n)
Worst: n^2

Mergesort:
Best: nlog(n)
Average: nlog(n)
Worst: nlog(n)

Quick sort has better space complexity, 
since it uses in-place sorting and no 
additional space is required for the sorting.