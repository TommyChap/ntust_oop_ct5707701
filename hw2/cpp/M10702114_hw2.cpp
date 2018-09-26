#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void insert_sort(string *, int);

int main(void){
	int n, i = 0;
	// Get max number and check is number
	while (1) {
		cout << "請輸入最大長度:" << endl;
		cin >> dec >> n;
		if(n) {
			break;
		} else {
			cout << "請輸入數字" << endl;
		}
	}

	// New a string array
	// string s[n + 1];	// Gnu G++ VLA
	string *s = new string[n + 1];	// C++ Dynamic Array

	// Main features
	 while (true) {
		cout << "請輸入字串或指令(print/exit):";
		cin >> s[i];
		if (s[i] == "print") {
			for (int j = 0; j < i; j++){
				cout << s[j] << " ";
			}
			cout << endl;
		} else if (s[i] == "exit") {
			break;
		} else {
			if (i == n) {
				cout << "已達輸入上限" << endl;
			} else {
				insert_sort(s, i);
				i++;
			}
		}	
	}
	system("pause");
	return 0;
}

void insert_sort(string *s, int len){
	string s_tmp;
	if (len < 1) {
		return;
	} else {
		for (int i = len; i > 0; i--) {
			if (s[i] < s[i - 1]) {
				s_tmp = s[i];
				s[i] = s[i - 1];
				s[i - 1] = s_tmp;
			}
		}
	}
}