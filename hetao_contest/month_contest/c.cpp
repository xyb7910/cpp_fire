#include <iostream>
#include <unordered_map>
#include <sstream>
#include <iomanip>

struct ListNode {
    int key;
    std::string address;
    std::string next;
    ListNode* nextNode;
    ListNode(int k, std::string addr, std::string nxt) : key(k), address(addr), next(nxt), nextNode(nullptr) {}
};

void processList(const std::string& headAddress, int n) {
    std::unordered_map<std::string, ListNode*> addressMap;
    for (int i = 0; i < n; ++i) {
        std::string address, next;
        int key;
        std::cin >> address >> key >> next;
        addressMap[address] = new ListNode(key, address, next);
    }

    // 构建链表
    ListNode* head = addressMap[headAddress];
    ListNode* current = head;
    while (current!= nullptr) {
        current->nextNode = addressMap[current->next];
        current = current->nextNode;
    }

    std::unordered_map<int, ListNode*> seen;
    ListNode* newHead = nullptr;
    ListNode* newTail = nullptr;
    ListNode* removedHead = nullptr;
    ListNode* removedTail = nullptr;

    current = head;
    while (current!= nullptr) {
        int absKey = std::abs(current->key);
        if (seen.find(absKey) == seen.end()) {
            seen[absKey] = current;
            if (newHead == nullptr) {
                newHead = current;
                newTail = current;
            } else {
                newTail->nextNode = current;
                newTail = current;
            }
        } else {
            if (removedHead == nullptr) {
                removedHead = current;
                removedTail = current;
            } else {
                removedTail->nextNode = current;
                removedTail = current;
            }
        }
        current = current->nextNode;
    }

    if (newTail!= nullptr) {
        newTail->nextNode = nullptr;
    }
    if (removedTail!= nullptr) {
        removedTail->nextNode = nullptr;
    }

    current = newHead;
    while (current!= nullptr) {
        std::cout << current->address << " " << current->key << " " << (current->nextNode? current->nextNode->address : "-1") << std::endl;
        current = current->nextNode;
    }

    current = removedHead;
    while (current!= nullptr) {
        std::cout << current->address << " " << current->key << " " << (current->nextNode? current->nextNode->address : "-1") << std::endl;
        current = current->nextNode;
    }

    // 释放内存
    current = head;
    while (current!= nullptr) {
        ListNode* temp = current;
        current = current->nextNode;
        delete temp;
    }
}

int main() {
    std::string headAddress;
    int n;
    std::cin >> headAddress >> n;
    processList(headAddress, n);
    return 0;
}
