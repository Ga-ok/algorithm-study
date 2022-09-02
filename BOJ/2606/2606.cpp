#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100];
int cnt = 0;
int visited[100];
vector<int> path;
void dfs(int index) {

	for (int i = 0; i < v[index].size(); i++) {
		if (visited[v[index][i]] != 0) continue;

		visited[v[index][i]] = 1;
		path.push_back(v[index][i]);
		dfs(v[index][i]);
	}
}

int main() {

	int n;
	cin >> n;

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int from;
		int to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	visited[1] = 1;
	//path.push_back(1);
	dfs(1);
	
	cout << path.size();
	return 0;
}