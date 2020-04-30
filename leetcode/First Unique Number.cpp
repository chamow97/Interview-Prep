class FirstUnique {
public:
    struct node {
        node *prev;
        node *next;
        int val;
    };
    node *head;
    node *tail;
    unordered_map<int, node*> ref;
    unordered_map<int, bool> isDuplicate;
    void addV(int currVal) {
        node *temp = new node();
        temp -> val = currVal;
        if(head == NULL) {
            temp -> next = NULL;
            temp -> prev = NULL;
            head = temp;
            tail = temp;
        } else {
            tail -> next = temp;
            temp -> prev = tail;
            tail = temp;
        }
        ref[currVal] = temp;
    }

    FirstUnique(vector<int>& nums) {
        ref.clear();
        head = NULL;
        tail = NULL;
        for(int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        if(head != NULL) {
            node *currNode = head;
            return currNode -> val;
        } else {
            return -1;
        }
    }
    
    void add(int value) {
        if(isDuplicate[value]) {
            return;
        }
        // if its already there check and remove it from unique list, else add it to back
        if(ref[value] != NULL) {
            node *curr = ref[value];
            if(curr -> prev == NULL) {
                // it means its the left most
                node *temp = curr -> next;
                if(temp == NULL) {
                    head = NULL;
                    tail = NULL;
                } else {
                    temp -> prev = NULL;
                    curr -> next = NULL;
                    head = temp;
                }
            } else {
                node *temp = curr -> prev;
                node *temp1 = curr -> next;
                temp -> next = temp1;
                if(temp1 != NULL) {
                    temp1 -> prev = temp;
                }      
            }
            ref[value] = NULL;
            isDuplicate[value] = true;
        } else {
            addV(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
