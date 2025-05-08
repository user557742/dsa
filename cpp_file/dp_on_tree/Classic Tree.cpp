// cho một cây n đỉnh gốc là 1 mỗi đỉnh có thể tô màu trắng hoặc đen 
// ---> đếm số cách tô màu thỏa mãn sao cho hiệu số màu trắng và đen chêch lệch không quá 1 đơn vị
// tư tưởng : dp trên cây
// dp[u][j] số cách tô màu đỉnh u thỏa mãn có đúng j đỉnh là màu trắng (j<=sz[u])
// xét các đỉnh v1,v2,....,vk là những con kề u
// nếu vj1+vj2+....+vjk <= sz[u]/2;
