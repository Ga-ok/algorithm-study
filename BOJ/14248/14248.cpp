#include <iostream>

using namespace std;

int MAP[100001];

int n;
int visited[100001];
int dy[] = { -1, 1 };
int s;

int cnt = 0;
void dfs(int node) {

	int right = node + MAP[node];
	int left = node - MAP[node];
	if (right < n) {
		if (visited[right] == 0) {
			visited[right] = 1;
			cnt++;
			dfs(right);
		}
	}
	
	if (left >= 0) {
		if (visited[left] == 0) {
			visited[left] = 1;
			cnt++;
			dfs(left);
		}
	}
}


int main() {

	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> MAP[i];
	}

	cin >> s;

	visited[s - 1] = 1;
	cnt++;
	dfs(s - 1);

	cout << cnt;
	
	return 0;
}