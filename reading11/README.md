Reading 11
==========

1. Provide a scalable distributed file system for large distributed data-intensive applications. 

It solves this problem by having a single master and multiple chunkservers that are accessed by multiple clients. 

Data is stored in chunks with a unique chunk handle and metadata stored in memory for fast master operations. Chunks are replicated on multiple chunkservers.

Data structures used might include a map, with the chunk handle serving as the key, or a hash table, with the chunk handle as the result of the hash function.

2. MapReduce is used to process and generate large data sets.

It uses a map function which processes a key/value pair to generate a set of intermediate key/value pairs, and a reduec function to merge those intermediate values. Programs are automatically parallelized.

Map phase - parses key value pairs and passes pair to Map function; intermediate key/value pairs produced by this buffered into memory

Reduce phase - reads buffered data and sorts it by intermediate keys, then iterates over data and passes key and corresponding set of intermediate values to Reduce function for each unique key encountered

Output phase - The master wakes up the user program and returns back to the user code

Sorting algorithms are used, as well as maps. Parsing algorithms are also used.
