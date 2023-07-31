https://leetcode.cn/problems/reorder-list/description/
/**
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
    void reorderList(ListNode* head) {
        if(head==nullptr)return;
        vector<ListNode*>temp;
        ListNode *st=head;
        while(st!=nullptr)
        {
            temp.push_back(st);
            st=st->next;
        }
        int l=0,r=temp.size()-1;
        while(l<r)
        {
            ListNode *t1=temp[l];
            ListNode *t2=temp[r];
            t1->next=t2;
            l++;
            if(l==r)break;
            t2->next=temp[l];
            r--;
        }
        temp[l]->next=nullptr;
    }
};
