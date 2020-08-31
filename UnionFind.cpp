#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
    int n;
    vector<int> par; // 親の番号
    vector<int> siz; // サイズを表している。

    // 初期化する。parは自身を指す（iotaは 0 ~ nまでの数字を順に入れていく）
    // size(siz) は最初はすべて１
    UnionFind(int n) : n(n){
        par.resize(n);
        iota(par.begin(),par.end(),0);
        siz.assign(n,1);
    }

    // 頂点の親を求める。
    // 再帰関数を使っており、経路圧縮もしている。
    int root(int x){
        // ここは親の処理。
        if (par[x] == x){
            return x;
        }

        //経路圧縮をしながら値を返す。
        // par[x] = root(par[x]);
        // return par[x];
        // と同じ意味。
        return par[x] = root(par[x]);
    }

    // unite :: a と bを同じグループに入れる。
    // もし初めから同じなら何もしない。
    void unite(int a,int b){
        int ra = root(a);
        int rb = root(b);

        if(ra == rb){
            return;
        }

        // サイズの大きい方にサイズの小さいほうを合成するので、swapしている。
        if (siz[ra] < siz[rb]){
            swap(ra,rb);
        }
        // サイズが大きい方に小さいのを合体
        // 小さいほうの親は大きい方の親になる。
        siz[ra] += siz[rb];
        par[rb] = ra;
    }

    //　同じグループかどうか判定するには、親が一緒かどうかをみたらよい
    bool same(int x,int y){
        return root(x) == root(y);
    }

    // 頂点が含まれるグループの頂点を求める。
    int get_size(int x){
        return siz[root(x)];
    }
};

int main(){
    // --------This code is for abc177 D Friends ----------
    // int n,m;
    // cin >> n >> m;
    // UnionFind uf(n);
    // for(int i=0 ; i<m ; i++){
    //     int a,b; cin >> a >> b;
    //     uf.unite(a,b);
    // }

    // int ans = 0;
    // for(int i=0 ; i<n ; i++){
    //     ans = max(ans,uf.get_size(i));
    // }

    // cout << ans << endl;
    // ------------end code-----------------------

    // --------This is ATC001 B UnionFind------------
    int n,q; cin >> n >> q;
    UnionFind uf(n);
    for(int i=0 ; i<q ; i++){
        int p,a,b; cin >> p >> a >> b;
        if(p == 0){
            uf.unite(a,b);
        }else{
            cout << (uf.same(a,b)? "Yes" : "No") << endl;
        }
    }
}