#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Rotation {
    vector<string> words; // 원본 문장
    int start;             // 회전 시작 위치
};

// 회전 비교 함수
bool operator<(const Rotation& a, const Rotation& b) {
    const vector<string>& A = a.words;
    const vector<string>& B = b.words;

    int na = A.size();
    int nb = B.size();

    int n = min(na, nb);

    for (int i = 0; i < n; i++) {
        string wa = A[(a.start + i) % na];
        string wb = B[(b.start + i) % nb];

        if (wa != wb)
            return wa < wb;
    }
    return na < nb;
}

int main() {
    vector<vector<string>> lines;
    string input;

    // 입력 전체 읽기
    while (getline(cin, input)) {
        if (input.empty()) continue;

        stringstream ss(input);
        vector<string> words;
        string w;

        while (ss >> w)
            words.push_back(w);

        lines.push_back(words);
    }

    // 모든 회전 생성
    vector<Rotation> rotations;

    for (auto& line : lines) {
        for (int i = 0; i < line.size(); i++) {
            rotations.push_back({ line, i });
        }
    }

    // 정렬
    sort(rotations.begin(), rotations.end());

    // 출력
    for (const auto& r : rotations) {
        const vector<string>& words = r.words;
        int n = words.size();

        // 앞부분 (기준 이전)
        for (int i = 0; i < r.start; i++)
            cout << words[i] << " ";

        cout << "\t"; // 구분 (정렬된 인덱스 느낌)

        // 기준 포함 뒷부분
        for (int i = r.start; i < n; i++)
            cout << words[i] << " ";

        cout << "\n";
    }

    return 0;
}
