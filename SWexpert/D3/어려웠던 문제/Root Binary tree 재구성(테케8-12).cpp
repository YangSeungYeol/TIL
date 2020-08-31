#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
	
}

int T, K,E, treeSize;
vector<int> binaryTree;
vector<pair <int,int>> ans;
pair <int, int> p;
bool visited[1024];
void func(vector<int> bTree,int treeSize,int depth) {
	if (depth > K) {
		return;
	}
	if (visited[bTree[treeSize / 2]] == false) {
		visited[bTree[treeSize / 2]] = true;
		p.first = bTree[treeSize / 2];
		p.second = depth;
		ans.push_back(p);
		vector <int> pTree;
		vector <int> qTree;
		for (int i = 0; i < treeSize / 2; i++) {
			pTree.push_back(bTree[i]);
			qTree.push_back(bTree[treeSize / 2 + i+1]);
		}
		func(pTree, treeSize / 2, depth + 1);
		func(qTree, treeSize / 2, depth + 1);
	}	
}

int main(int argc, char** argv)
{
	int test_case;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> K;
		binaryTree.clear();
		ans.clear();
		treeSize = pow(2, K) - 1;
		for (int i = 0; i < treeSize; i++) {
			cin >> E;
			binaryTree.push_back(E);
		}
		func(binaryTree,treeSize,1);
		cout << "#" << test_case << " ";
		
		sort(ans.begin(), ans.end(),cmp);
		int p = 0;
		for (int i = 0; i < K; i++) {
			for (int j = p; j < pow(2, i)+p; j++) {
				cout << ans[j].first<<" ";
				visited[j] = false;
			}
			p += pow(2, i);
			cout << endl;
		}
	}
	return 0;
}