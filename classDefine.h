#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct stdu {
    char name[256];
    int score;
    int schoolId;
} stdu;

typedef struct project {
    char projectId;
    int getPreN;
    stdu *data[30];
    int length;
} project;

typedef struct projects {
    project data[50];
    int length;
} projects;

typedef struct school {
    int schoolId;
    char schoolName[256];
    stdu *data[50];
    int length;
    int boysScoreSum;
    int girlsScoreSum;
} school;

typedef struct schools {
    school data[20];
    int length;
} schools;