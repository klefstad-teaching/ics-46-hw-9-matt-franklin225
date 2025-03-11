#include "dijkstras.h"
using namespace std;

struct Node{
	int vertex;
	int weight;
	bool operator<(const Node& other) const{
		return weight < other.weight;
	}
	bool operator>(const Node& other) const{
		return weight > other.weight;
	}
};

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
	vector<bool> visited = vector<bool>(G.numVertices, false);
	previous = vector<int>(G.numVertices, -1);
	vector<int> distances = vector<int>(G.numVertices, numeric_limits<int>::max());
	distances[source] = 0;

	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push(Node(source, 0));
	
	while(!pq.empty()){
		int u = pq.top().vertex;
		cout << "Now testing: " << u << endl;
		pq.pop();
		if(visited[u]) { continue; }
		visited[u] = true;
		for(Edge e: G[u]){
			int v = e.dst;
			int weight = e.weight;
			// if (!visited[v]){
				cout << "Possible dist to " << v << ": " << distances[u] + weight << endl;
			// }
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
	vector<int> path;
	vector<int> trace_back(1, destination);
	cout << distances[0];
	while(previous[destination] != -1){
		destination = previous[destination];
		trace_back.push_back(destination);
	}
	while(trace_back.size()){
		path.push_back(trace_back[0]);
		trace_back.pop_back();
	}
	return path;
}
void print_path(const vector<int>& v, int total){
	for(int i: v)
		cout << i << " ";
	cout << "\nTotal cost is " << total << endl;
}