#include <iostream>

using namespace std;


int visited[51][51];
int MAP[51][51];
int dy[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

int w = -1;
int h = -1;
void dfs(int y, int x) {

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (MAP[ny][nx] == 0) continue;
		if (visited[ny][nx] != 0) continue;

		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

int main() {

	while (true) {

		cin >> w >> h;

		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> MAP[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] != 0) continue;
				if (MAP[i][j] == 0) continue;

				visited[i][j] = 1;
				dfs(i, j);
				cnt += 1;
			}
		}

		cout << cnt << "\n";

		// ÃÊ±âÈ­
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				MAP[i][j] = 0;
				visited[i][j] = 0;
			}
		}
	}
	


	return 0;
}