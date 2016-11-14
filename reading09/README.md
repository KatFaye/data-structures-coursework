Reading 09
==========

1. A) path between every vertices

B) No closed path

C) Edges directed from one vertex to another

D) Unweighted, undirected graph with no loops or multiple edges

E) numeric label associated with each edge

2. Graph 1:
 ABCD
A0101
B1000
C1000
D0111

A: B, D
B: A
C: A
D: C, D, B

Graph 2:
 ABCD
A0111
B1011
C1101
D1110

A: B, C, D
B: A, C, D
C: A, B, D
D: A, B, C

Graph 3:
 ABCD
A0000
B0001
C0001
D0110

B: D
D: C, B
C: D

B) Faster to look up if a specific edge exists

C) Uses less memory

3. 
v.insert(s);
for(auto el : graph[s])
	q.push(el);
while(!q.empty()) {
	char n = q.top();
	q.pop();
	cout << n;
	auto search = v.find(src);
	if(search != v.end()) {
		//in marked
		continue;
	} else {
		v.insert(n);
		for(auto i : graph[n]) {
			q.push(i);
		}
	}
}

B. Stores all edges to visit

C. Stores all edges already visited

D. Change the stack to a queue


