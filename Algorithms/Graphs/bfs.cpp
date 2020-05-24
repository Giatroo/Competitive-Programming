#include <queue>
#include <vector>

const int N = 112345;
bool visited[N];
std::vector<int> adj[N];

void dfs(int s) {
	std::queue<int> q;
	q.push(s);
	visited[s] = true;

	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (auto it : adj[cur]) {
			if (!visited[it]) {
				visited[it] = true;
				q.push(it);
				// processing
			}
		}
	}
}
