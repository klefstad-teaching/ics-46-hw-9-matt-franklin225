#include "dijkstras.h"
using namespace std;

struct Node{
	int vertex;
	int weight;
	bool operator<(const Node& other) const{
		return weight < other.weight;
	}
};

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
	vector<bool> visited = vector<bool>(G.numVertices, false);
	previous = vector<int>(G.numVertices, -1);
	vector<int> distances = vector<int>(G.numVertices, numeric_limits<int>::max());
	distances[source] = 0;

	priority_queue<Node> pq;
	pq.push(Node(source, 0));
	
	while(!pq.empty()){
		int u = pq.top().vertex;
		pq.pop();
		if(visited[u]) { continue; }
		visited[u] = true;
		for(Edge e: G[u]){
			int v = e.dst;
			int weight = e.weight;
			if (!visited[v] && distances[u] + weight < distances[v]){
				distances[v] = distances[u] + weight;
				previous[v] = u;
				pq.push(Node(v, distances[v]));
			}
		}
	}

	return distances;
}
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
	cout << distances.size() << previous.size() << destination;
	return distances;
}
void print_path(const vector<int>& v, int total){
	for(int i: v)
		cout << i << " ";
	cout << "\nTotal cost is " << total << endl;
}