#include <iostream>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    ListNode* newHead = new ListNode();
    ListNode* cur = newHead; 
    while (a != b && b != nullptr) {
        if (a->val <= b->val) {
            cur->next = a;
            a = a->next;
        }
        else {
            cur->next = b;
            b = b->next;
        }
        cur = cur->next;
    }

    while (a != b) {
        cur->next = a;
        cur = cur->next;
        a = a->next;
    }
    while (b != nullptr) {
        cur->next = b;
        cur = cur->next;
        b = b->next;
    }
    return newHead->next;
}

// Sort an unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* firstHead = head;
    ListNode* secondHead = head->next;
    while (secondHead && secondHead->next) {
        firstHead = firstHead->next;
        secondHead = secondHead->next->next;
    }
    ListNode* secondList = firstHead->next;
    firstHead->next = nullptr;
    ListNode* firstList = mergeSortList(head);
    ListNode* lastList = mergeSortList(secondList);
    mergeLists(firstList, lastList);
}

int main() {
    ;

}