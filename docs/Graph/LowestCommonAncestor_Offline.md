## きもち

オフラインに最小共通祖先を求める。  
基本方針は深さ優先探索。  
LCAを求めたいペア(P, Q)が与えられているとしよう。  
Pが既に探索済みである状態で、Qに到着したとする。  
このとき、LCA(P, Q)は、Qの探索を開始した時点で、まだすべての子について探索を終えていないPの祖先のうち、最も深い頂点である。  
UnionFindを用いて、そのクエリに効率よく答えることができる。  
具体的には、ある頂点Vのすべての子について探索を終えた時、  
・その親を Par(V)とする。  
・Vの(V自身を含む)すべての子 x について UnionFind::find(x)がPar(V)となるようにしたい。  
・VとPar(V)をUniteする(Union by size)。  
・Union by sizeによって計算量が落ちるが、VとPar(V)どちらがUnionFind木の根になるかわからない。  
・VがPar(V)の根にならないように強制的にUnionFind::Root[V]をPar(V)に変更。これでOK.  


## 使い方  
- `OffLCA(vector<vector<long>>& tree, long root, vector<tuple<long,long,long>> &query)`:コンストラクタ。treeに木を、rootに根の頂点番号を、queryはLCAを求めたい二頂点とそのLCAを格納する変数をこの順にもつtupleのvectorを代入してください。  

## 計算量

$\mathrm{O}(Nα(N) + Q)$　$α$はアッカーマン関数の逆関数  
$\mathrm{O}(N + Q)$のLCAにはオーダーが劣るがこちらは定数倍がかなり軽め。  

## Tips

面白い。レートへの寄与は低そうだけど。  
