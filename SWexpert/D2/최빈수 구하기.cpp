#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
    int test_case, T, N,M, modeValue, cnt,maxcnt;
    vector<int> vec;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        vec.clear();
        for (int i = 0; i < 1000; i++) {
            cin >> M;
            vec.push_back(M);
        }
        sort(vec.begin(), vec.end());
        maxcnt = 0;
        cnt = 0;
        for (int i = 0; i < 999; i++) {
            if (vec[i] == vec[i + 1]) {
                cnt++;//�ߺ���������
            }
            else {
                if (cnt > maxcnt) {
                    maxcnt = cnt;
                    modeValue = vec[i];
                }
                else if (cnt == maxcnt&& modeValue < vec[i]) {
                    modeValue = vec[i];
                }
                cnt = 0;//�ߺ������ʱ�ȭ
            }
        }

        cout << "#" << N << " " << modeValue << endl;
    }
    return 0;
}