#include<iostream>
#include<string>
#include<vector>

using namespace std;

string depar = "SEOUL";
string hub = "DAEGU";
string dest = "YEOSU";
vector<vector<string>> roads = { {"ULSAN","BUSAN"},{"DAEJEON","ULSAN"},{"DAEJEON","GWANGJU"},{"SEOUL","DAEJEON"},{"SEOUL","ULSAN"},{"DAEJEON","DAEGU"},{"GWANGJU","BUSAN"},{"DAEGU","GWANGJU"},{"DAEGU","BUSAN"},{"ULSAN","DAEGU"},{"GWANGJU","YEOSU"},{"BUSAN","YEOSU"} };
bool visited[100000];
int result;

void dfs(string start,string arrive) {
	if (start == arrive) {
		result += 1;
		return;
	}
	for (int i = 0; i < roads.size(); i++) {
		if (roads[i][0] == start&&visited[i]==false) {
			visited[i] = true;
			dfs(roads[i][1],arrive);
			visited[i] = false;
		}
	}
}
int main() {
	int answer = -1;
	result = 0;
	dfs(depar, hub);
	int deparToHub = result;
	result = 0;
	dfs(hub, dest);
	int hubTodest = result;
	answer = deparToHub * hubTodest;
	cout << answer << endl;
	return 0;
}