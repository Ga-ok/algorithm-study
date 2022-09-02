#include<iostream>

using namespace std;

int m;
int n;
int MAP[50][50];
int visited[50][50];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] == 0) continue;

		visited[ny][nx] = 1;
		dfs(ny, nx);
	}

}

int main() {

	int t;
	cin >> t;

	for (int testcase = 0; testcase < t; testcase++) {

		int k;
		int cnt = 0;

		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x;
			int y;
			cin >> x >> y;
			MAP[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (MAP[i][j] == 1) {
					if (visited[i][j] != 0) continue;
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt <<"\n";

		// ÃÊ±âÈ­
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				MAP[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		
	}

	return 0;
}