        auto fakehead=ListNode();
        auto p=&fakehead;
        while (l1&&l2){
            if(l1->val<l2->val){
                p->next=l1;
                l1=l1->next;
                p->next->next=nullptr;
                p=p->next;
            }
            else{
                p->next=l2;
                l2=l2->next;
                p->next->next=nullptr;
                p=p->next;
            }
        }
        if(l1)p->next=l1;
        if(l2)p->next=l2;
        return fakehead.next;