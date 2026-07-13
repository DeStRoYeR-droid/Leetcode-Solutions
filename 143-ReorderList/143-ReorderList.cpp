// Last updated: 13/07/2026, 22:25:56
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* current = head;
        ListNode* prev = nullptr;

        while(current != nullptr){
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
		
        ListNode* temp = slow->next;
        temp = reverse(temp);			
        
        slow->next = nullptr;
        
        ListNode* first = head;
        ListNode* second = temp;
        
        while(second){
			ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
		}

    }
};