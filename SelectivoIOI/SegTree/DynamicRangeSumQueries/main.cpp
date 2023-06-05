#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> segTree;
ll N, seg_size, num_q;

void update (ll x, ll k) {
	x += seg_size;
	//cout << x;
	segTree[x] = k;
	x /= 2;
	while (x != 0) {
		segTree[x] = segTree[2*x] + segTree[2*x+1];
		x /= 2;
	}
}

ll find (ll a, ll b) {
	ll sum = 0;
	a += seg_size; b += seg_size;
	while (a <= b) {
		//cout << a << " " << b << endl;
		if (a % 2 == 1) sum += segTree[a++];
		if (b % 2 == 0)	sum += segTree[b--];
		a /= 2;
		b /= 2;
	}
	return sum;
}

int main()
{
	cin >> N >> num_q;
	seg_size = 1;
	while (seg_size < N) seg_size <<= 1;
	segTree.resize(seg_size*2);
	
	for (ll i = 0; i < N; i++) cin >> segTree[i+seg_size];
	for (ll i = seg_size - 1; i > 0; i--) segTree[i] = segTree[2*i] + segTree[2*i+1];
	
	ll qtype, a, b;
	for (int q = 0; q < num_q; q++) 
	{
		cin >> qtype >> a >> b;
		if (qtype == 1) update(a-1, b);
		else cout << find(a-1, b-1) << "\n";
	}
	
}
