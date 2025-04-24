#include <cmath>
#include <iostream>
#include <vector>
using std::cin;

struct Node {
    int value;
    Node *parent, *left, *right;
};

class Tree {
    std::vector<Node> nodes;
    int level = 0, levelIdx = 0;

    public:
    Tree() {

    }

    void addLevel(std::string &value) {
        printf("[Tree] %d Level에 추가, %d개의 노드\n", level + 1, (int)value.length());
        if (value.length() != pow(2, level)) return;
        if (level == 0) {
            nodes.push_back({ value[0] - 'A' + 1, NULL, NULL, NULL });
        } else {
            for (int i = 0; i < value.length(); i++) {
                Node *parent = &nodes[levelIdx + (i / 2)];
                nodes.push_back({ value[i] - 'A' + 1, parent, NULL, NULL });
                if (i % 2 == 0) parent->left = &*nodes.rbegin();
                else parent->right = &*nodes.rbegin();
                printf("%d\n", parent->left->value);
            }
            levelIdx += value.length();
        }
        level++;
    }

    int length() {
        return nodes.size();
    }

    void postOrder(Node *node) {
        if (node == NULL) return;
        printf("%d\n", node->left->value);
        postOrder(node->left);
        postOrder(node->right);
        printf("value: %d\n", node->value);
    }

    Node* getRoot() {
        if (level == 0) return NULL;
        printf("root: %d\n", nodes[0].value);
        return &nodes[0];
    }
};



int main() {
    int N, idx = 0;
    std::string str;
    Tree tree = Tree();
    cin >> N;
    while (N--) {
        cin >> str;
        tree.addLevel(str);
    }
    tree.postOrder(tree.getRoot());
}