#include "treeMap.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Pair {
    Value key;
    Value value;
};

Pair* createPair()
{
    Pair* pair = malloc(sizeof(Pair));
    pair->key = wrapNone();
    pair->value = wrapNone();
    return pair;
}

typedef struct Node {
    Value value;
    Value key;
    struct Node* leftChild;
    struct Node* rightChild;
    int height;
} Node;

struct TreeMapIterator {
    Node* current;
};

struct AVLTree {
    Node* root;
    Comparator comparator;
};

int getHeight(Node* node)
{
    return node ? node->height : 0;
}

int getBalanceFactor(Node* node)
{
    return getHeight(node->rightChild) - getHeight(node->leftChild);
}

void updateHeight(Node* node)
{
    if (node) {
        int heightLeft = getHeight(node->leftChild);
        int heightRight = getHeight(node->rightChild);
        node->height = fmax(heightLeft, heightRight) + 1;
    }
}

Node* rotateRight(Node* root)
{
    Node* child = root->leftChild;
    root->leftChild = child->rightChild;
    child->rightChild = root;
    updateHeight(root);
    updateHeight(child);
    return child;
}

Node* rotateLeft(Node* root)
{
    Node* child = root->rightChild;
    root->rightChild = child->leftChild;
    child->leftChild = root;
    updateHeight(root);
    updateHeight(child);
    return child;
}

Node* balance(Node* root)
{
    if (root) {
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->rightChild) == -1)
                root->rightChild = rotateRight(root->rightChild);
            return rotateLeft(root);
        }
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->leftChild) == 1)
                root->leftChild = rotateLeft(root->leftChild);
            return rotateRight(root);
        }
    }
    return root;
}

TreeMapIterator* getIterator(TreeMap* map)
{
    TreeMapIterator* iterator = malloc(sizeof(TreeMapIterator));
    iterator->current = map->root;
    return iterator;
}

void next(TreeMapIterator* iterator, bool rightDirection)
{
    iterator->current = iterator->current ? (rightDirection ? iterator->current->rightChild : iterator->current->leftChild) : NULL;
}

Value getKey(TreeMapIterator* iterator)
{
    return iterator->current->key;
}

Value getValue(TreeMapIterator* iterator)
{
    return iterator->current->value;
}

bool hasElement(TreeMapIterator* iterator)
{
    return iterator->current;
}

Node* createNewNode(Value value, Value key)
{
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->key = key;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->height = 1;
    return node;
}

TreeMap* createTreeMap(Comparator comparator)
{
    TreeMap* tree = malloc(sizeof(TreeMap));
    tree->root = NULL;
    tree->comparator = comparator;
    return tree;
}

void freeNode(Node* node, Node* replacedNode)
{
    if (node->leftChild && node->leftChild != replacedNode) {
        freeNode(node->leftChild, replacedNode);
    }
    if (node->rightChild && node->rightChild != replacedNode) {
        freeNode(node->rightChild, replacedNode);
    }
    free(node);
}

void deleteTreeMap(TreeMap* map)
{
    if (map->root)
        freeNode(map->root, NULL);
    free(map);
}

Node* insert(Node* node, Value key, Value value, Comparator comparator)
{
    if (!node)
        return createNewNode(value, key);
    if (comparator(node->key, key) > 0)
        node->leftChild = insert(node->leftChild, key, value, comparator);
    else if (comparator(node->key, key) < 0)
        node->rightChild = insert(node->rightChild, key, value, comparator);
    else
        node->value = value;
    updateHeight(node);
    return balance(node);
}

void put(TreeMap* map, Value key, Value value)
{
    map->root = insert(map->root, key, value, map->comparator);
    updateHeight(map->root);
}

Node* getMax(Node* node)
{
    return node->rightChild ? getMax(node->rightChild) : node;
}

Value getMaximum(TreeMap* map)
{
    return getMax(map->root)->key;
}

Node* getMin(Node* node)
{
    return node->leftChild ? getMin(node->leftChild) : node;
}

Value getMinimum(TreeMap* map)
{
    return getMin(map->root)->key;
}

Node* removeMin(Node* node)
{
    if (!node->leftChild)
        return node->rightChild;
    node->leftChild = removeMin(node->leftChild);
    return balance(node);
}

Node* deleteNode(Node* root, Value key, Comparator comparator)
{
    if (!root)
        return 0;
    if (comparator(root->key, key) > 0)
        root->leftChild = deleteNode(root->leftChild, key, comparator);
    else if (comparator(root->key, key) < 0)
        root->rightChild = deleteNode(root->rightChild, key, comparator);
    else {
        Node* left = root->leftChild;
        Node* right = root->rightChild;
        root->leftChild = NULL;
        root->rightChild = NULL;
        freeNode(root, NULL);
        if (!right)
            return left;
        Node* newRoot = getMin(right);
        newRoot->rightChild = removeMin(right);
        newRoot->leftChild = left;
        return balance(newRoot);
    }
    return balance(root);
}

Pair* removeKey(TreeMap* map, Value key)
{
    Pair* pair = createPair();
    if (!(hasKey(map, key) && map->root))
        return pair;
    pair->key = key;
    pair->value = get(map, key);
    map->root = deleteNode(map->root, key, map->comparator);
    updateHeight(map->root);
    return pair;
}

Value get(TreeMap* map, Value key)
{
    Node* current = map->root;
    while (current) {
        if (map->comparator(current->key, key) == 0)
            return current->value;
        if (map->comparator(current->key, key) > 0)
            current = current->leftChild;
        else
            current = current->rightChild;
    }
    return wrapNone();
}

bool hasKey(TreeMap* map, Value key)
{
    return !isNone(get(map, key));
}

Value getUpperBound(TreeMap* map, Value key)
{
    Node* previous = NULL;
    Node* current = map->root;
    if (map->comparator(getMaximum(map), key) > 0 && map->root) {
        while (current) {
            previous = map->comparator(current->key, key) > 0 ? (previous ? (map->comparator(current->key, previous->key) < 0 ? current : previous) : current) : previous;
            if (map->comparator(current->key, key) > 0)
                current = current->leftChild;
            else
                current = current->rightChild;
        }
    }
    Value resultKey = wrapNone();
    if (previous)
        resultKey = previous->key;
    return resultKey;
}

Value getLowerBound(TreeMap* map, Value key)
{
    if (!map->root)
        return wrapNone();
    if (hasKey(map, key))
        return key;
    return getUpperBound(map, key);
}