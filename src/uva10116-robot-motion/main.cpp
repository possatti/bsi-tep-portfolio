// UVa 10116 - Robot Motion

#include <iostream>
#include <map>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

#define FOR(ii, i0, in) for((ii)=(i0); (ii)<(in); (ii)++)
#define FOR2d(ii, jj, i0, j0, in, jn) FOR(ii, i0, in) FOR(jj, j0, jn)
#define OFFSET 256

int i, j, I, J,C, Nth[]={-1,+0}, Sth[]={+1,0}, Est[]={0,+1}, Wst[]={0,-1};

map<int, int*> m;
int g[1000][1000];

void go(int y, int x, int d){
	assert(y>=0 && x>=0 && y<I && x<J);
	assert(g[y][x]<OFFSET);

	int y2 = y+m[g[y][x]][0], x2=x+m[g[y][x]][1];
	g[y][x] = d;

	if(y2<0 || x2<0 || y2>=I || x2>=J)
		printf("%d step(s) to exit\n", d-OFFSET+1);
	else if(g[y2][x2] >= OFFSET)
		printf("%d step(s) before a loop of %d step(s)\n", g[y2][x2] -OFFSET, d - g[y2][x2]+1);
	else go(y2, x2, d+1);
}

int main() {
	char c;

	m['N'] = Nth, m['S'] = Sth, m['E'] = Est, m['W'] = Wst;
	while((cin >> I >> J >> C) && I){
		memset(g, 0, sizeof g);
		FOR2d(i, j, 0, 0, I, J)
		{cin >> c; g[i][j]=c; }
		go(0, C-1, OFFSET);
	}

	return 0;
}
