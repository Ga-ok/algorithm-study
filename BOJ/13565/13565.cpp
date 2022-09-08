#include <iostream>
#include <queue>
#include <string>
using namespace std;

char MAP[1001][1001];
int visited[1001][1001];
int m, n;
struct Node {
	int y;
	int x;
};
void bfs(int y, int x) {

	queue<Node> q;
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };

	q.push({ y, x });
	visited[y][x] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
			if (visited[ny][nx] != 0) continue;
			if (MAP[ny][nx] == '1') continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;

		}
	}

}

int main() {
	
	cin >> m >> n;

	
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			MAP[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (MAP[0][i] == '1') continue;
		if (visited[0][i] != 0) continue;
		bfs(0, i);
	}

	string res = "NO";
	for (int i = 0; i < n; i++) {
		if (visited[m - 1][i] == 1) {
			res = "YES";
			break;
		}
	}

	cout << res << "\n";

	return 0;
}