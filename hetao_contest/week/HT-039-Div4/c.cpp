/*
* @Author: Yanpb
* @Date:   2024-12-26 16:04:31
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-26 18:46:23
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool isEncryptedRecipe(const std::string &original, const std::string &encrypted) {
    if (original.length() != encrypted.length()) return false;

    std::vector<int> counts(26, 0);
    for (char c : original) counts[c - 'a']++;

    for (int i = 0; i < encrypted.length(); ++i) {
        if (encrypted[i] != '*') {
            counts[encrypted[i] - 'a']--;
            if (counts[encrypted[i] - 'a'] < 0) return false;
        }
    }

    return true;
}

int main() {
    std::string originalRecipe, encryptedRecipe;
    std::cin >> originalRecipe >> encryptedRecipe;

    if (isEncryptedRecipe(originalRecipe, encryptedRecipe)) {
        std::cout << "A" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    return 0;
}