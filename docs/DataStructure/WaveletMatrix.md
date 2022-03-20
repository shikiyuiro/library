## 使い方  
- `WaveletMatrix(vector<int64_t> &_v)`：配列_vをもとにウェーブレット行列を構築する。  
- `int64_t range_freq(int64_t L, int64_t R, int64_t lower, int64_t upper)`:区間`[L, R)`内のlower以上upper未満の値の個数を返す。  
- `int64_t range_Kth_max(int64_t L, int64_t R, int64_t K)`:区間`[L, R)`内でK番目に大きな値を返す。Kは0-indexed.  
- `int64_t range_Kth_min(int64_t L, int64_t R, int64_t K)`:区間`[L, R)`内でK番目に小さな値を返す。Kは0-indexed.  
- `int64_t range_successor(int64_t L, int64_t R, int64_t value)`:区間`[L, R)`内の値のうちvalueより真に大きい最小のものを返す。存在しない場合-1を返す。  
- `int64_t range_predecessor(int64_t L, int64_t R, int64_t value)`:区間`[L, R)`内の値のうちvalueより真に小さい最大のものを返す。存在しない場合-1を返す。  

## 使用例
<a href="https://judge.yosupo.jp/submission/83011" target="_blank">yosupo judge - Range Kth Smallest</a>
