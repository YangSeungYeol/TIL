#include<iostream>

using namespace std;

int test_case,T, vL,vR,smlL, midL, lagL, smlR, midR, lagR, ans;
char ch[1000];

int main(int argc, char** argv)
{
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
		vL = 0, vR = 0, smlL = 0, midL = 0, lagL = 0, smlR = 0, midR = 0, lagR = 0;
		string str = "";
		for (int i = 0; i < T; i++) {
			cin>>ch[i];
		}
		for (int i = 0; i < T; i++) {
			switch(ch[i]) {
				case '(':
					smlL++;
					break;
				case '{':
					midL++;
					break;
				case '[':
					lagL++;
					break;
				case ')':
					smlR++;
					break;
				case '}':
					midR++;
					break;
				case ']':
					lagR++;
					break;
				case '<' :
					vL++;
					break;
				case '>':
					vR++;
					break;
			}
			if (smlL == smlR && midL == midR && lagL == lagR) {
				ans = 1;
			}
			else {
				ans = 0;
			}
		}
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}