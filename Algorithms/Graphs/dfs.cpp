#include <stack>
#include <vector>

const int N = 112345;
bool visited[N];
std::vector<int> adj[N];

void dfs(int s) {
  std::stack<int> st;
	st.push(s);
	visited[s] = true;

	int cur;
	while (!st.empty()) {
		cur = st.top();
		st.pop();

		for (auto it : adj[cur]) {
			if (!visited[it]) {
				visited[it] = true;
				st.push(it);
				// processing
			}
		}
	}
}
