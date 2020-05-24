#include <bits/stdc++.h>
using namespace std;

const int N = 112345;
int n;
int dist[N][N];

void floydwarshall() {
	// inicialize dist first (INF in everything, 0 in the diagonal and d in adj)
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
