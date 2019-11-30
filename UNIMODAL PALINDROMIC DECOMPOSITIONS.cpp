/*Một dãy các số nguyên dương gọi là Palindromic nếu nó đọc từ trái qua phải và từ phải qua trái đều được một dãy như nhau. Ví dụ:

Dãy một: 23 11 15 1 37 37 1 15 11 23

Dãy hai: 1 1 2 3 4 7 7 10 7 7 4 3 2 1 1

Một dãy Palindromic là Unimodal Palindromic nếu dãy từ phần tử đầu đến phần tử giữa là một dãy không giảm, và dãy từ phần tử giữa đến phần tử cuối là một dãy không tăng. Ví dụ: dãy một ở trên KHÔNG là một dãy Unimodal Palindromic, còn dãy hai thì là dãy Unimodal Palindromic.

Một dãy Unimodal Palindromic là Unimodal Palindromic Decomposition của số nguyên N, nếu tổng các số nguyên trong dãy bằng N. Ví dụ:Tất cả các Unimodal Palindromic Decomposition của một số nguyên đầu tiên như sau:

1: (1)

2: (2), (1 1)

3: (3), (1 1 1)

4: (4), (1 2 1), (2 2), (1 1 1 1)

5: (5), (1 3 1), (1 1 1 1 1)

6: (6), (1 4 1), (2 2 2), (1 1 2 1 1), (3 3),(1 2 2 1), ( 1 1 1 1 1 1)

7: (7), (1 5 1), (2 3 2), (1 1 3 1 1), (1 1 1 1 1 1 1)

8: (8), (1 6 1), (2 4 2), (1 1 4 1 1), (1 2 2 2 1),(1 1 1 2 1 1 1), ( 4 4), (1 3 3 1), (2 2 2 2),(1 1 2 2 1 1), (1 1 1 1 1 1 1 1)

Viết chương trình tính số Unimodal Palindromic Decomposition của một số nguyên N.
*/


/*Đầu tiên nghiên cứu làm thế nào mỗi dữ liệu được lấy từ trước đó.
Ví dụ: (6), (1 4 1), (2 2 2), (1 1 2 1 1), (3 3),
(1 2 2 1), (1 1 1 1 1 1) Có tổng cộng 7.
Chia 6 thành hai số giống nhau và một số khác lớn hơn số này hoặc 0 (Miệng thật). Chỉ cần nhìn vào sau đây:
1, 6 = 1 + 1 + 4. Sau đó, anh ta có thể thêm 1 ở cả hai phía của 4 vào một giải pháp 6 (1 4 1), (1 1 2 1 1), (1 2 2 1), (1 1 1 1 1 1).
2, 6 = 2 + 2 + 2. Sau đó, anh ta có thể thêm tất cả các giá trị tối thiểu là 2 bằng hoặc nhiều hơn 2 và thêm 2 ở cả hai bên để thay đổi (2) thành (2, 2, 2)
3, 6 = 3 + 3 + 0. Lưu ý rằng điều này chỉ có thể được thực hiện khi số khác bằng 0. Ví dụ, 5 = 2 + 2 + 1 là không thể. Sau đó, anh ta có thể thêm 3 vào cả hai bên của 0 để trở thành 3, 3 trong tổng số. Tổng số trường hợp mặc định là 0 ở đây.
4 và 6 mình (6) là một nhóm 1
Vậy 6 nghiệm là 4 + 1 + 1 + 1 = 7.
Từ phân tích trên, phương trình chuyển trạng thái s [i] [j] = s [i-2 * j] [j] + s [i] [j + 1]; (1 <= j <= i / 2)
Trong đó i đại diện cho tổng dữ liệu, là n trong bài toán và j đại diện cho tổng số trường hợp trong đó tất cả các số trong tất cả các giải pháp của tôi đều lớn hơn hoặc bằng j (lý do cho định nghĩa này có thể đề cập đến bước 2 trong phân tích ở trên)
Bê tông thực hiện
1. Tiền xử lý nội dung của s [i] [j] (i> = j> i / 2) thành 1 (vì với s [i] [j] tất cả đều là 1 cho j> i / 2, vì s [ 6] [4] = s [6] [5] = s [6] [6] = 1 chỉ (6) một).
2. Tiền xử lý nội dung của s [i] [j] (i <j) thành 0 (vì theo định nghĩa j không thể lớn hơn i.)
3. Xử lý trước nội dung của s [0] [j] thành 1 (vì khi bạn cần gọi s [0] [j], điều đó có nghĩa là một số được chia thành hai số giống nhau và kết quả tất nhiên là một)
4. Thêm một vòng lặp for (j = i / 2; j> = 1; j--) vào mỗi vòng lặp của for (i = 2; i <= nax; i ++) và đảo ngược kết quả mỗi lần
Quy trình thực hiện chương trình
Khi tôi = 6
1. j = 3 s [6] [3] = s [6-3 * 2] [3] + s [6] [4] = 1 + 1 = 2; có hai loại giải pháp có giải pháp lớn hơn 3 in ( 3, 3) (6);
2.j = 2 s [6] [2] = s [2] [2] + s [6] [3] = 1 + 2 = 3;
3. j = 1 s [6] [1] = s [4] [1] + s [6] [2] = 4 + 3 = 7; s [6] [1] lưu trữ tất cả dữ liệu khi n = 6 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

unsigned int dp[250][250];

class Solution {
public:
    unsigned int fun(int n) {
        for(int num=0; num<250; num++) {
            for (int k=0; k<250; k++) {
                if (num==0) {
                    dp[num][k] = 1;
                }
                else if (k>num){
                    dp[num][k] = 0;
                }
                else {
                    dp[num][k] = 1;
                }
            }
        }
        for (int num=2; num<=n; num++)
        {
            for (int k=num/2; k>=1; k--)
            {
                dp[num][k] = dp[num-2*k][k] + dp[num][k+1];
            }
        }
        return dp[n][1];
    }
};

int main() 
{
    Solution sol;
    int n;
    cin >> n;
    while(n != 0) {
        cout << n << ' ' << sol.fun(n) << endl;
        cin >> n;
    }
    return 0;
}
