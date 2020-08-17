#include <iostream>
#define MAX 10
using namespace std;

int col[MAX];
int N, total;

bool check(int level)
{
    for (int i = 0; i < level; i++)
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)// �밢���̰ų� ���� ����
            return false;
    //col[i]�� �ǹ��ϴ� ���� X��ǥ, i�� �ǹ��ϴ°��� Y��ǥ�̹Ƿ� ���̰� �����ϴٸ� �밢���� �ִٰ� �� �� �ִ�.
    return true;
}

void nqueen(int x)
{
    if (x == N) {
        total++;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            col[x] = i; // �ش� ��ġ�� ���� ��ġ
            if (check(x)) { // ��ȿ�ϴٸ� �������� �� ��ġ, ��ȿ�����ʴٸ� �ٸ� ��ġ�� �� ��ġ ����
                nqueen(x + 1);
            }
        }
    }
}
int main(int argc, char** argv) {
    int T, test_case;
    cin >> T;
    for (test_case = 1; test_case <= T; test_case++) {
        total = 0;
        cin >> N;
        nqueen(0);
        cout << "#" << test_case << " " << total << endl;
    }
    
}