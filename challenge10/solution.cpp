// Challenge 10: Minimum Spanning Tree

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {
    int size;
    bool first = true;

    while(cin>>size) {
    	//get input
    	vector<pair<char, char>> mst;
    	int graph[size][size] = {0};
    	for(int i=0;i<size;i++) {
    		for(int j=0;j<size;j++) {
    			cin >> graph[i][j];
    			if(graph[i][j]==-1) { //no path
    				graph[i][j] = INT_MAX;
    			}
    		}
    	}
        int marked[size] = {false};
        marked[0]=true;
        int inMST=0, tree = 0, x, y, min;


        while(inMST < size-1){
           min = INT_MAX;

           for(int i=0;i<size;i++) {
              if(marked[i]==true){
                 for(int j=0;j<size;j++){
                    if(marked[j]==false){
                       if(min > graph[i][j]) {
                           min = graph[i][j];
                           x = i;
                           y = j;
                       }
                    }
                }
              }
           }
           marked[y]=true;
           tree += graph[x][y];
           inMST++;
           if(x<y) {
                mst.push_back(make_pair(x + 'A', y + 'A'));
           } else {
                mst.push_back(make_pair(y + 'A', x + 'A'));
           }
           sort(mst.begin(), mst.end());
        }
        if(!first) {
            cout << endl;
        }
		cout << tree << endl; //size of mst
		for(auto p : mst) {
			cout << p.first << p.second << endl;
		}
		first = false;
    }
    return EXIT_SUCCESS;
}


// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
