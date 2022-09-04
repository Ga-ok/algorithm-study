#include <iostream>
#include <string>
using namespace std;


char MAP[101][101];
int visited[101][101];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int h, w;
void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] == '.') continue;

		visited[ny][nx] = 1;
		dfs(ny, nx);
	}

}

int main() {

	int T;
	cin >> T;

	for (int testcase = 0; testcase < T; testcase++) {

		cin >> h >> w;

		for (int i = 0; i < h; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < w; j++) {
				MAP[i][j] = str[j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (MAP[i][j] == '.') continue;
				if (visited[i][j] != 0) continue;

				visited[i][j] = 1;
				dfs(i, j);
				cnt += 1;
			}
		}
		cout << cnt << "\n";

		// ÃÊ±âÈ­
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				MAP[i][j] = '0';
				visited[i][j] = 0;
			}
		}
	}

	return 0;
}