#include <bits/stdc++.h>
using namespace std;

const int N = 112345;
int n;
int uf[N], w[N];

void build() {
   for (int i = 0; i < n; i++) { uf[i] = i; w[i] = 1; }
}

int find(int u) {
   return (uf[u] == u ? u : uf[u] = find(uf[u]));
}

void join(int u, int v) {
   u = find(u);
   v = find(v);
   if (w[u] < w[v]) swap(u, v);
   w[u] += w[v];
   uf[v] = u;
}

