class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr){}
    }*head;

    // 初始化链表
    MyLinkedList() {
        head = NULL;
    }
    
    // 获取第n个节点的值，如果n时非法数值直接返回-1
    int get(int index) {
        if (index < 0)
            return -1;
        LinkedNode* p = head;
        for (int i = 0; i < index && p; i++)
            p = p->next;
        if (!p) return -1;
        return p->val;
    }
    
    // 头部插入节点
    void addAtHead(int val) {
        LinkedNode* cur = new LinkedNode(val);
        cur->next = head;
        head = cur;
    }
    
    // 尾部插入节点
    void addAtTail(int val) {
        if (!head)
            head = new LinkedNode(val);
        else {
            auto p = head;
            while (p->next)
                p = p->next;
            p->next = new LinkedNode(val);
        }
    }
    
    // 第n个节点前插入节点
    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val) {
        if (index <= 0) addAtHead(val);
        else {
            int len = 0;
            for (auto p = head; p; p = p->next)
                len ++;
            if (index == len) addAtTail(val);
            else if (index < len){
                auto p = head;
                for (int i = 0; i < index - 1; i++)
                    p = p->next;
                auto cur = new LinkedNode(val);
                cur->next = p->next;
                p->next = cur;
            }
        }
    }
    
    // 删掉第n个节点
    void deleteAtIndex(int index) {
        int len = 0;
        for (auto p = head; p; p = p->next) len++;
        if (index >= 0 && index < len) {
            if (!index) head = head->next; //删除头节点
            else {
                auto p = head;
                for (int i = 0; i < index - 1; i ++)
                    p = p->next;
                p->next = p->next->next;
            }
        }
    }

    void printLinkedList() {
        LinkedNode* cur = dummy;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int size;
    LinkedNode* dummy;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */