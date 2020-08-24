#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool flag;
int tc, T,cnt;
string word;
string str;


int main(int argc, char** argv) {

    for (int tc = 1; tc <= 10; tc++) {
        scanf_s("%d\n", &T);
        str = "";
        word = "";
        cin >> word;
        cin >> str;
        cnt = 0;
        flag = true;
        cout <<"word"<< word << endl;
        cout <<"str"<< str << endl;
        while (flag) {
            for(int i = 0; i<str.length();i++){
                if (str.find(word) >= 0) {
                    cnt++;
                    str = str.substr(str.find(word)+word.length());
                    cout << "substr" << str << endl;
                }
                if (str.length() <= word.length()|| str.find(word) == str.rfind(word)) {
                    cnt++;
                    flag = false;
                    break;
                }
                
            }
        }

        printf("#%d %d\n", T, cnt);
    }
    return 0;
}