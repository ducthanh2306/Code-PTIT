#include <bits/stdc++.h>
using namespace std;

struct mondo{
    int w, v;
    double rt; // v/w
};

int n, maxW, best = 0;
vector<mondo> ks;

void ktao(){
    cin >> n >> maxW;
    ks.resize(n);
    for(int i = 0; i < n; i++) cin >> ks[i].w;
    for(int i = 0; i < n; i++) cin >> ks[i].v;
    for(int i = 0; i < n; i++) ks[i].rt = 1.0 * ks[i].v / ks[i].w;

    // RẤT QUAN TRỌNG: sort theo mật độ giá trị giảm dần
    sort(ks.begin(), ks.end(), [](const mondo& A, const mondo& B){
        if (A.rt != B.rt) return A.rt > B.rt;
        return A.w < B.w; // tie-break nhẹ
    });
}

// Cận trên dạng fractional knapsack (chặt, đúng “đơn vị”)
double boundFrac(int i, int sumV, int sumW){
    if (sumW > maxW) return -1e18; // quá tải thì vô hiệu
    double val = sumV;
    int wt = sumW;
    for (int j = i; j < n && wt < maxW; j++){
        if (wt + ks[j].w <= maxW){
            wt += ks[j].w;
            val += ks[j].v;                 // lấy trọn món
        } else {
            int rem = maxW - wt;            // phần còn trống
            val += rem * ks[j].rt;          // lấy “phân số” món j
            break;
        }
    }
    return val;
}

void bnb(int i, int sumV, int sumW){
    // Cập nhật best ngay khi vào
    if (sumV > best) best = sumV;
    if (i == n) return;

    // CẮT NHÁNH bằng cận trên
    double UB = boundFrac(i, sumV, sumW);
    if (UB <= best) return;

    // Nhánh "lấy i" (ưu tiên gọi trước để nâng best sớm → cắt tốt hơn)
    if (sumW + ks[i].w <= maxW)
        bnb(i + 1, sumV + ks[i].v, sumW + ks[i].w);

    // Nhánh "bỏ i"
    bnb(i + 1, sumV, sumW);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ktao();
    bnb(0, 0, 0);
    cout << best << "\n";
}
