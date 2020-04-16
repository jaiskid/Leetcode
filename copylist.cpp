class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Insert the copied node after the original one.
        for (auto *curr = head; curr; curr = curr->next->next) {
            auto *node = new RandomListNode(curr->label);
            node->next = curr->next;
            curr->next = node;
        }

        // Update random node.
        for (auto *curr = head; curr; curr = curr->next->next) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
        }

        // Seperate the copied nodes from original ones.
        RandomListNode dummy(0);
        for (auto *curr = head, *copy_curr = &dummy;
                curr;
                copy_curr = copy_curr->next, curr = curr->next) {
            copy_curr->next = curr->next;
            curr->next = curr->next->next;
        }

        return dummy.next;
    }
};