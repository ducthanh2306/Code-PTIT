#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int n;
vector<int> A, B, C;
vector<string> ans;
int cnt = 0;
string prev_move = "";

// Hàm kiểm tra xem đĩa lớn có được đặt lên đĩa nhỏ không
bool canMove(const vector<int>& from, const vector<int>& to) {
    if (from.empty()) {
        return false;
    }
    if (to.empty()) {
        return true;
    }
    return from.back() < to.back();
}

// Hàm kiểm tra xem nước đi có phải là quay lại nước đi trước không
bool isNotPrevious(const string& current_move) {
    if (prev_move.empty()) {
        return true;
    }
    if (current_move == "A-->B" && prev_move == "B-->A") return false;
    if (current_move == "A-->C" && prev_move == "C-->A") return false;
    if (current_move == "B-->A" && prev_move == "A-->B") return false;
    if (current_move == "B-->C" && prev_move == "C-->B") return false;
    if (current_move == "C-->A" && prev_move == "A-->C") return false;
    if (current_move == "C-->B" && prev_move == "B-->C") return false;
    return true;
}

// Hàm kiểm tra điều kiện kết thúc
bool isSolved() {
    if ((int)C.size() != n) return false;
    for (int i = 0; i < n; i++) {
        if (C[i] != n - i) return false;
    }
    return true;
}

void backtracking() {
    cnt++;
    if (ans.size() == pow(2, n) - 1 && isSolved()) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
        cout << "Tong so buoc duyet: " << cnt << endl;
        exit(0);
    }
    // Giới hạn số bước để tránh vòng lặp vô tận trong trường hợp lỗi logic khác
    if (ans.size() >= pow(2, n) - 1) {
        return;
    }

    // A -> B
    if (!A.empty() && canMove(A, B) && isNotPrevious("A-->B")) {
        int disk = A.back();
        A.pop_back();
        B.push_back(disk);
        ans.push_back("A-->B");
        prev_move = "A-->B";
        backtracking();
        prev_move = ""; // Reset prev_move sau khi backtrack
        ans.pop_back();
        B.pop_back();
        A.push_back(disk);
    }

    // A -> C
    if (!A.empty() && canMove(A, C) && isNotPrevious("A-->C")) {
        int disk = A.back();
        A.pop_back();
        C.push_back(disk);
        ans.push_back("A-->C");
        prev_move = "A-->C";
        backtracking();
        prev_move = "";
        ans.pop_back();
        C.pop_back();
        A.push_back(disk);
    }

    // B -> A
    if (!B.empty() && canMove(B, A) && isNotPrevious("B-->A")) {
        int disk = B.back();
        B.pop_back();
        A.push_back(disk);
        ans.push_back("B-->A");
        prev_move = "B-->A";
        backtracking();
        prev_move = "";
        ans.pop_back();
        A.pop_back();
        B.push_back(disk);
    }

    // B -> C
    if (!B.empty() && canMove(B, C) && isNotPrevious("B-->C")) {
        int disk = B.back();
        B.pop_back();
        C.push_back(disk);
        ans.push_back("B-->C");
        prev_move = "B-->C";
        backtracking();
        prev_move = "";
        ans.pop_back();
        C.pop_back();
        B.push_back(disk);
    }

    // C -> A
    if (!C.empty() && canMove(C, A) && isNotPrevious("C-->A")) {
        int disk = C.back();
        C.pop_back();
        A.push_back(disk);
        ans.push_back("C-->A");
        prev_move = "C-->A";
        backtracking();
        prev_move = "";
        ans.pop_back();
        A.pop_back();
        C.push_back(disk);
    }

    // C -> B
    if (!C.empty() && canMove(C, B) && isNotPrevious("C-->B")) {
        int disk = C.back();
        C.pop_back();
        B.push_back(disk);
        ans.push_back("C-->B");
        prev_move = "C-->B";
        backtracking();
        prev_move = "";
        ans.pop_back();
        B.pop_back();
        C.push_back(disk);
    }
}

int main() {
    cout << "Nhap so dia (n): ";
    cin >> n;
    for (int i = n; i >= 1; i--) {
        A.push_back(i);
    }
    backtracking();
    cout << "Khong tim thay loi giai." << endl;
    return 0;
}
