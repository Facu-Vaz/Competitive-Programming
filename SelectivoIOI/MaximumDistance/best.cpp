#include <bits/stdc++.h>

using namespace std;
int num_nodes, num_edges, num_especial_nodes;
vector<pair<int, pair<int, int>>> edges;

vector<int> parent;
vector<int> children;
vector<int> especial_per_comp;

int find (int x)
{
	while (parent[x] != x) x = parent[x];
	return x;
}

int join (int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false;
	
	if (children[b] > children[a]) swap(a, b);
	
	parent[b] = a;
	children[a] += children[b];
	especial_per_comp[a] += especial_per_comp[b];
	
	if (especial_per_comp[a] == num_especial_nodes) return true;
	return false;
}

int main() 
{
	cin >> num_nodes >> num_edges >> num_especial_nodes;
	children.resize(num_nodes+1, 1);
	for (int p = 0; p <= num_nodes; p++) parent.push_back(p);
	especial_per_comp.resize(num_nodes+1, 0);
	
	int esp_node;
	for (int e = 0; e < num_especial_nodes; e++) 
	{
		cin >> esp_node;
		especial_per_comp[esp_node] = 1;
	}  
	
	int a, b, w;
	for (int e = 0; e < num_edges; e++)
	{
		cin >> a >> b >> w;
		edges.push_back({w, {a, b}});
	}
	sort(edges.begin(), edges.end());
	
	int final_cost;
	for (auto e : edges) {
		a = e.second.first; b = e.second.second;
		if (join(a, b)) {
			final_cost = (e.first);
			break;
		}
	}
	
	for (int i = 0; i < num_especial_nodes; i++) cout << final_cost << " ";
	
	
	
	
	
	
}
