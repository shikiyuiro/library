## きもち

スパーステーブルだよ。  
冪等性をもつ静的な区間クエリに構築O(NlogN), クエリO(1)で答えられるよ。  
冪等性を仮定しないdisjointなスパーステーブルや、  
[構築O(N), クエリO(1)のスパーステーブル](https://shikiyuiro.github.io/library/DataStructure/SparseTable_Compact.cpp)もあるよ。  

## 使い方  
#### template<S, op, e> ここで、Sは区間の要素の型、opは区間に対する演算、eはopの単位元。 
- `SparseTable(vector<S> &v)`：コンストラクタ。配列vをもとにスパーステーブルを構築する。  
- `Element query(long l, long r)`：半開区間\[l, r)に対して演算結果を返す。  

## 計算量

構築:$\mathrm{O}(NlogN)$  
クエリ:$\mathrm{O}(1)$  

## Tips

todo:ここに使用例を書く
