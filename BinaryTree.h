#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Player.h"

struct Node {
    Player data;
    Node* left;
    Node* right;
    Node* parent;

};

struct BinarySearchTree {
    Node* root;
    int tree_size;


    /*insert(object) – додати новий елемент в дерево (без повторень)
• find(object) – перевірити наявність елемента в дереві
• erase(object) – видалити елемент з дерева
• size() – знайти кількість елементів в дереві
2.3 Реалізувати додаткові методи для роботи з деревом:
• print() – вивести всі елементи дерева (у відсортованому порядку)
• height() – знайти висоту дерева
• findInRange(minObject, maxObject) – знайти всі елементи в дереві на*/
    Node* insertNode(Node* node, const Player& player, Node* parent);
    void insert(const Player& player);
    void erase(const Player& player);
    int size();
    void print();
    int height();
    int findInRange(const Player& min_object, const Player& max_object);
};

#endif //BINARYTREE_H