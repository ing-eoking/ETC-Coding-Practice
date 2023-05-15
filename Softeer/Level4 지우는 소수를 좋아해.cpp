#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

#define INF 1000000001

#define MAXP 10007

int par[10000];

vector<int> prime;

int findPar(int idx){
	int cur = par[idx];
	while(cur != par[cur]) cur = par[cur];
	return cur;
}

void findPrime(){
	vector<bool> isPrime(10001, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i <= 100; i++){
		if(!isPrime[i]) continue;
		for(int mult = 2; i * mult <= 10000; mult++)
			isPrime[i*mult] = false;
	}
	for(int i = 1; i <= 10000; i++)
	if(isPrime[i]) prime.push_back(i);
	prime.push_back(10007);
}

int main(int argc, char** argv)
{
	findPrime();
	for(int i = 0; i < 10000; i++) par[i] = i;
	int N, M;
	scanf("%d %d", &N, &M);
	priority_queue<pair<int, pair<int, int>>> pq;
	pair<int, pair<int, int>> cur;
	int A, B, C, _min = INF;
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &A, &B, &C);
		pq.push({INF - C, {A - 1, B - 1}});
	}
	while(!pq.empty()){
		cur = pq.top();
		cur.first = INF - cur.first;
		pq.pop();
		if(par[cur.second.first] == par[cur.second.second]) continue;
		int pA = findPar(cur.second.first), pB = findPar(cur.second.second);
		if(pA < pB) par[pB] = pA;
		else par[pA] = pB;
		for(int i = 0; i < N; i++) par[i] = findPar(i);
		if(par[N - 1] == 0){
			_min = cur.first;
			break;
		}
	}
	int answer = *upper_bound(prime.begin(), prime.end(), _min);
	printf("%d", answer);
	return 0;
}
