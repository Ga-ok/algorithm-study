#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int n;
	int dist;
};

vector<Node> v[5001];
int visited[5001];
long long maxSum = 0;
void dfs(int node, long long distSum) {

	if (maxSum < distSum) maxSum = distSum;

	for (int i = 0; i < v[node].size(); i++) {
		Node next = v[node][i];

		if (visited[next.n] != 0) continue;

		visited[next.n] = 1;
		dfs(next.n, distSum+next.dist);
		visited[next.n] = 0;
	}

}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int a, b, dist;
		cin >> a >> b >> dist;

		v[a].push_back({ b, dist });
		v[b].push_back({ a, dist });
	}

	visited[1] = 1;
	dfs(1, 0);
	visited[1] = 0;
	cout << maxSum<<"\n";
	return 0;
}