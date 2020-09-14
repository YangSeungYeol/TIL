#include<iostream>
#include<vector>
using namespace std;

int tc, T, N, exist,cnt;
vector <pair<int, int>> vec;
pair<int, int> p;

void func(int currentNode) {
    if (currentNode == 99) {
        exist = 1;
    }
	for (int i = 0; i < vec.size(); i++) {
		if (cnt == 2) {
			break;
		}
		if (vec[i].first == currentNode) {
			cnt++;
			int nextNode = vec[i].second;
			func(nextNode);
		}
		cnt = 0;
	}
}3

int main(int argc, char** argv)
{
	for (tc = 1; tc <= 10; ++tc)
	{
		exist = 0;
		vec.clear();
		cin >>T>> N;
		for (int i = 0; i < N; i++) {
			cin >> p.first >> p.second;
			vec.push_back(p);
		}
		func(0);

		cout << "#" << tc << " " << exist << endl;
	}
    return 0;
}