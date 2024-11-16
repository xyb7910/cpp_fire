#include <iostream>
#include <vector>
#include <string>

std::string moveKthBlock(std::string S, int K) {
    std::vector<std::pair<int, int>> blocks; 
    int N = S.length();
    int start = -1;

    for (int i = 0; i <= N; ++i) {
        if (i < N && S[i] == '1') {
            if (start == -1) start = i; 
        } else {
            if (start != -1) {
                blocks.emplace_back(start, i - 1);
                start = -1;
            }
        }
    }

    int kth_start = blocks[K-1].first;
    int kth_end = blocks[K-1].second;

    std::string T = S;
    std::string kth_block = T.substr(kth_start, kth_end - kth_start + 1);
    T.erase(kth_start, kth_end - kth_start + 1);
    T.insert(blocks[K-2].second + 1, kth_block);
    return T;
}

int main() {
    std::string S;
    int N, K;


    std::cin >> N >> K;
    std::cin >> S;

    std::cout << moveKthBlock(S, K) << std::endl;

    return 0;
}