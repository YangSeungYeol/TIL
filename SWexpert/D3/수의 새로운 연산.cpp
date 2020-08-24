#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int tc, T, p,q,x,y,xx,yy,cnt,eCnt;
bool flag;

vector <int> ampersand(int e) {
    x = 1;
    cnt = 1;
    y = cnt;
    eCnt = 1;
    flag = true;
    while (flag) {//cnt == e일떄까지 반복
        for (int i = 1; i < cnt; i++) {//덩어리
            if (eCnt == e) {
                xx = x;
                yy = y;
                flag = false;
                break;
            }
            if (y == 1) {
                x = 1;
                y = cnt;
            }
            else {
                x += 1;
                y -= 1;
            }
            eCnt++;
        }
        cnt++;
    }
    vector <int>ans;
    ans.push_back(xx);
    ans.push_back(yy);
    return ans;

}

vector<int> midOperate(int pp, int qq) {
    vector<int>ansXansY;
    int ansX = 0, ansY = 0;
    ansX = ampersand(pp)[0] + ampersand(qq)[0];
    ansY = ampersand(pp)[1] + ampersand(qq)[1];
    ansXansY.push_back(ansX);
    ansXansY.push_back(ansY);
    return ansXansY;
}

int sharp(int p, int q) {
    vector<int>ansans;
    int x, y,answer;
    ansans = midOperate(p,q);
    x = ansans[0];
    y = ansans[1];
    flag = true;
    xx = 1;
    cnt = 1;
    eCnt = 0;
    yy = cnt;
    while (flag) {
        for (int i = 1; i <= cnt; i++) {
            if (xx == x && yy == y) {
                flag = false;
                return eCnt;
            }
            
            if (yy == 1) {
                xx = 1;
                yy = cnt;
            }
            else {
                xx += 1;
                yy -= 1;
            }
            eCnt++;
        }
        cnt++;
    }
}

int main(int argc, char** argv) {
    scanf_s("%d\n", &T);
    
    for (int tc = 1; tc <= T; tc++) {
        cin >> p >> q;
        printf("#%d %d\n", tc, sharp(p, q));
    }
    return 0;
}