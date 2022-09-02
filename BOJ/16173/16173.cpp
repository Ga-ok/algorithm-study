#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int y;
	int x;
};

int n;
int dy[] = { 1, 0 };
int dx[] = { 0, 1 };
int visited[3][3];
vector<Node> v;
int MAP[3][3] = { 0 };
int flag = 0;
void dfs(int y, int x) {

	if (y == n - 1 && x == n - 1) {
		flag = 1;
		return;
		exit(0);
	}

	for (int i = 0; i < 2; i++) {
		int ny = y + dy[i] * MAP[y][x];
		int nx = x + dx[i] * MAP[y][x];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx] != 0) continue;
		visited[ny][nx] = 1;
		v.push_back({ ny, nx });
		dfs(ny, nx);
		v.pop_back();
		visited[ny][nx] = 0;
	}

}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}

	visited[0][0] = 1;
	v.push_back({ 0, 0 });
	dfs(0, 0);
	v.pop_back();
	visited[0][0] = 0;


	if (flag == 0) cout << "Hing";
	else cout << "HaruHaru";

	return 0;
}