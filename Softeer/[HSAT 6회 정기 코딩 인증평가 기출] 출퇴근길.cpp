#include<iostream>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
	int n, m, x, y, s, t;
	scanf("%d %d", &n, &m);
	vector<vector<int>> road(n), reroad(n);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
		x--; y--;
		road[x].push_back(y);
		reroad[y].push_back(x);
	}
	scanf("%d %d", &s, &t); s--; t--;
	vector<bool> go(n, false), come(n, false), rgo(n, false), rcome(n, false);
	go[s] = go[t] = true;
	come[s] = come[t] = true;
	queue<int> g, c, rg, rc;
	int cur;
	g.push(s); c.push(t); rg.push(t); rc.push(s);
	while(!g.empty()){
		cur = g.front();
		g.pop();
		for(int i : road[cur])
			if(!go[i]){
				go[i] = true;
				g.push(i);
			}
	}
	while(!c.empty()){
		cur = c.front();
		c.pop();
		for(int i : road[cur])
			if(!come[i]){
				come[i] = true;
				c.push(i);
			}
	}
	while(!rg.empty()){
		cur = rg.front();
		rg.pop();
		for(int i : reroad[cur])
			if(!rgo[i]){
				rgo[i] = true;
				rg.push(i);
			}
	}
	while(!rc.empty()){
		cur = rc.front();
		rc.pop();
		for(int i : reroad[cur])
			if(!rcome[i]){
				rcome[i] = true;
				rc.push(i);
			}
	}
	int answer = 0;
	for(int i = 0; i < n; i++)
		answer += rcome[i] & rgo[i] & come[i] & go[i];
	printf("%d", answer - 2);
	return 0;
}
