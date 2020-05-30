#include <bits/stdc++.h>
using namespace std;

const int N = 112345;
const int L = 27;

int anc[N][L];
vector<int> adj[N];
int depth[N];
int n;

void bfs(int s) {
	queue<int> q;
	q.push(s);
	for (int i = 0; i < n; i++) depth[i] = -1;
	depth[s] = 0;

	while (!q.empty()) {
		s = q.front();
		q.pop();
		for (int i : adj[s]) {
			if (depth[i] != -1) {
				anc[s][0] = i;
				continue;
			}
			depth[i] = depth[s] + 1;
			q.push(i);
		}
	}
}

void build_anc(int root) {
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < L; j++) anc[i][j] = 0;
	bfs(root);
	for (int j = 1; j < L; j++)
		for (int i = 1; i <= n; i++) anc[i][j] = anc[anc[i][j - 1]][j - 1];
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	for (int i = L - 1; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v]) u = anc[u][i];

  if (u == v) return u;

  for (int i = L-1; i>=0; i--) {
     if (anc[u][i] != 0 && anc[u][i] != anc[v][i]) {
        u = anc[u][i];
        v = anc[v][i];
     }
  }

	return anc[u][0];
}
