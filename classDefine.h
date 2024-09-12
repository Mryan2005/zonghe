#pragma once
#include <stdio.h>
#include <stdlib.h>
#define maxSchool 21
#define maxProject 51
#define boyProjectP 1
#define girlProjectP 31

typedef struct stdu {
    char name[256];
    int score;
    int schoolId;
	int position;
	int projectid;
} stdu;

typedef struct project {
    char projectId;
    int getPreN;
    stdu *data[30];
    int length;
} project;

typedef struct projects {
    project data[maxProject];
    int length;
} projects;

typedef struct school {
    int schoolId;
    char schoolName[256];
    stdu *data[2000];
    int length;
    int boysScoreSum;
    int girlsScoreSum;
} school;

typedef struct schools {
    school data[maxSchool];
    int length;
} schools;
