#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/** BstMap **/

void recursive_insert();

typedef struct Node_t {
    char* key; 
    int value;
    struct Node_t *left;
    struct Node_t *right;
} Node_t;

typedef struct BstMap {
    struct Node_t *root;

} BstMap;

Node_t* create_node(char* key, int value) {
    Node_t *node = malloc(sizeof(Node_t));

    node->key = strdup(key);
    node->value = value;
    node->left = node->right = NULL;

    return node;
}

void print_tree(Node_t *curr_node) {
    if (curr_node->left) {
        print_tree(curr_node->left);
    }
    
    printf("%s\n", curr_node->key);

    if (curr_node->right) {
        print_tree(curr_node->right);
    }
}

void recursive_insert(Node_t *curr_node, char* key, int val) {

    int result = strcmp(key, curr_node->key);

    if(result < 0) {
        if(!curr_node->left) {
            curr_node->left = create_node(key, val);
        } else {
            recursive_insert(curr_node->left, key, val);
        }
    } else if(result > 0) {
        if(!curr_node->right) {
            curr_node->right = create_node(key, val);
            return;

        } else {
            recursive_insert(curr_node->right, key, val);
        }
    } else {
        curr_node->value++;
    }
}

Node_t* find(char* key, Node_t *curr_node) {
    int result = strcmp(key, curr_node->key);

    if(result < 0) {
        if(!curr_node->left) {
            return NULL; // Key cant be found, it shouldve been down this path
        } else {
            find(key, curr_node->left);
        }
    } else if(result > 0) {
        if(!curr_node->right) {
            return NULL; // Key cant be found, it shouldve been down this path
        } else {
            find(key, curr_node->right);
        }
    } else {
        return curr_node;
    }
}

void free_tree(Node_t *node) {
    if (node) {
        free_tree(node->left);
        free_tree(node->right);
        free(node->key);
        free(node);
    }
}

int main() {

    size_t len = 0;
    char *word = NULL;
    int val = 1;
    int cnt = 0;

    BstMap *map = malloc(sizeof(BstMap));

    // Create the root node
    map->root = create_node("ItSmellsGood",2);
    
    FILE *file = fopen("brian_words.txt", "r");
    if (file == NULL) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    while (getline(&word, &len, file) != -1) {
        // Remove \n
        word[strlen(word) - 1] = 0;

            recursive_insert(map->root, word, val);
            ++cnt;
    }

    printf("All done, inserted %d words \n\n", cnt);

    /* Print the entire tree's keys */
    //print_tree(map->root);

    /* FIND A KEY k*/
    char* k = "Arne";
    Node_t *found_node = find(k, map->root);
    if(found_node) {

        printf("Key: %s has %d occurrences! \n", found_node->key, found_node->value);
    } else {
        printf("Key: %s doesnt exist! \n", k);
    }

    // Cleanup
    free_tree(map->root);
    free(map);

    return 0;
}