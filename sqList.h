#pragma once
#include <stdio.h>
#include <string.h>
#include "classDefine.h"

void removeProject(projects *pros, int proId) {
	if(pros->data[proId].projectId == 0) {
		printf("\t\t��id������\n");
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
	printf("\t\t�������������");
	scanf("%d", &length);
	printf("\t\t��������Ŀ�ı��");
	scanf("%d", &proId);
	printf("\t\t��������ĿҪȡ��ǰn��");
	scanf("%d", &getPreN);
	printf("\t\t��������Ŀ�����ͣ�0 or 1��[ 0: ����, 1: Ů�� ]");
	scanf("%d", &proType);
	if(pros->data[proId].projectId != 0) {
		printf("\t\t��Ŀid�ѱ�ռ�ã����޸���Ŀid��\n");
		while(1) {
			printf("\t\t���޸���Ŀid: ");
			scanf("%d", &proId);
			if(pros->data[proId].projectId == 0) break;
		}
	} else if(proType == 0 && proId >= girlProjectP) {
		printf("\t\t��Ŀ���ͳ������Ƿ���Ů����Ŀ (y or n)��\n");
		scanf("%c", &isY);
		if(isY == 'y') {
			proType = 1;
		} else {
			while(1) {
				printf("\t\t���޸���Ŀid: ");
				scanf("%d", &proId);
				if(proId < girlProjectP) break;
			}
		}
	} else if(proType == 1 && proId < girlProjectP) {
		printf("\t\t��Ŀ���ͳ������Ƿ���������Ŀ (y or n)��\n");
		scanf("%c", &isY);
		if(isY == 'y') {
			proType = 0;
		} else {
			while(1) {
				printf("\t\t���޸���Ŀid: ");
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
			printf("\t\t%s����ѧУ�����ڣ���ѧ����Ϣ�޷�¼�룬���Ա��ų�����\n", (*p)->name);
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
	printf("\t\t\t��ǰ�ѽ��еı�����Ŀ\n\t\t===================================\n");
	printf("\t\tid\tȡǰn��\n");
	for(int i = 1; i < maxProject; i++) {
		if(pros.data[i].projectId != 0) {
			printf("\t\t%d\t%d\n", pros.data[i].projectId, pros.data[i].getPreN);
		}
	}
}

void showProjectResult(project pro, schools schs) {
	printf("\t\t\t���������ȫ����\n\t\t===================================\n");
	printf("\t\t����\t����\t�ɼ�\t����ѧУ\n");
	for(int i = 0; i < pro.length; i++) {
		printf("\t\t%d\t%s\t%d\t%s\n", i+1, pro.data[i]->name, pro.data[i]->score, schs.data[pro.data[i]->schoolId].schoolName);
	}
}

void showProjectResult1(project pro, schools schs) {
	printf("\t\t\t���������ǰn����\n\t\t===================================\n");
	printf("\t\t����\t����\t�ɼ�\t����ѧУ\n");
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
		printf("\t\t��ѧУ����ѱ�ռ��\n");
		return;
	}
	schs->data[schoolId].schoolId = schoolId;
	strcpy(schs->data[schoolId].schoolName, schoolName);
	schs->data[schoolId].girlsScoreSum = schs->data[schoolId].boysScoreSum = schs->data[schoolId].length = 0;
	(schs->length)++;
}

void removeSchool(schools *schs, int schoolId) {
	if(schoolId < maxSchool && schoolId == 0) {
		printf("\t\t������Χ��\n");
		return;
	}
	if(schs->data[schoolId].schoolId == 0) {
		printf("\t\t��ѧУ�����ڣ�\n");
		return;
	}
	schs->data[schoolId].schoolId = 0;
	--(schs->length);
}

void showSchools(schools schs) {
	printf("\n");
	printf("\t\t\t��ǰ����ѧУ\n\t\t===================================\n");
	for(int i = 1; i < maxSchool; i++) {
		if(schs.data[i].schoolId != 0) printf("\t\t %d %s \n", schs.data[i].schoolId, schs.data[i].schoolName);
	}
	printf("\n");
}

void showSchoolResult(schools schs, int schoolId) {
	printf("\t\t\t�������\n\t\t===================================\n");
	printf("\t\t����\t��Ŀid\t����\t�ɼ�\n");
	for(stdu **p = schs.data[schoolId].data; p < schs.data[schoolId].data + schs.data[schoolId].length; p++) {
		printf("\t\t%s\t%d\t%d\t%d\n", (*p)->name, (*p)->projectid, (*p)->position, (*p)->score);
	}
}

void count(schools schs) {
	printf("\t\t\t����ͳ��\n\t\t===================================\n");
	printf("\t\tѧУ��\t��������\tŮ������\t�����ܷ�\n");
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
