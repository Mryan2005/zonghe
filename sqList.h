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
	int length, proId, getPreN, proType;
	char isY;
	printf("\t\t请输入参赛人数");
	scanf("%d", &length);
	printf("\t\t请输入项目的编号");
	scanf("%d", &proId);
	printf("\t\t请输入项目要取的前n名");
	scanf("%d", &getPreN);
	printf("\t\t请输入项目的类型（0 or 1）[ 0: 男生, 1: 女生 ]");
	scanf("%d", &proType);
	if(pros->data[proId].projectId != 0) {
		printf("\t\t项目id已被占用，请修改项目id。\n");
		while(1) {
			printf("\t\t请修改项目id: ");
			scanf("%d", &proId);
			if(pros->data[proId].projectId == 0) break;
		}
	} else if(proType == 0 && proId >= girlProjectP) {
		printf("\t\t项目类型出错，这是否是女生项目 (y or n)：\n");
		scanf("%c", &isY);
		if(isY == 'y') {
			proType = 1;
		} else {
			while(1) {
				printf("\t\t请修改项目id: ");
				scanf("%d", &proId);
				if(proId < girlProjectP) break;
			}
		}
	} else if(proType == 1 && proId < girlProjectP) {
		printf("\t\t项目类型出错，这是否是男生项目 (y or n)：\n");
		scanf("%c", &isY);
		if(isY == 'y') {
			proType = 0;
		} else {
			while(1) {
				printf("\t\t请修改项目id: ");
				scanf("%d", &proId);
				if(proId < girlProjectP) break;
			}
		}
	}
    pros->data[proId].projectId = proId;
    pros->data[proId].length = length;
    pros->data[proId].getPreN = getPreN;
	int i = 1;
    for(stdu **p = pros->data[proId].data; p < pros->data[proId].data+pros->data[proId].length; ) {
		*p = (stdu*)malloc(sizeof(stdu));
		printf("\t\t");
		scanf("%s %d %d", (*p)->name, &(*p)->schoolId, &(*p)->score);
		(*p)->position = i;
		(*p)->projectid = proId;
		if(schs->data[(*p)->schoolId].schoolId == 0) {
			printf("\t\t%s所属学校不存在，该学生信息无法录入，所以被排除掉。\n", (*p)->name);
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
		a.data[i].girlsScoreSum = a.data[i].boysScoreSum = a.data[i].schoolId = 0;
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
	printf("\t\t\t比赛结果\n\t\t===================================\n");
	printf("\t\t姓名\t项目id\t排名\t成绩\n");
	for(stdu **p = schs.data[schoolId].data; p < schs.data[schoolId].data + schs.data[schoolId].length; p++) {
		printf("\t\t%s\t%d\t%d\t%d\n", (*p)->name, (*p)->projectid, (*p)->position, (*p)->score);
	}
}

void count(schools schs) {
	printf("\t\t\t团体统计\n\t\t===================================\n");
	printf("\t\t学校名\t男子团体\t女子团体\t团体总分\n");
	for(int i = 1; i < maxSchool; i++) {
		if(schs.data[i].schoolId == 0) continue;
		schs.data[i].boysScoreSum = schs.data[i].girlsScoreSum = 0;
		for(stdu **p = schs.data[i].data; p < schs.data[i].data + schs.data[i].length; p++) {
			if((*p)->projectid >= girlProjectP) {
				schs.data[i].girlsScoreSum += (*p)->score;
			} else if((*p)->projectid < girlProjectP && (*p)->projectid >= boyProjectP) {
				schs.data[i].boysScoreSum += (*p)->score;
			}
		}
		printf("\t\t%s\t%d\t\t%d\t\t%d\n", schs.data[i].schoolName, schs.data[i].boysScoreSum, schs.data[i].girlsScoreSum, schs.data[i].girlsScoreSum+schs.data[i].boysScoreSum);
	}
}
