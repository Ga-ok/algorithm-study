#include <iostream>
#include <vector>
#include <string>
using namespace std;

char MAP[601][601];

int sy, sx;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int n, m;
int visited[601][601];

int cnt = 0;
void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] == 'X') continue;
		if (MAP[ny][nx] == 'I') continue;

		if (MAP[ny][nx] == 'P') cnt += 1;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}

}


int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			MAP[i][j] = str[j];

			if (str[j] == 'I') {
				sy = i;
				sx = j;
			}
		}
	}

	visited[sy][sx] = 1;
	dfs(sy, sx);

	if (cnt == 0) {
		cout << "TT";
	}
	else {
		cout << cnt;
	}
	
	return 0;
}