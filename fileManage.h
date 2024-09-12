#pramga once
#include <stdio.h>
#include "linkedList.h"

/*

*/
void write(FILE *fp, LList L, int mode) {
    int i = 1;
    for(LNode *p = L.head; p; p = p->next) {
        fprintf(fp, "%d %s %d %d", i, p->name, p->projectId, p->score);    // pos name projectId score
    }
}