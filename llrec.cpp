#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (!head) { // check if ll is empty
        smaller = nullptr;
				larger = nullptr;
        return;
    }
    if (head->val <= pivot) { // add to smaller
        Node* rest = head->next;//remove element from original list
        head->next = nullptr;
        llpivot(rest, smaller, larger, pivot);
        head->next = smaller;
        smaller = head;
    } else { // add to larger 
        Node* rest = head->next;//remove element from original list
        head->next = nullptr;
        llpivot(rest, smaller, larger, pivot);
        head->next = larger;// add to front after iterations have completed
        larger = head;
    }
    head = nullptr; // set last trace of original list to null
}


