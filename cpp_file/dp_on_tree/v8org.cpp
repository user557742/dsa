//dề bài : cây n đỉnh . cho số nguyên k tìm cách xóa ít đỉnh nhất sao cho cây bị bẻ thành  các cây con có độ dài không quá k
// có sz nhỏ hơn k 
// dp[u] là số đỉnh it nhất cần loại bỏ để có sz nhỏ hơn k trong cây con gốc u 
// nếu sz[u]>k bỏ đỉnh u sz[u]=0;
// nếu v là con của u nếu thêm v thì ta sz[u]>=k thì ta có thể bỏ v hoặc bỏ u
