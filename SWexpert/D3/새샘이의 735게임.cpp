#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int T,E,temp;
vector <int>numArr;
vector <int>triplePlus;

int main(int argc, char** argv) {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        numArr.clear();
        triplePlus.clear();
        for (int i = 0; i < 7; i++) {
            cin >> E;
            numArr.push_back(E);
        }
        for (int k = 0; k < 5; k++) {
            for (int j = k+1; j < 6; j++) {
                for (int i = j+1; i < 7; i++) {
                    temp = numArr[i] + numArr[j] + numArr[k];
                    triplePlus.push_back(temp);
                }
            }
        }
        sort(triplePlus.begin(), triplePlus.end(), greater<int>()); //내림차순 greater<int>()
        //reverse(triplePlus.begin(),triplePlus.end());
        unique(triplePlus.begin(), triplePlus.end());
        cout << "#" << tc << " " << triplePlus[4] << endl;
    }
    return 0;
}


