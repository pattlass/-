#include <iostream>
using namespace std;
int main() {
	setlocale(0, "");
	int x, y;
	cout << "¬ведите два целых числа через пробел: ";
	cin >> x >> y;

	int sum = x + y; 
	cout << "—умма: " << sum << endl;
	return 0;
}
