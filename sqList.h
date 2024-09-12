#pragma once
#include <stdio.h>
#include "classDefine.h"

void add(projects *pros) {
    int length, proId, getPreN;
    scanf("%d %d %d", &length, &proId, &getPreN);
    pros->data[proId-1].projectId = proId;
    pros->data[proId-1].length = length;
    pros->data[proId-1].getPreN = getPreN;
    for(stdu *p = pros->data[proId-1].data; p < pros->data[proId-1].data+pros->data[proId-1].length; p++) {
        scanf("%s %d %d", p->name, &p->schoolId, &p->score);
    }
}

void classify(stdu *stdus, int prosLength, schools *schs) {
    int insertId;
    for(stdu *p = stdus; p < stdus+prosLength; p++) {
        insertId = schs->data[p->schoolId].length;
        schs->data[p->schoolId];
    }
}

// void renewSchoolSumScore(schools *schs) {
//     for(school *p = schs; p < schs+schs)
//     for(stdu *q = schs; )
// }