#include<iostream>
#include<vector>
using namespace std;

int tc, N,x,y,E,M;
char ins;
vector <int> vec;
int main(int argc, char** argv)
{

	for (tc = 1; tc <= 10; ++tc)
	{
		vec.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> E;
			vec.push_back(E);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >>ins>> x >> y;
			for (int k = 0; k < y; k++) {
				cin >> E;
				vec.insert(vec.begin()+x + k, E);
			}

		}
		
		cout << "#" << tc << " ";
		for (int i = 0; i < 10; i++) {
			cout << vec[i] << " ";
		}
		cout<<endl;
	}
	return 0;
}