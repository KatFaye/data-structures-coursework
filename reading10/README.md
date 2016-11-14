Reading 10
==========

1. A) Linear ordering of vertices so that for ever directed edge uv, u comes before v in the ordering. Real life application in resolving dependencies, such as with Makefiles.

B) The shortest path from a vertex v to all other vertices on the graph. Real life application in giving directions from one location to another (Google Maps).

C) Subset of edges connecting all vertices with the minimum amount of edges. Real life application in networking and laying out cables to connect all buildings in a neighborhood.

2. A) Yes, because you can start from a different node.

B) Yes, because there can be multiple distinct paths with the same length.

C) Yes, for example if all the edge weights are a given graph are the same, then every spanning tree of the graph is a minimum.

3. A) Graph 1: B, A, D, E, C

Graph 2: A, C, B, D, E, F

Graph 3: A, C, D, E, B

B) (B, D) (D, E) (C, E) (B, A)

Graph 2: (A, B) (B, D) (D, F) (D, E) (A, C)

Graph 3: (A, B) (D, E) (A, C) (C, B)

C) Graph 1: (B, D) (D, E) (C, E) (B, A)

Graph 2: (A, B) (B, C) (C, D) (D, E) (D, F)

Graph 3: (C, E) (C, B) (B, A) (C, E) (D, E)
