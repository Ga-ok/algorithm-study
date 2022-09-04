#include <iostream>
#include <vector>
using namespace std;

int to;
vector<int> v[101];
int visited[101];

int res = -1;
void dfs(int node, int level) {

	if (node == to) {
		res = level;
		return;
	}

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (visited[next] != 0) continue;
		visited[next] = 1;
		dfs(next, level+1);
		visited[next] = 0;

		if (res != -1) return;
	}
}

int main() {

	int n;
	cin >> n;

	int from;
	cin >> from >> to;

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int from;
		int to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	dfs(from, 0);
	cout << res;
	return 0;
}