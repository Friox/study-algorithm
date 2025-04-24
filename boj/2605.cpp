#include <iostream>

class node {
    public:
    node(int item, node* next) {
        item_ = item;
        next_ = next;
    }
    int item_;
    node* next_;
};

class list {
    public:
    list() {
        startPtr = 0;
        size_ = 0;
    }
    void insert(int item, int offset) {
        int index = size_ - offset;
        // int offset = size_ - index;
        if (startPtr == 0) {
            startPtr = new node(item, 0);
            size_++;
            return;
        }
        if (index == 0) {
            // 제일 처음
            startPtr = new node(item, startPtr);
            size_++;
            return;
        }
        node* ptr = startPtr;
        --index;
        while (index--) ptr = ptr -> next_;
        ptr -> next_ = new node(item, ptr -> next_);
        size_++;
    }
    void print() {
        node* ptr = startPtr;
        while (ptr != 0) {
            std::cout << ptr -> item_ << ' ';
            ptr = ptr -> next_;
        }
    }

    private:
    node* startPtr;
    int size_;
};

int main() {
    list* mList = new list();
    int n, num;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> num;
        mList->insert(i, num);
    }
    mList->print();
}