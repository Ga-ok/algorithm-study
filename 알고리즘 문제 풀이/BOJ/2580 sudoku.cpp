#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int y;
	int x;
};

int MAP[9][9] = { 0 };
vector<Node> zero;
bool isPossible(int y, int x, int num) {

	// ������ üũ
	for (int i = 0; i < 9; i++) {
		if (MAP[y][i] == num) return false;
	}

	// ������ üũ
	for (int i = 0; i < 9; i++) {
		if (MAP[i][x] == num) return false;
	}

	// 3X3 üũ
	// 0, 1, 2 / 3, 4, 5 / 6, 7, 8
	//    0         1         2
	int ty = (y / 3) * 3;
	int tx = (x / 3) * 3;
	for (int i = ty; i < ty + 3; i++) {
		for (int j = tx; j < tx + 3; j++) {
			if (MAP[i][j] == num) return false;
		}
	}

	// ����!
	return true;
}

int flag = 0;
void dfs(int idx) {

	// ��������
	// ������ ��� ä����!
	if (idx == zero.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << MAP[i][j] << " ";
			}
			cout << "\n";
		}
		// ������ ��� ä�����ٴ� ���� ���!
		flag = 1;
		return;
	}

	int y = zero[idx].y;
	int x = zero[idx].x;

	// ��ͱ���
	for (int i = 1; i <= 9; i++) {
		if (isPossible(y, x, i)) {
			MAP[y][x] = i;

			dfs(idx + 1);

			// ������ �̹� ä�����µ�, ����ؼ� for���� ���ư��� ���� ����
			if (flag == 1) return;

			// ����, ���ٰ� �ȵǸ� ���ƿͼ� �ٽ� ������� �����ֱ�!
			MAP[y][x] = 0;

		}
	}

}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 0) zero.push_back({ i, j });
		}
	}

	// 0�� ��ǥ�� dfs �����ֱ� 
	for (int i = 0; i < zero.size(); i++) {
		dfs(i);
	}

	return 0;
}