#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10


typedef struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct Map {
    Node *hashmap[MAX_SIZE];
} Map;

Map *init()
{    
    Map *map = malloc(sizeof(Map)); 
    for(int i = 0; i < MAX_SIZE; i++){
        map->hashmap[i] = NULL;
    }
    return map;

}

int hash (char *key){
    int hash = 0;
    for(int i = 0; i < strlen(key); i++){
        hash += ((int)key[i] * 10) / 3;
    }
    return hash % MAX_SIZE;
}


void print_map(Map * map){
    printf("----------------------\n");
    printf("Printing Dictionary: (-1 = EMPTY) \n");
    int counter = 1;
    for(int i = 0; i < MAX_SIZE; i++){
        if(map->hashmap[i] != NULL){
            printf("%i. %s - %i\n", counter++, map->hashmap[i]->key, map->hashmap[i]->value);
            Node * curr = map->hashmap[i];
            while(curr->next){
                curr = curr->next;
                i += 1;
                printf("%i. %s - %i\n", counter++, curr->key, curr->value);
            }
        }
    }
    printf("----------------------\n");

}


int insert_map(Map *map, char *key, int value){
    int index = hash(key);

    Node *new_node = malloc(sizeof(Node));
    new_node->key = malloc(sizeof(char) * strlen(key) + 1);
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = NULL;
    
    if(map->hashmap[index] != NULL){
        // If its not null then there's a collison.
        Node * next_node = map->hashmap[index]
        ; 
        while(next_node->next != NULL){
            next_node = next_node->next;
        }
        next_node->next = new_node;
        return 1;
    }
    map->hashmap[index] = new_node;
    return 0;
}


void remove_hash(Map *map, char *key){
    int index = hash(key);
    Node * curr = map->hashmap[index];
    Node *prev = NULL;
    // if curr is not null then

    // if they are not same and curr is not null
    while(strcmp(curr->key, key) && curr != NULL){
        prev = curr;
        curr = curr->next;   
    }
    if(!prev){
        if(curr->next){
            map->hashmap[index] = curr->next;
        } else {
            map->hashmap[index] = NULL;

        }
    } else {

        if(curr->next){
            prev->next = curr->next;
        } else {
            prev->next = NULL;
        }
    }
    free(curr->key);
    free(curr);
}

int main(){

    Map * dict = init();
    insert_map(dict ,"Zainan", 10);
    insert_map(dict ,"Zayan", 20);
    insert_map(dict ,"Zaher", 40);
    insert_map(dict ,"Zahra", 30);

    print_map(dict);
    remove_hash(dict, "Zayan");
    print_map(dict);

    return 1;
}