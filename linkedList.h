#pramga once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LNode{
    char name;
    int projectId;
    int score;
    struct LNode *next;
} LNode;

typedef struct LList {
    LNode *head;
    LNode *tail;
} LList;

LList initLList() {
    LList L;
    L.head = (LNode*)malloc(sizeof(LNode));
    L.tail = L.head;
    return L;
}

void addLNode(LList *L, int projectId, char *name, int score) {
    L->tail->next = (LNode*)malloc(sizeof(LNode));
    L->tail = L->tail->next;
    L->tail->projectId = projectId;
    strcpy(L->tail->name, name);
    L->tail->score = score;
}

void removeLNode(LList *L, char *name) {
    
}