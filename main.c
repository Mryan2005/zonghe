#include <stdio.h>
#include <stdlib.h>
#include "classDefine.h"
#include "fileManage.h"
#include "sqList.h"

int main() {
	int choice, schoolId, proId;
	char schoolName[256];
	schools schs = initSchoolsSqList();
	projects pros = initProjectsSqList();
	while (1) {
		printf("\n\n\t\t============== 运动会分数统计 ==============\n");
		printf("\t\t1. 添加学校\n");
		printf("\t\t2. 删除学校\n");
		printf("\t\t3. 查看参赛学校\n");
		printf("\t\t4. 添加比赛项目\n");
		printf("\t\t5. 删除比赛项目\n");
		printf("\t\t6. 查看比赛项目\n");
		printf("\t\t7. 查看比赛项目的结果（所有）\n");
		printf("\t\t8. 查看比赛项目的结果（前n名）\n");
		printf("\t\t9. 各校成绩单\n");
		printf("\t\t10. 团体总分分报表\n");
		printf("\t\t0. 退出\n");
		printf("\t\t请选择: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				if (schs.length != 0) {
					showSchools(schs);
				}
				printf("\t\t请输入学校序号和学校名称（输入\"0\"结束）\n");
				while (1) {
					printf("\t\t");
					scanf("%d", &schoolId);
					if (schoolId == 0) break;
					while(schoolId > maxSchool) {
						printf("\t\t学校编码越界，请重新输入。\n\t\t");
						scanf("%d", &schoolId);
					}
					gets(schoolName);
					while(strcmp(schoolName, " ") == 0 || strcmp(schoolName, "") == 0) {
						gets(schoolName);
					}
					addSchool(&schs, schoolId, schoolName);
				}
				break;
			case 2:
				if (schs.length == 0) {
					printf("\t\t如此空的顺序表，连我都应付不过来。\n");
					break;
				}
				showSchools(schs);
				printf("\t\t请选择：");
				scanf("%d", &schoolId);
				removeSchool(&schs, schoolId);
				break;
			case 3:
				if (schs.length == 0) {
					printf("\t\t好像没有学校参加比赛，快去让更多的学校参赛吧。\n");
					break;
				}
				showSchools(schs);
				break;
			case 4:
				if (schs.length == 0) {
					printf("\t\t好像没有学校参加比赛，快去让更多的学校参赛吧。\n");
					break;
				}
				addProject(&pros, &schs);
				break;
			case 5:
				if (schs.length == 0) {
					printf("\t\t好像没有学校参加比赛，快去让更多的学校参赛吧。\n");
					break;
				} else if (pros.length == 0) {
					printf("\t\t好像没有比赛项目，快去开始比赛吧。\n");
					break;
				}
				printf("请输入比赛项目的id（0表示退出）");
				scanf("%d", &proId);
				if(proId == 0) break;
				removeProject(&pros, proId);
				break;
			case 6:
				if (pros.length == 0) {
					printf("\t\t好像没有比赛项目，快去开始比赛吧。\n");
					break;
				}
				showProjectsList(pros);
				break;
			case 7:
				if (pros.length == 0) {
					printf("\t\t好像没有比赛项目，快去开始比赛吧。\n");
					break;
				}
				showProjectsList(pros);
				printf("\t\t请选择：");
				scanf("%d", &proId);
				if(proId < 0 || proId > maxProject) {
					printf("\t\t发生越界了！\n");
					break;
				} else if(pros.data[proId].projectId == 0) {
					printf("\t\t该比赛项目不存在！\n");
					break;
				}
				showProjectResult(pros.data[proId], schs);
				break;
			case 8:
				if (pros.length == 0) {
					printf("\t\t好像没有比赛项目，快去开始比赛吧。\n");
					break;
				}
				showProjectsList(pros);
				printf("\t\t请选择：");
				scanf("%d", &proId);
				if(proId < 0 || proId > maxProject) {
					printf("\t\t发生越界了！\n");
					break;
				} else if(pros.data[proId].projectId == 0) {
					printf("\t\t该比赛项目不存在！\n");
					break;
				}
				showProjectResult1(pros.data[proId], schs);
				break;
			case 9:
				if (schs.length == 0) {
					printf("\t\t好像没有学校参加比赛，快去让更多的学校参赛吧。\n");
					break;
				} else if (pros.length == 0) {
					printf("\t\t好像没有比赛项目，快去开始比赛吧。\n");
					break;
				}
				showSchools(schs);
				printf("\t\t请选择：");
				scanf("%d", &schoolId);
				if(proId < 0 || schoolId > maxSchool) {
					printf("\t\t发生越界了！\n");
					break;
				} else if(schs.data[schoolId].schoolId == 0) {
					printf("\t\t该学校不存在！\n");
					break;
				}
				showSchoolResult(schs, pros, schoolId);
				break;
			case 10:
				if (schs.length == 0) {
					printf("\t\t好像没有学校参加比赛，快去让更多的学校参赛吧。\n");
					break;
				} else if (pros.length == 0) {
					printf("\t\t好像没有比赛项目，快去开始比赛吧。\n");
					break;
				}
				count(schs);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("\t\t这个选择以后再来探索吧！\n");
				break;
		}
		fflush(stdin);
		printf("\t\t");
		system("pause");
		system("cls");
	}
}
