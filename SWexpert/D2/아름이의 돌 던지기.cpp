#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
    int test_case, T, N, M, cnt;
    vector<int> vec;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        vec.clear();
        cnt = 1;
        for (int i = 0; i < N; i++) {
            cin >> M;
            M = abs(M);
            vec.push_back(M);
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i] == vec[i + 1]) {
                cnt++;
            }
            else {
                break;
            }
        }

        cout << "#" << test_case << " " << vec[0] << " " << cnt << endl;
    }
    return 0;
}