#include<iostream>
#include <vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main(int argc, char** argv)
{
    int test_case, T,N,M,maxReward; //N = 숫자판정보, M=교환횟수
    vector<int> vec;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        vec.clear();
        maxReward = 0;
        cin >> N >> M;
        while (N != 0) {
            vec.push_back(N % 10);
            N /= 10;
        }
        reverse(begin(vec), end(vec));
        for (int k = 0; k < M; k++) {
            for (int i = 0; i < vec.size(); i++) {
                int temp = vec[i];
                int idxTemp = i;
                for (int j = vec.size() - 1; j >= i + 1; j--) {
                    if (vec[j] > temp) {
                        temp = vec[j];
                        idxTemp = j;
                    }
                }
                swap(vec[i], vec[idxTemp]);
            }
        }
        cout << "#" << test_case << " ";
        while (1) {
            if (!vec.empty()) {
                cout << vec.front();
                vec.erase(vec.begin());
            }else{
                break;
            }
        }
        cout << endl;
    }
    return 0;
}