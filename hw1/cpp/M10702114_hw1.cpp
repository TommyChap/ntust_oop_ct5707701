#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
	// Init variable
	int min, max, ans, userinput;
	
	// Read setting file
	ifstream fcin = ifstream("./input.txt");
	fcin >> min >> max >> ans;

	// Start Game
	do {
		cout << "請輸入" << min << "~" << max << "之間的數字:";
		cin >> userinput;
		if (userinput >= max || userinput <= min){
			cout << "請輸入範圍內的數值" << endl;
		} else if (userinput > ans) {
			max = userinput;
		} else if (userinput < ans) {
			min = userinput;
		} else {
			cout << "恭喜你答對了" << endl;
		}
	} while (userinput != ans);

	// Stop View
	system("pause");
	return 0;
}