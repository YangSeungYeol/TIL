#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
    int test_case, T, P,Q,R,S,W,feeA,feeB,fee;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> P >> Q >> R >> S >> W;
        feeA = W * P;
        if (W <= R) {
            feeB = Q;
        }
        else {
            feeB = Q + S * (W - R);
        }
        if (feeA >= feeB) {
            fee = feeB;
        }
        else {
            fee = feeA;
        }
        cout << "#" <<test_case<< " " <<fee << endl;
    }
    return 0;
}