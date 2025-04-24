#include <stdio.h>

class node {
	public:
	node(int d, node* p = 0) {
		d_ = d;
		p_ = p;
	}

	int d_;
	node* p_ = 0;
	node* l_ = 0;
	node* r_ = 0;
};

class Bst {
	public:
	void Insert(int el) {
		if (!root_) root_ = new node(el);
		else Insert(root_, el);
	}

	void Insert(node* ptr, int el) {
		if (ptr -> d_ == el) return;
		if (ptr -> d_ > el) {
			if (ptr -> l_ == 0) ptr -> l_ = new node(el, ptr);
			else Insert(ptr -> l_, el);
		} else {
			if (ptr -> r_ == 0) ptr -> r_ = new node(el, ptr);
			else Insert(ptr -> r_, el);
		}
	}

	void Execute() {
		Traversal(root_);
	}

	void Traversal(node* ptr) {
		if (ptr == 0) return;
		Traversal(ptr -> l_);
		Traversal(ptr -> r_);
		printf("%d\n", ptr -> d_);
	}

	private:
	node* root_ = 0;
};

int main() {
	Bst bst;
	int n;
	while (scanf("%d", &n) != EOF) bst.Insert(n);
	bst.Execute();
}