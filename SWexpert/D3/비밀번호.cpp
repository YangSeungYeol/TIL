#include <iostream>
#include<cmath>
using namespace std;
bool flag;
int N,startPoint;
string str,str1,str2, pwd;
int main(int argc, char** argv) {
    for (int tc = 1; tc <= 10; tc++) {
        scanf_s("%d", &N);
        flag = true;
        pwd = "";
        cin >> str;
        while(flag){
            startPoint = -1;
            for (int i = 0; i < str.size()-1; i++) {
                if (str.at(i) == str.at(i + 1)) {
                    startPoint = i;
                    break;
                }
            }
            if (startPoint==-1) {//Å»ÃâÁ¶°Ç
                flag = false;
                break;
            }
            if (flag==true) {
                str1 = str.substr(0, startPoint);
                str2 = str.substr(startPoint + 2);
                str = str1 + str2;
            }
        }
        cout << "#" << tc <<" "<< str << endl;
    }
    return 0;
}