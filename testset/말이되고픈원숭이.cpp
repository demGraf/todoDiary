#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
int visit[100][100][30] = { 0 }; // �ʿ��� �Ÿ��� ��� �ִ� �迭
int graph[100][100];
int N, M;
int k;
// �����¿�
// int dir[4][2] = { {0,1}, {0,-1}, {-1, 0}, {1, 0} };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int hx[8] = { 2,2,-2,-2,1,-1,1,-1 };
int hy[8] = { 1,-1,1,-1,2,2,-2,-2 };
int BFS();
int main() {
    scanf("%d", &k);
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= M; j++) 
            scanf("%d", &graph[i][j]);
    printf("%d", BFS());
}
int BFS() {
    queue <pair<pair<int, int>, int>> q;
    q.push({ {1,1}, 0 });
    visit[1][1][0] = 0;
    while (!q.empty()) {
        int x = q.front().first.first; // <int, int>���� ù��° ��
        int y = q.front().first.second; // <int, int>���� �ι�° ��
        int wall = q.front().second; // <<int, int>, int>���� �ι�° �ε���
        q.pop(); // front�� ���� �Ŀ� ���ֱ�
        if (x == N && y == M) return visit[x][y][wall]; // N, M�� �����ϸ� visit�� ����
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {//�������� ����� ������
                if (graph[nx][ny] == 0 && visit[nx][ny][wall] == 0) {//��x �湮x
                    visit[nx][ny][wall] = visit[x][y][wall] + 1;
                    q.push({ { nx,ny }, wall });
                }
            }
        }
        for (int i = 0; i < 8 && wall < k; i++) {//���̵� �����Ҷ�
            int nx = x + hx[i];
            int ny = y + hy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {//�������� ����� ������
                if (graph[nx][ny] == 0) {//��x 
                    visit[nx][ny][wall + 1] = visit[x][y][wall] + 1;
                    q.push({ { nx,ny }, wall + 1 });
                }
            }
        }
    }
    return -1; // �Ұ����Ҷ�
}
