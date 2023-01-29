/*
first attempt -- but runtime error at line 31 (pow(10, idx)), 모든 값을 다 저장해놓고 하기에는 너무 큰 수가 있다.
*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int v_l1 = l1->val;
        int idx = 0;
        ListNode *next_node = l1->next;
        while(next_node != nullptr){
            idx++;
            v_l1 = v_l1 + next_node->val*pow(10,idx);
            next_node = next_node->next;
        }

        int v_l2 = l2->val;
        idx = 0;
        next_node = l2->next;
        while(next_node != nullptr){
            idx++;
            v_l2 = v_l2 + next_node->val*pow(10,idx);
            next_node = next_node->next;
        }
        int result = v_l1 + v_l2;
        ListNode *ans, *cur;
        ans = new ListNode(result%10);
        result = result / 10;
        cur = ans;
        while(result != 0){
            cur->next = new ListNode(result%10);
            result = result / 10;
            cur = cur->next;
        }
        return ans;
    }
};

/*
second attempt - 반올림을 사용해서 모든 노드를 동시에 iterate 하면서 동시에 ans list를 업데이트함.
*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans, *cur;
        ans = new ListNode();
        int v_l1 = l1->val;
        int v_l2 = l2->val;
        int upper = 0;
        int sum = v_l1 + v_l2;
        upper = sum / 10;
        sum = sum % 10;
        ans->val = sum;
        ListNode *next_l1 = l1->next;
        ListNode *next_l2 = l2->next;
        cur = ans;
        while(next_l1 != nullptr && next_l2 != nullptr){
            v_l1 = next_l1->val;
            v_l2 = next_l2->val;
            sum = v_l1 + v_l2 + upper;
            upper = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            next_l1 = next_l1->next;
            next_l2 = next_l2->next;
        }
        if(next_l1 != nullptr){
            while(next_l1 != nullptr){
                sum = upper + next_l1->val;
                upper = sum / 10;
                sum = sum % 10;
                cur->next = new ListNode(sum);
                cur = cur->next;
                next_l1 = next_l1->next;
            }
        }
        if(next_l2 != nullptr){
            while(next_l2 != nullptr){
                sum = upper + next_l2->val;
                upper = sum / 10;
                sum = sum % 10;
                cur->next = new ListNode(sum);
                cur = cur->next;
                next_l2 = next_l2->next;
            }
        }
        if(upper){
            cur->next = new ListNode(upper);
        }
        return ans;
    }
};