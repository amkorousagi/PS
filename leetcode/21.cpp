/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        ListNode* tail = nullptr;
        ListNode* temp;
        while(1){
            if(l1!= nullptr && l2!=nullptr){
                if(l1->val < l2->val){
                    temp = new ListNode(l1->val);
                    if(res == nullptr){
                        res = temp;
                        tail = temp;
                    }else{
                        tail->next = temp;
                        tail = temp;
                    }
                    l1 = l1->next;
                }else{
                    temp = new ListNode(l2->val);
                    if(res == nullptr){
                        res = temp;
                        tail = temp;
                    }else{
                        tail->next = temp;
                        tail = temp;
                    }
                    l2 = l2->next;
                }
            }else{
                if(l1==nullptr && l2==nullptr){
                    break;
                }
                ListNode* rest = (l1!=nullptr)?l1:l2;
                if(res!= nullptr){
                    tail->next = rest;
                    break;
                }else{
                    res = rest;
                    break;
                }
            }
        }
        return res;
    }
};