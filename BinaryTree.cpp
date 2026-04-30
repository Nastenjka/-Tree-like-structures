#include "BinaryTree.h"

Node* BinarySearchTree::insertNode(Node* node, const Player& player, Node* parent) {
    if (node == nullptr) {
        return new Node{player, nullptr, nullptr, parent};
    }

    if (player < node->data)
        node->left = insertNode(node->left, player, node);
    else if (player > node->data)
        node->right = insertNode(node->right, player, node);

    return node;
}

void BinarySearchTree ::insert(const Player& player) {
    root = insertNode(root, player, nullptr);
    tree_size++;
}

