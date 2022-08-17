#include <bits/stdc++.h>

using namespace std;

#define endl "\n";

bool answer = true;

struct User {
	int time;
	int s;
};

int N, M;
vector<vector<User>> vec;

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vec.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int t, n, s;
		cin >> t >> n >> s;

		vec[n].push_back({ t, s });
	}
}

void output() {
	if (answer) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}

void source() {
	for (int i = 1; i <= N; i++) {

		int last_s = -1;

		for (int j = 0; j < vec[i].size(); j++) {

			if (vec[i][j].s != j % 2) {
				answer = false;
				break;
			}

			if (vec[i][j].s == 1) {
				if (vec[i][j].time - vec[i][j - 1].time < 60) {
					answer = false;
					break;
				}
			}

			last_s = vec[i][j].s;
		}

		if (!answer) {
			break;
		}

		if (last_s == 0) {
			answer = false;
			break;
		}
	}
}

int main()
{
	input();
	source();
	output();

	return 0;
}