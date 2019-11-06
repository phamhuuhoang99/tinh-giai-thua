#include <iostream>
using namespace std;

int main() {
	int soN;
	cout << "so can tinh tong" << '\t';
	cin >> soN;
	cout << endl;
	int sum = 0;
	while (soN != 0) {
		int x = soN % 10;
		sum = sum + x;
		soN = soN % 10;
	}
	cout << "tong cac so nguyen la: " << sum << endl;
	return 0;
}
