# UnionFind_rank
*素集合データ構造です。*

*集合をマージするときに経路圧縮を行うことで計算量を対数時間以下に抑えられます*
# 使用例
*問）https://atcoder.jp/contests/atc001/tasks/unionfind_a*

*解答）https://atcoder.jp/contests/atc001/submissions/19526729*
~~~
#include <vector>
#include <iostream>

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


int main(){
    int N, Q;
    std::cin >> N >> Q;
    UnionFind_rank tree(N);

    for(int i = 0 ; i < Q; i++){
        int p, a, b;
        std::cin >> p >> a >> b;
        a, b;
        if(p == 0){
            tree.Union(a, b);
        }
        else{
            if(tree.IsSame(a, b))std::cout << "Yes" << std::endl;
            else std::cout << "No" << std::endl;
        }
    }

    return 0;
}
~~~
