vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
	vector<bool> visited = vector<bool>(G.numVertices, false);
	vector<int> distances = vector<int>(G.numVertices, numeric_limits<int>::max());
	distances[source] = 0;

	priority_queue<int> pq;
	pq.push(source);
	
	while(!pq.empty()){
		int current = pq.top();
		pq.pop();
		if(visited[current]) { continue; }
		visited[current] = true;
	}

	return distances;
}
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
	return vector<int>(10, 0);
}
void print_path(const vector<int>& v, int total){
	for(int i: v)
		cout << i << " ";
	cout << "\nTotal cost is " << total << endl;
}