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
    root = insertNode(root, player, nullptr);
    tree_size++;
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
            tree_size--; // <-- Додаємо зменшення розміру
            return nullptr;
        }
        // 2. Лише правий нащадок
        else if (node->left == nullptr) {
            Node* temp = node->right;
            temp->parent = node->parent;
            delete node;
            tree_size--; // <-- Додаємо зменшення розміру
            return temp;
        }
        // 2. Лише лівий нащадок
        else if (node->right == nullptr) {
            Node* temp = node->left;
            temp->parent = node->parent;
            delete node;
            tree_size--; // <-- Додаємо зменшення розміру
            return temp;
        }
        // 3. Два нащадки
        else {
            Node* successor = node->right;
            while (successor->left != nullptr)
                successor = successor->left;

            node->data = successor->data;

            // ЗВЕРНИ УВАГУ: Тут tree_size-- писати НЕ ПОТРІБНО.
            // Рекурсивний виклик eraseNode піде шукати successor->data,
            // потрапить у випадок 1 або 2 вище, і там розмір успішно зменшиться!
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
    // Запускаємо рекурсію починаючи з кореня
    printNode(root);
    std::cout << "----------------------" << "\n";
}


