#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool ok[100][100];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int bfs(vector<vector<int>> &picture, int i, int j, int m, int n, int color){
    queue<pair<int, int>> q;
    ok[i][j] = true;
    q.push(make_pair(i, j));
    int ans = 0;
    while (!q.empty()) {
        ans++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k < 4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                if(picture[i][j] == picture[nx][ny]){
                    if(ok[nx][ny] == false){
                        ok[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    return ans;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    memset(ok, false, sizeof(ok));
    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){
            if(ok[i][j] == false && picture[i][j] != 0){
                int color = picture[i][j];
                max_size_of_one_area = max(max_size_of_one_area, bfs(picture,i, j, m, n, color));
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
