// Challenge 09: Graph Paths

#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Main Execution
map<char, vector<char>> makeGraph(int nEdges) {
	char src, dest;
	map<char, vector<char>> graph;
	for(int i=0; i<nEdges; i++) {
		vector<char> destination;
		cin >> src >> dest;
		destination.push_back(dest);
		
		auto search = graph.find(src);
		if(search == graph.end()) { //if src not already in map
			graph.insert(make_pair(src, destination));
		} else {
			search->second.push_back(dest);
		}
	}
	return graph;
}
bool findPath(map<char, vector<char>> graph, char src, char dest) {
	
	stack<char> frontier;
	vector<char> marked;
	vector<char> path;
	auto search = graph.find(src);
	
	if(search==graph.end()) { //source is not in the graph
		return false;
	} else { //source is in graph, depth-first search*/
		marked.push_back(src);
		path.push_back(src);
		for(auto el : graph[src])
			frontier.push(el);
		while(!frontier.empty()) {
			char n = frontier.top();
			frontier.pop();
			path.push_back(n);
			auto s = find(marked.begin(), marked.end(), n);
			if(s != marked.end()) {
				//in marked
				continue;
			} else {
				marked.push_back(n);
				for(auto i : graph[n]) {
					frontier.push(i);
				}
			}
		}

	}
	auto check = find(path.begin(), path.end(), src);
	auto isPath = find(check, path.end(), dest);
	if(isPath != path.end())
		return true;

	//no path found; default
	return false;
}
int main(int argc, char *argv[]) {

	int nEdges, nPaths, nGraph = 0;
	char src, dest;
	bool first = true;

	while(cin >> nEdges) {
		//get edges to build adjacency list
		if(!first)
			cout << endl;
		nGraph++;
		auto graph = makeGraph(nEdges);
		cin >> nPaths;
		for(int i=0; i<nPaths; i++) {
			cin >> src >> dest;
			bool isPath = findPath(graph, src, dest);
			string output = isPath ? " is a" : " is no";
			cout << "In Graph " << nGraph << " there" << output << " path from " << src << " to " << dest << endl;
		}
		first = false;

		
	}
    return EXIT_SUCCESS;

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
