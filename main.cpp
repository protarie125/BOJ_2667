#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;

vs f;
vvb isVisited;
int ct;

const auto& dx = vi{ -1, 0, 1, 0 };
const auto& dy = vi{ 0, -1, 0, 1 };

void dfs(int i, int j, int n) {
	for (auto d = 0; d < 4; ++d) {
		const auto& nx = i + dx[d];
		const auto& ny = j + dy[d];

		if (nx < 0 || n <= nx ||
			ny < 0 || n <= ny) {
			continue;
		}

		if (!isVisited[nx][ny] && '1' == f[nx][ny]) {
			isVisited[nx][ny] = true;
			++ct;
			dfs(nx, ny, n);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; cin >> n;
	f = vs(n);
	for (auto i = 0; i < n; ++i) {
		cin >> f[i];
	}

	isVisited = vvb(n, vb(n, false));

	auto ans = vi{};
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			if ('0' == f[i][j]) {
				continue;
			}

			if (isVisited[i][j]) {
				continue;
			}

			isVisited[i][j] = true;
			ct = 1;
			dfs(i, j, n);
			ans.push_back(ct);
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (const auto& x : ans) {
		cout << x << '\n';
	}

	return 0;
}