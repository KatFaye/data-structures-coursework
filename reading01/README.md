Reading 01
==========

1. Since templates are generalized, they can 
allow data structures to be implemented with 
any type, allowing for standardized 
functionalities without requiring code to be 
rewritten. Templates are useful in 
implementing standard constructs, or data 
structures, such as vectors, for such reasons.

2. The class is missing an assignment operator 
an a copy constructor. Since the destructor is 
non-empty, this is needed to prevent the 
program from attempting to deallocate the same 
memory locatino more than once when a copy of 
the program is made.

I would fix this using code similar to what 
was in the reading:
 Stack(const Stack& s):
      data(new T[s.size]),
      size(s.size) {
      std::copy(data, data + size, s.data);
   }
   Stack&
   operator=(const Stack& s) {
      int* newdata = new T[s.size];
      std::copy(s.data,s.data+s.size, newdata);
      delete[] data;
      data = newdata;
      size = s.size;
      return *this;
   }

3. a) O(1)
b) O(n)
c) O(n)

A vector's size is how many elements are 
currently stored in a vector; the capacity is 
the maximum number of elements current able to 
be stored in the vector without re-sizing it.

4. Locate: O(n)
Insert in back: O(1)
Insert in front: O(1)

Using a singly or doubly linked list does not 
effect the big-O complexity of these operations.