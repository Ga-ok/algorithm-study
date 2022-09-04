#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

char MAP[5][5];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
set<string> s;
void dfs(int y, int x, int level, string str) {

	if (level == 5) {
		s.insert(str);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
		dfs(ny, nx, level + 1, str + MAP[ny][nx]);
	}

}

int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string start;
			start.push_back(MAP[i][j]);
			dfs(i, j, 0, start);
		}
	}

	cout << s.size();
	return 0;
}