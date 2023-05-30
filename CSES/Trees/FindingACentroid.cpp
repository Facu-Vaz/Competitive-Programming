#include <bits/stdc++.h>

using namespace std;

int num_nodes;
int half;
int centroid;

vector<vector<int>> adj;
vector<int> num_children;

void find (int a, int f) {
	for (auto n : adj[a])
	{
		if (n == f) continue;
		if (num_children[n] > half) {
			find(n, a);
			break;
		}
		centroid = a+1;
		return;
	}
}

int calc (int a, int f) {
	int x = 0;
	for (auto n : adj[a])
	{
		if (n == f) continue;
		x += calc(n, a);
	}
	num_children[a] = x+1;
	
	return num_children[a];
}

int main ()
{
	cin >> num_nodes;
	half = num_nodes / 2;
	//if (num_nodes % 2 == 1) half += 1;
	adj.resize(num_nodes);
	num_children.resize(num_nodes);
	int a, b;
	for (int i = 1; i < num_nodes; i++) 
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	calc(0, -1);
	
	centroid = 1;
	for (auto fn : adj[0]) {
		if (num_children[fn] > half)
		{
			find(fn, 0);
			break;
		}
	}
	
	cout << centroid;
	
	
	
	//for (auto z : num_children) cout << z << " ";
	
}
