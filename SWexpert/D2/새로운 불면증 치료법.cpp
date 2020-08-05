#include<iostream>
#include <vector>
using namespace std;
int main(int argc, char** argv)
{
    int test_case, T, N,NN,NNN,mok,r,cnt;
    bool is_new;
    vector<int> vec;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        cnt = 1;
        NN = N;
        NNN = N;
        vec.clear();
        while (vec.size()!=10) {
            cnt ++;
            while(N!=0) {
                r = N % 10;
                N = N / 10;
                is_new = true;
                for (int i = 0; i < vec.size(); i++) {
                    if (r == vec.at(i)) {
                        is_new = false;
                        break;
                    }
                }
                if (is_new == true) {
                    vec.push_back(r);
                }
            }
            N = NN;
            N *= cnt;
        }
        cout << "#" << test_case << " " << NNN*(cnt-1) << endl;
    }
    return 0;
}