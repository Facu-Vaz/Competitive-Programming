#include <bits/stdc++.h>

using namespace std;

struct node {
	int father = 0; 
	int value = 0;
	int left;
	int right;
};

int N, seg_size, num_q, logn;
vector<int> num_list;
vector<int> front_seg = {0};
vector<int> roots = {1};
vector<node> nodes = {node()};
map<int, int> compress;


void build_seg()
{
	for (int i = 1; i < seg_size*2; i++) {
		front_seg.push_back(i);
		node n; n.father = i/2;
		if (i < seg_size) {
			n.left = i*2; 
			n.right = i*2+1;
		}
		else {
			n.left = -1; 
			n.right = -1;
		}
		nodes.push_back(n);
	}
}

void add_root (int x)
{
	int index = compress[x] + seg_size;
	int new_val = nodes[front_seg[index]].value + 1;
	int paralel = front_seg[index];
	 
	int node_id = nodes.size();
	node n; n.left = -1; n.right = -1; n.value = new_val; 
	if (seg_size != 1) n.father = node_id + 1;
	else n.father = 0;
	
	nodes.push_back(n);
	front_seg[index] = node_id;
	paralel = nodes[paralel].father;
	
	while (paralel != 0) {
		
		node n;
		if (index % 2 == 0) {
			n.left = node_id; n.right = front_seg[index+1];
		}
		else {
			n.left = front_seg[index-1]; n.right = node_id;
		}
		n.value = nodes[n.left].value + nodes[n.right].value;
		index /= 2;
			
		node_id = nodes.size();
		n.father = node_id + 1;
		nodes.push_back(n);
		front_seg[index] = node_id;
		
		//cout << "A" << node_id << " (" << paralel << ")  ";	
		//if (nodes[paralel].father != 0) 
		
		//else {
		//	n.father = 0;
		//	cout << "DONE  "; 
		//}	
		paralel = nodes[paralel].father;
	}
	nodes[front_seg[1]].father = 0;
	roots.push_back(front_seg[1]);
}

int find (int x, int k, set<int> &s) {
	//for (auto a : s) cout << a << " ";
	//cout << endl;
	auto iter = s.lower_bound(k);
	if (*iter != k) iter--;
	k = *iter;
	//cout << k << endl;
	node actual_node = nodes[roots[x]];
	//cout << roots[x] << endl;
	int total = actual_node.value;
	//cout << total << endl;
	int resto = 0;
	int obj = compress[k];
	//cout << obj << endl;
	int vara = seg_size / 2;
	for (int i = 0; i < logn-1; i++)
	{
		//cout << actual_node.father << " - " << actual_node.left << " " << actual_node.right << endl;
		//cout << vara << "    ";
		if (obj >= vara) {
			//cout << actual_node.value << "A";
			resto += nodes[actual_node.left].value;
			obj -= vara;
			actual_node = nodes[actual_node.right];
		}
		//else if (obj >= seg_size && obj == vara) resto += actual_node.value;
		else 
		{
			//cout << actual_node.value << "B";
			actual_node = nodes[actual_node.left];
		}
		vara /= 2;
	}
	resto += actual_node.value;
	//cout << endl << resto << endl;
	return total - resto;
}
 

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	
	num_list.resize(N+2);
	num_list[0] = 0; num_list[N+1] = 1e9 + 1;
	for (int i = 1; i < N+1; i++) cin >> num_list[i];
	
	set<int> s (num_list.begin(), num_list.end());

	int pos = 0;
	for (int el : s) compress[el] = pos++;
	
	seg_size = 1; logn = 1;
	while (seg_size < s.size()) {
		seg_size <<= 1;
		logn++;
	}
	
	build_seg();
	
	//for (int i = 0; i < seg_size*2; i++) cout << nodes[front_seg[i]].value << " ";
	//for (int i = 0; i < seg_size*2; i++) cout << front_seg[i] << " ";
	//cout << endl;
	
	//for (auto a : s) cout << a << " ";
	//cout << endl;
	
	for (int i = 1; i < N+1; i++) { add_root(num_list[i]);
		//for (int i = 0; i < seg_size*2; i++) cout << nodes[front_seg[i]].value << " ";
		//for (int i = 0; i < seg_size*2; i++) cout << front_seg[i] << " ";
		//cout << endl;
	}
	
	//for (auto a : roots) cout << a << " ";
	//cout << endl;

	//for (int i = 1; i < nodes.size(); i++)
	//{
	//	node a = nodes[i];
	//	cout << a.father << " - " << i << " - " << a.left << " " << a.right << endl;
	//}
	cin >> num_q;
	int i, j, k;
	for (int q = 0; q < num_q; q++)
	{
		cin >> i >> j >> k;
		cout << find(j, k, s) - find(i-1, k, s) << "\n	";
	}
	
	
}
