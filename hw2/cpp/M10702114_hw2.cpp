#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n, i = 0, j;
	while (1) {
		cout << "請輸入最大長度:" << endl;
		cin >> dec >> n;
		if(n) {
			break;
		} else {
			cout << "請輸入數字" << endl;
		}
	}
	string s[n + 1];
	 while (true) {
		cout << "請輸入字串或指令(print/exit):" << endl;
		cin >> s[i];
		if (s[i] == "print") {
			vector<string> sortvector(s, s + i);
			sort(sortvector.begin(), sortvector.end());
			for (vector<string>::iterator j = sortvector.begin(); j != sortvector.end(); ++j)
				cout << * j << " ";
			cout << endl;
		} else if (s[i] == "exit") {
			break;
		} else {
			if (i == n) {
				cout << "已達輸入上限" << endl;
			} else {
				i++;
			}
		}	
	}
	system("pause");
	return 0;
}