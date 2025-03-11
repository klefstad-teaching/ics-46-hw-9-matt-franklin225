#include "dijkstras.h"
using namespace std;

int main(){
	Graph G;
	file_to_graph("small.txt", G);
	vector<int> shortest_path = dijkstra_shortest_path(G, 0, vector<int>(G.numVertices, -1));
	print_path(shortest_path);
}