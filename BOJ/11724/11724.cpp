#include <iostream>
#include <vector>
using namespace std;

int visited[1001];
vector<int> graph[1001];
void dfs(int node) {

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];

		if (visited[next] != 0) continue;
		visited[next] = 1;
		dfs(next);
	}

}
int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u;
		int v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] != 0) continue;
		dfs(i);
		cnt += 1;
	}

	cout << cnt << "\n";

	return 0;
}