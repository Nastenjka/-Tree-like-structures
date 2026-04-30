#include "BinaryTree.h"
#include <assert.h>

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

void BinarySearchTree::insert(const Player& player) {
    if (find(player)) {
        return;
    }

    root = insertNode(root, player, nullptr);
    tree_size++;
}

bool BinarySearchTree::findNode(Node* node, const Player& player) {
    if (node == nullptr) {
        return false;
    }

    if (node->data == player) {
        return true;
    }

    if (player < node->data) {
        return findNode(node->left, player);
    }
    else {
        return findNode(node->right, player);
    }
}

bool BinarySearchTree::find(const Player& player) {
    return findNode(root, player);
}

Node* BinarySearchTree::eraseNode(Node* node, const Player& player) {
    if (node == nullptr) return nullptr;

    if (player < node->data) {
        node->left = eraseNode(node->left, player);
        if (node->left) node->left->parent = node;
    }
    else if (player > node->data) {
        node->right = eraseNode(node->right, player);
        if (node->right) node->right->parent = node;
    }
    else {
        // 1. Немає нащадків
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            tree_size--;
            return nullptr;
        }
        // 2. Лише правий нащадок
        else if (node->left == nullptr) {
            Node* temp = node->right;
            temp->parent = node->parent;
            delete node;
            tree_size--;
            return temp;
        }
        // 2. Лише лівий нащадок
        else if (node->right == nullptr) {
            Node* temp = node->left;
            temp->parent = node->parent;
            delete node;
            tree_size--;
            return temp;
        }
        // 3. Два нащадки
        else {
            Node* successor = node->right;
            while (successor->left != nullptr)
                successor = successor->left;

            node->data = successor->data;
            node->right = eraseNode(node->right, successor->data);
        }
    }
    return node;
}

void BinarySearchTree::erase(const Player& player) {
    if (root == nullptr) return;
    root = eraseNode(root, player);
}

int BinarySearchTree::size() {
    return tree_size;
}

void BinarySearchTree::printNode(Node* node) {
    if (node == nullptr) {
        return;
    }

    printNode(node->left);

    std::cout << "Nickname: " << node->data.nickname
              << " | Rank: " << node->data.rank
              << " | XP: " << node->data.XP
              << " | Wins: " << node->data.wins
              << " | Total games: " << node->data.total_games << std::endl;


    printNode(node->right);
}


void BinarySearchTree::print() {
    if (root == nullptr) {
        std::cout << "The tree is empty\n";
        return;
    }

    std::cout << "--- Player's list ---" << "\n";
    printNode(root);
    std::cout << "----------------------" << "\n";
}


int BinarySearchTree::heightNode(Node* node) {
    if (node == nullptr) return 0;

    int left_height = heightNode(node->left);
    int right_height = heightNode(node->right);

    return std::max(left_height, right_height) + 1;
}

int BinarySearchTree::height() {
    return heightNode(root);
}

int BinarySearchTree::findInRangeNode(Node* node, const Player& min_object, const Player& max_object) {
    if (node == nullptr) {
        return 0;
    }

    int count = 0;

    if (node->data >= min_object) {
        count += findInRangeNode(node->left, min_object, max_object);
    }

    if (node->data >= min_object && node->data <= max_object) {
        count++;
    }

    if (node->data <= max_object) {
        count += findInRangeNode(node->right, min_object, max_object);
    }

    return count;
}

int BinarySearchTree::findInRange(const Player& min_object, const Player& max_object) {
    if (root == nullptr) return 0;
    int count = findInRangeNode(root, min_object, max_object);
    return count;
}