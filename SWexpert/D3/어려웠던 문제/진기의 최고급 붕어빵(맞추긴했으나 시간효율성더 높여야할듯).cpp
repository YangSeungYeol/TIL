#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int tc, T, N, M, K,E, numOfBread,numOfCustomer,goneCustomer,maxSellTime;
int main(int argc, char** argv) {
    scanf_s("%d\n", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf_s("%d %d %d\n", &N, &M, &K);
        vector <int> arriveTime;
        bool possibility=true;
        maxSellTime = 0;
        numOfBread = 0;
        numOfCustomer = 0;
        goneCustomer = 0;
        arriveTime.clear();
        for (int i = 0; i < N; i++) {
            scanf_s("%d", &E);
            arriveTime.push_back(E);
        }
        maxSellTime = *max_element(arriveTime.begin(), arriveTime.end()) + 1;
        for (int i = 0; i < maxSellTime; i++) {
            //0ÃÊ¿¡ ¼Õ´ÔÀÌ ¿Ã¶§ ºØ¾î»§¸øÆÊ
            if (arriveTime[0] == 0) {
                possibility = false;
                break;
            }
            //MÃÊÀÇ ¹è¼ö¸¶´Ù K°³¾¿ ºØ¾î»§ÀÌ ´Ã¾î³².
            if (i!=0&&i%M == 0) {
                numOfBread += K;
            }

            //iÃÊÀÏ ¶§ ¿Â ÃÑ¼Õ´Ô ¼ö
            for (int j = 0; j < N; j++) {
                if (arriveTime[j] <= i) {
                    numOfCustomer++;
                }
            }
            //ÃÑ¼Õ´Ô¼ö - °£¼Õ´Ô¼ö = ÇØ´çÃÊ¿¡ ºØ¾î»§Áà¾ßÇÏ´Â ¼Õ´Ô¼ö
            numOfCustomer = numOfCustomer - goneCustomer;   
            if (numOfBread < numOfCustomer) {
                possibility = false;
                break;
            }
            else if(numOfCustomer!=0) {
                numOfBread -= numOfCustomer;
                goneCustomer += numOfCustomer;
                numOfCustomer = 0;
            }
        }
        printf("#%d %s\n",tc, possibility ? "Possible" : "Impossible");
    }
    return 0;
} 