#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl "\n";

using namespace std;

int N, M;
vector<vector<int>> InputPanel;
vector<vector<int>> Panel;

struct Answer { // v: 세로 h: 가로
	char c;
	int pos;
	int color;
};
vector<Answer> answer;

void input() {

	// 콘솔창 입력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	InputPanel.resize(N);
	for (auto& i : InputPanel) {

		i.resize(M);

		for (auto& j : i) {
			cin >> j;
		}
	}

	Panel.resize(N);
	for (auto& i : Panel) {
		i.resize(M);
	}
}

void output() {

	//콘솔창 출력
	cout << answer.size() << endl;

	for (auto& i : answer) {
		cout << i.c << " ";
		cout << i.pos << " ";
		cout << i.color << endl;
	}
}

void inputFile(int n)
{
	//파일 입력
	string path = "input_" + to_string(n) + ".txt";

	FILE* file = fopen(path.c_str(), "r");

	cout << strerror(errno) << endl;

	fscanf(file, "%d %d", N, M);

	InputPanel.resize(N);
	for (auto& i : InputPanel) {

		i.resize(M);

		for (auto& j : i) {
			fscanf(file, "%d", j);
		}
	}

	Panel.resize(N);
	for (auto& i : Panel) {
		i.resize(M);
	}

	fclose(file);
}

void outputFile(int n)
{
	//파일 출력
	string path = "output_" + to_string(n) + ".txt";

	FILE* file;
	file = fopen(path.c_str(), "w");

	fprintf(file, "%d\n", answer.size());
	
	for (auto& i : answer) {
		fprintf(file, "%d ", i.c);
		fprintf(file, "%d ", i.pos);
		fprintf(file, "%d\n", i.color);
	}

	fclose(file);
}

void source() {
	while (1) {
		bool flag = true;

		for (int i = 0; i < N; i++) {
			int color = -1;
			for (int j = 0; j < M; j++) {
				if (Panel[i][j] != InputPanel[i][j]
					&& InputPanel[i][j] != 0)
				{
					color = InputPanel[i][j];
					break;
				}
			}

			if (color == -1)
				continue;


			for (int j = 0; j < M; j++) {
				Panel[i][j] = color;
			}

			answer.push_back({ 'H', i + 1, color });
			flag = false;
		}

		for (int i = 0; i < M; i++) {
			int color = -1;
			for (int j = 0; j < N; j++) {
				if (Panel[j][i] != InputPanel[j][i]
					&& InputPanel[j][i] != 0)
				{
					color = InputPanel[j][i];
					break;
				}
			}

			if (color == -1)
				continue;


			for (int j = 0; j < N; j++) {
				Panel[j][i] = color;
			}

			answer.push_back({ 'V', i + 1, color });
			flag = false;
		}

		if (flag == true) {
			break;
		}
	}
}

int main() {

	/*
	//파일 입출력(파일경로에 input파일 있어야함)
	for (int i = 1; i <= 10; i++) {
		inputFile(i);
		source();
		outputFile(i);
	}
	*/

	//콘솔 입출력
	input();
	source();
	output();
	
	return 0;
}