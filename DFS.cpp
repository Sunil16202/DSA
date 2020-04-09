#include <iostream>
using namespace std;

void DFS(int ** edges, int n, int startingVertex, bool * visited){
	cout<<startingVertex;
	cout<<" ";
	visited[startingVertex] = true;
	for(int i=0; i<n; i++){
		if(i == startingVertex){
			continue;
		}
		if(edges[startingVertex][i] == 1){
			if(visited[i]){
				continue;
			}
			DFS(edges,n,i,visited);
		}
	}
}


int main(){
	int n;
	int e;
	cin >> n >> e;
	int ** edges = new int*[n];
	for(int i=0; i<n; i++){
		edges[i] = new int [n];
		for(int j=0; j<n; j++){
			edges[i][j] = 	0;
		}
	}
	for(int i=0; i<e; i++){
		int f,s;
		cin >> f>> s;
		edges[f][s] = 1;
		edges[s][s] = 1;
	}
	bool * visited = new bool[n];
	for(int i=0; i<n; i++){
		visited[i] = false;
	}

	DFS(edges,n,0,visited);
}