/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode*next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ptr = l1;
        ListNode *ptr2=l2;
        ListNode *l3= new ListNode();
        ListNode *curr=l3;
        int carry=0;
        while(ptr!=NULL ||ptr2!=NULL){
            int x=(ptr!=NULL)?ptr->val:0;
            int y=(ptr2!=NULL)?ptr2->val:0;
            int sum= x+y+carry;
            carry = sum/10;
            curr->next= new ListNode(sum%10);
            curr=curr->next;
            if(ptr!=NULL) ptr=ptr->next;
            if(ptr2!=NULL) ptr2=ptr2->next;   
        }
        if (carry!=0){
            curr->next= new ListNode(carry);
        }
        ListNode * te=l3;
        l3=l3->next;
        return l3;   
    }
};