#include<iostream>
#include<string>
using namespace std;
int N,cnt,iNum;
string sNum,answer;
int main() {
	cin >> N;


	while(true){
		iNum++;
		sNum = to_string(iNum);
		if (sNum.find("666")<100000) cnt++;
		if (cnt == N) {
			answer = sNum;
			break;
		}
	}
	cout << answer << endl;
	return 0;
}