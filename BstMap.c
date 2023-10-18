#include <stdio.h>
#include <stdlib.h>

/** BstMap **/

void insert();
void* get();
Node_t* create_node();

typedef struct Node_t {
    void* key; // void* since we dont know what type key is
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

}

void insert() {
    
}

int main() {
    BstMap *map = malloc(sizeof(BstMap));
    map->root = create_node((void*)1,(void*)2);

    return 0;
}