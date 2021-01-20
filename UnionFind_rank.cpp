#include <vector>

struct UnionFind_rank
{
    std::vector<int> par, rank;

    UnionFind_rank(){}

    UnionFind_rank(int N){
        par.resize(N), rank.resize(N, 0);
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int Find(int x){
        if(par[x] == x) return x;
        else return par[x] = Find(par[x]);
    }

    void Union(int x, int y){
        x = Find(x), y = Find(y);

        if(x == y) return;
        if(rank[x] > rank[y]){
            par[y] = x;
        }
        else if(rank[x] <= rank[y]){
            par[x] = y;
        }

        if(rank[x] == rank[y]) rank[x]++;
    }

    bool IsSame(int x, int y) {
        return Find(x) == Find(y);
    }
};