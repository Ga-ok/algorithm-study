#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
int path[100001];
void dfs(int node) {

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (path[next] != 0) continue;
		path[next] = node;
		dfs(next);
	}

}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int from;
		int to;
		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << path[i] << "\n";
	}

}