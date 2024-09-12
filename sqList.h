#pragma once
#include <stdio.h>
#include <string.h>
#include "classDefine.h"

void removeProject(projects *pros, int proId) {
	if(pros->data[proId].projectId == 0) {
		printf("\t\t该id不存在\n");
		return;
	}
	for(stdu **p = pros->data[proId].data; p < pros->data[proId].data+pros->data[proId].length; p++) {
		free(*p);
	}
	pros->data[proId].projectId = pros->data[proId].getPreN = pros->data[proId].length = 0;
}

void classify(projects *pros, int proId, int prosLength, schools *schs) {
	for(stdu **p = pros->data[proId].data; p < pros->data[proId].data+prosLength; p++) {
		schs->data[(*p)->schoolId].data[schs->data[(*p)->schoolId].length++] = *p;
	}
}

void addProject(projects *pros, schools *schs) {
	int length, proId, getPreN;
	scanf("%d %d %d", &length, &proId, &getPreN);
	if(pros->data[proId].projectId != 0) {
		printf("\t\t项目id已被占用。\n");
		return;
	}
    pros->data[proId].projectId = proId;
    pros->data[proId].length = length;
    pros->data[proId].getPreN = getPreN;
	int i = 1;
    for(stdu **p = pros->data[proId].data; p < pros->data[proId].data+pros->data[proId].length; ) {
		*p = (stdu*)malloc(sizeof(stdu));
		scanf("%s %d %d", (*p)->name, &(*p)->schoolId, &(*p)->score);
		(*p)->position = i;
		(*p)->projectid = proId;
		if(schs->data[(*p)->schoolId].schoolId == 0) {
			printf("\t\t该学生所属学校不存在，该学生信息无法录入。\n");
			pros->data[proId].length--;
		} else {
			++p;
			++i;
		}
    }
	++(pros->length);
	classify(pros, proId, pros->data[proId].length, schs);
}

void showProjectsList(projects pros) {
	printf("\t\t\t当前已进行的比赛项目\n\t\t===================================\n");
	printf("\t\tid\t取前n名\n");
	for(int i = 1; i < maxProject; i++) {
		if(pros.data[i].projectId != 0) {
			printf("\t\t%d\t%d\n", pros.data[i].projectId, pros.data[i].getPreN);
		}
	}
}

void showProjectResult(project pro, schools schs) {
	printf("\t\t\t比赛结果（全部）\n\t\t===================================\n");
	printf("\t\t排名\t姓名\t成绩\t所属学校\n");
	for(int i = 0; i < pro.length; i++) {
		printf("\t\t%d\t%s\t%d\t%s\n", i+1, pro.data[i]->name, pro.data[i]->score, schs.data[pro.data[i]->schoolId].schoolName);
	}
}

void showProjectResult1(project pro, schools schs) {
	printf("\t\t\t比赛结果（前n名）\n\t\t===================================\n");
	printf("\t\t排名\t姓名\t成绩\t所属学校\n");
	for(int i = 0; i < pro.getPreN; i++) {
		printf("\t\t%d\t%s\t%d\t%s\n", i+1, pro.data[i]->name, pro.data[i]->score, schs.data[pro.data[i]->schoolId].schoolName);
	}
}

// void renewSchoolSumScore(schools *schs) {
//     for(school *p = schs; p < schs+schs)
//     for(stdu *q = schs; )
// }

schools initSchoolsSqList() {
	schools a;
	for(int i = 0; i < maxSchool; i++) {
		a.data[i].schoolId = 0;
	}
	a.length = 0;
	return a;
}

projects initProjectsSqList() {
	projects a;
	for(int i = 0; i < maxSchool; i++) {
		a.data[i].projectId = 0;
	}
	a.length = 0;
	return a;
}

void addSchool(schools *schs, int schoolId, char *schoolName) {
	if(schs->data[schoolId].schoolId != 0) {
		printf("\t\t该学校序号已被占用\n");
		return;
	}
	schs->data[schoolId].schoolId = schoolId;
	strcpy(schs->data[schoolId].schoolName, schoolName);
	schs->data[schoolId].girlsScoreSum = schs->data[schoolId].boysScoreSum = schs->data[schoolId].length = 0;
	(schs->length)++;
}

void removeSchool(schools *schs, int schoolId) {
	if(schoolId < maxSchool && schoolId == 0) {
		printf("\t\t超过范围！\n");
		return;
	}
	if(schs->data[schoolId].schoolId == 0) {
		printf("\t\t该学校不存在！\n");
		return;
	}
	schs->data[schoolId].schoolId = 0;
	--(schs->length);
}

void showSchools(schools schs) {
	printf("\n");
	printf("\t\t\t当前参赛学校\n\t\t===================================\n");
	for(int i = 1; i < maxSchool; i++) {
		if(schs.data[i].schoolId != 0) printf("\t\t %d %s \n", schs.data[i].schoolId, schs.data[i].schoolName);
	}
	printf("\n");
}

void showSchoolResult(schools schs, int schoolId) {
	for(stdu **p = schs.data[schoolId].data; p < schs.data[schoolId].data + schs.data[schoolId].length; p++) {
		printf("%d %d %s %d\n", (*p)->projectid, (*p)->position, (*p)->name, (*p)->score);
	}
}
