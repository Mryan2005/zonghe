#pragma once
#include <stdio.h>
#include "linkedList.h"

/*
in:
    - 文件指针
    - 链表 
    - mode: 类型
        - 1: 个人
        - 2: 团体
*/
void write(FILE *fp, LList L) {
    int i = 1;
    for(LNode *p = L.head; p; p = p->next) {
        fprintf(fp, "%d %s %d %d", i, p->name, p->projectId, p->score);    // pos name projectId score
    }
}

void read(FILE *fp);