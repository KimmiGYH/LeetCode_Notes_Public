class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr){}
    };

    // 初始化链表
    MyLinkedList() {
        dummy = new LinkedNode(0);
        size = 0;
    }
    
    // 获取第n个节点的值，如果n时非法数值直接返回-1
    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        LinkedNode* cur = dummy->next;
        while (index--)
            cur = cur->next;
        return cur->val;
    }
    
    // 头部插入节点
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = dummy->next;
        dummy->next = newNode;
        size++;
    }
    
    // 尾部插入节点
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = dummy;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = newNode;
        size++;
    }
    
    // 第n个节点前插入节点
    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = dummy;
        while (index--)
            cur = cur->next;
        newNode->next = cur->next; // cur        节点
        cur->next = newNode;       //    newNode
        size++;
    }
    
    // 删掉第n个节点
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        LinkedNode* cur = dummy;
        while (index--)
            cur = cur->next;
        LinkedNode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        size--;
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