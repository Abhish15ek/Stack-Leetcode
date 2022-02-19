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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vec;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            vec.push_back(temp->val);
            temp=temp->next;
        }
        vector<int> ans;
        stack<int> s;
        for(int i=vec.size()-1;i>=0;i--)
        {
            if(s.size()==0)
            {
                ans.push_back(0);
            }
            else if(s.size()>0 and s.top()>vec[i])
                ans.push_back(s.top());
            else if(s.size()>0 and s.top()<=vec[i])
            {
                while(s.size()>0 and s.top()<=vec[i])
                    s.pop();
                if(s.size()==0)
                    ans.push_back(0);
                else
                    ans.push_back(s.top());
            }
            s.push(vec[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};