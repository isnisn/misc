#include <stdio.h>
#include <stdlib.h>

/** BstMap **/

void recursive_insert();
void* get();

typedef struct Node_t {
    void* key; // void pointer since we dont know what type key is
    void* value; // Same here
    struct Node_t *left;
    struct Node_t *right;
} Node_t;

typedef struct BstMap {
    struct Node_t *root;

} BstMap;

Node_t* create_node(void* key, void* value) {
    Node_t *node = malloc(sizeof(Node_t));
    node->key = key;
    node->value = value;

    return node;
}

void print_tree() {
    // tbi
}

// We must also pass the node, tbi
void recursive_insert(Node_t *curr_node, void* key, void* val) {

    if(key < curr_node->key) {
        printf("Go left\n");
        // Check if left exist, if it doesnt, create it!
        recursive_insert(curr_node->left, key, val);
    }

    if(key == curr_node->key) {
        printf("Duplicate\n");
    }

    if(key > curr_node->key) {
        printf("Go Right\n");
        recursive_insert(curr_node->right, key, val);
    }

}

int main() {
    BstMap *map = malloc(sizeof(BstMap));
    map->root = create_node((void*)1,(void*)2);
    // Pass pointer to root-node
    recursive_insert(map->root, (void*)2,(void*)2);

    return 0;
}