#include <iostream>
#include<iostream>
#include<queue>
using namespace std;
void BFS(int ** edges,int n, bool * visited,int sv){
	queue<int> pendingVertices;
	
	pendingVertices.push(sv);
	visited[sv] = true;
	while(!pendingVertices.empty()){
		int currentVertex = pendingVertices.front();
		pendingVertices.pop();
		cout<<currentVertex<<" ";

		for(int i=0; i<n; i++){
			if(currentVertex == i){
				continue;
			}
			if(edges[currentVertex][i] == 1 && !visited[i]){
				pendingVertices.push(i);
				visited[i]  = true;
			}
		}
	}
}

void SearchBFS(int ** edges, int n){
    bool * visited = new bool[n];
	for(int i=0; i<n; i++){
		visited[i] = false;
	}
    for(int i=0; i<n;i++){
        if(!visited[i]){
            BFS(edges,n,visited,i);
        }
    }
    
}

int main() {
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
		edges[s][f] = 1;
	}
	

	SearchBFS(edges,n);

	for(int i=0; i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
}