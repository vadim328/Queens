#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int rec(int n, int n2, int i, int j, vector <int> x, vector <int> y, int &sum) { // i - строка, j - столбец
	bool cross = false;
	// проверка на пересечение ферзей с остальными
	if (find(x.begin(), x.end(), i) != x.end()) {
		cross = true;
	}
	if (find(y.begin(), y.end(), j) != y.end()) {
		cross = true;
	}
	for (int k = 0; k < n2; k++) {
		if (abs(i - x[k]) == abs(j - y[k])) {
			cross = true;
			break;
		}
	}
	if (cross == false) { // если нету пересечений с остальными ферзями
		if (i == n - 1) {
			sum++;
			return sum;
		}
		x.push_back(i);
		y.push_back(j);

		rec(n, n2 + 1, i + 1, 0, x, y, sum);

		if (i != 0 && j != n - 1) {
			x.pop_back();
			y.pop_back();
			rec(n, n2, i, j + 1, x, y, sum);
		}
	}
	else if (j == n - 1) { // нет возможности поставить ферзя
		return sum;
	}
	else {
		return rec(n, n2, i, j + 1, x, y, sum);
	}
}

int main() {
	int n, sum = 0; // i - строка, j - столбец
	cout << "Enter the number of queens: ";
	cin >> n;
	vector <int> x;
	vector <int> y;
	for (int s = 0; s < n; s++) {
		rec(n, 0, 0, s, x, y, sum);
	}
	cout << sum;
	return 0;
}
