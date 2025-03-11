#include "dijkstras.h"
using namespace std;

int main(){
	Graph G;
	file_to_graph("src/medium.txt", G);
	vector<int> prev;
	vector<int> shortest_path = dijkstra_shortest_path(G, 0, prev);
	print_path(shortest_path, shortest_path.size());
}