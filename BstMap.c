#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

    // Return a pointer to a Node_t struct
    return node;
}

void print_tree(Node_t *curr_node) {
    if (curr_node->left != NULL) {
        print_tree(curr_node->left);
    }
    
    printf("%d \n", (int)(uintptr_t)curr_node->key);

    if (curr_node->right != NULL) {
        print_tree(curr_node->right);
    }
}

// We must also pass the node, tbi
void recursive_insert(Node_t *curr_node, void* key, void* val) {

    if(key < curr_node->key) {
        printf("Go left\n");
        // Check if left exist, if it doesnt, create it!
        if(!curr_node->left) {
            printf("Left node on current node exist, creating \n");
            curr_node->left = create_node(key, val);
        } else {
            //Node does exist, traverse.
            recursive_insert(curr_node->left, key, val);
        }
    }

    // Duplicate or key found.
    if(key == curr_node->key) {
        printf("Duplicate\n");
    }

    if(key > curr_node->key) {
        printf("Go Right\n");

        if(!curr_node->right) {
            printf("Right node on current node exist, creating \n");
            curr_node->right = create_node(key, val);
        } else {
            //Node does exist, traverse.
            recursive_insert(curr_node->right, key, val);
        }
    }

}

int main() {

    BstMap *map = malloc(sizeof(BstMap));
    
    // Create the root node
    map->root = create_node((void*)40,(void*)2);

    // Pass pointer to root-node

    recursive_insert(map->root, (void*)20,(void*)2);
    recursive_insert(map->root, (void*)25,(void*)2);
    recursive_insert(map->root, (void*)50,(void*)2);
    recursive_insert(map->root, (void*)10,(void*)2);

    print_tree(map->root);

    return 0;
}