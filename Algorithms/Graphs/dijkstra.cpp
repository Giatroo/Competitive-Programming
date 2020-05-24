#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mk make_pair
#define pii pair<int, int>

const int N = 112345;
const int INF = 0x3f3f3f3f;

vector<pii> adj[N];
int dist[N];
int n;

void dijkstra(int s) {
	set<pii> pq;
	for (int i = 0; i < n; i++) dist[i] = INF;
	pq.insert(mk(0, s));
	dist[s] = 0;

	pii cur;
	while (!pq.empty()) {
		cur = *pq.begin();
		pq.erase(pq.begin());

		if (dist[cur.s] != INF) continue;

		for (auto it : adj[cur.s]) {
			if (dist[it.f] > cur.f + it.s) {
				dist[it.f] = cur.f + it.s;
				pq.insert(mk(dist[it.f], it.f));
				// processing
			}
		}
	}
}
