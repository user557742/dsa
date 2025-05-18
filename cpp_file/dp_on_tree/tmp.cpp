A. Cây khổng lồ của Parsa

Giới hạn thời gian cho mỗi test: 1 giây
Giới hạn bộ nhớ cho mỗi test: 256 megabyte

Parsa có một cái cây khổng lồ với n đỉnh.

Ở mỗi đỉnh v anh ta đã ghi hai số nguyên l_v và r_v.

Để làm cho cây của Parsa trông càng huy hoàng hơn, Nima muốn gán một số a_v (l_v ≤ a_v ≤ r_v) cho mỗi đỉnh v sao cho vẻ đẹp của cây Parsa được tối đa hóa.

Cách cảm nhận vẻ đẹp của Nima khá kỳ lạ. Anh định nghĩa vẻ đẹp của cây là tổng của |a_u - a_v| trên tất cả các cạnh (u, v) của cây.

Vì cây của Parsa quá lớn, Nima không thể tối đa hóa vẻ đẹp đó một mình. Nhiệm vụ của bạn là tìm vẻ đẹp tối đa có thể cho cây của Parsa.

Đầu vào
Dòng đầu tiên chứa một số nguyên t (1 ≤ t ≤ 250) — số lượng bộ test. Mô tả từng bộ test tiếp theo.
Dòng đầu tiên của mỗi bộ test chứa một số nguyên n (2 ≤ n ≤ 10^5) — số đỉnh trong cây của Parsa.
Dòng thứ i trong số n dòng tiếp theo chứa hai số nguyên l_i và r_i (1 ≤ l_i ≤ r_i ≤ 10^9).
Mỗi trong số n - 1 dòng tiếp theo chứa hai số nguyên u và v (1 ≤ u, v ≤ n, u ≠ v) mô tả rằng có một cạnh nối giữa các đỉnh u và v trong cây của Parsa.

Đảm bảo rằng đồ thị được cho là một cây.

Đảm bảo tổng số n của tất cả các bộ test không vượt quá 2 * 10^5.

Đầu ra
Với mỗi bộ test, in ra vẻ đẹp tối đa có thể của cây Parsa.

Nếu bạn cần mình giải thích hay dịch tiếp phần nào khác, cứ nói nhé!