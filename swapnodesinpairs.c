struct ListNode* swapPairs(struct ListNode* head) {

    // Empty list or only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Dummy node
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* prev = &dummy;

    while (prev->next != NULL &&
           prev->next->next != NULL) {

        // First and second nodes
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;

        // Swap the nodes
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // Move to the next pair
        prev = first;
    }

    return dummy.next;
}
