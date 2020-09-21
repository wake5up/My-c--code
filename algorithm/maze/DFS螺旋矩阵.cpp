#include <iostream>
#include <vector>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

//第一种：通过判断下一步所在位置是否填充来判断是否需要退出
void DFS1(vector<vector<char>>& v,vector<bool>& flag, int x, int y, int m, int n, char chars){
	if (chars > 'Z'){
		chars = 'A';
	}
	v[x][y] = chars;
	for (int i = 0; i<4; i++){
		if (flag[i] == true){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx >= m || ny<0 || ny >= n || v[nx][ny] != ' '){				
				if (i == 3){
					int xx = x + dx[0];
					int yy = y + dy[0];
					if (xx<0 || xx >= m || yy<0 || yy >= n || v[xx][yy] != ' ')
						return;
					flag[0] = true;
					flag[i] = false;
					i = -1;
				}
				else{
					flag[i + 1] = true;
					flag[i] = false;
				}	
				continue;
			}
			DFS1(v, flag, nx, ny, m, n, chars + 1);
		}
	}
}

//第二种：通过计数器来判断是否需要退出
void DFS2(vector<vector<char>>& v, vector<bool>& flag, int x, int y, int m, int n, char chars,int& count){
	if (chars > 'Z'){
		chars = 'A';
	}
	v[x][y] = chars;
	count++;
	if (count == m*n)
		return;
	for (int i = 0; i<4; i++){
		if (flag[i] == true){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx >= m || ny<0 || ny >= n || v[nx][ny] != ' '){
				if (i == 3){
					flag[0] = true;
					flag[i] = false;
					i = -1;
				}
				else{
					flag[i + 1] = true;
					flag[i] = false;
				}
				continue;
			}
			DFS2(v, flag, nx, ny, m, n, chars + 1,count);
			if (count == m*n)
				return;
		}
	}
}

int main(){
	int m, n;
	cin >> m >> n;
	vector<vector<char>> v(m, vector<char>(n, ' '));
	vector<bool> flag(4);
	flag[0] = true;
	int count = 0;
	DFS2(v,flag, 0, 0, m, n, 'A',count);
	for (int i = 0; i<m; i++){
		for (int j = 0; j<n; j++){
			if (j == n - 1)
				cout << v[i][j];
			else
				cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
