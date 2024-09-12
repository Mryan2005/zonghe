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
		printf("\n\n\t\t============== �˶������ͳ�� ==============\n");
		printf("\t\t1. ���ѧУ\n");
		printf("\t\t2. ɾ��ѧУ\n");
		printf("\t\t3. �鿴����ѧУ\n");
		printf("\t\t4. ��ӱ�����Ŀ\n");
		printf("\t\t5. ɾ��������Ŀ\n");
		printf("\t\t6. �鿴������Ŀ\n");
		printf("\t\t7. �鿴������Ŀ�Ľ�������У�\n");
		printf("\t\t8. �鿴������Ŀ�Ľ����ǰn����\n");
		printf("\t\t9. ��У�ɼ���\n");
		printf("\t\t10. �����ֱַܷ���\n");
		printf("\t\t0. �˳�\n");
		printf("\t\t��ѡ��: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				if (schs.length != 0) {
					showSchools(schs);
				}
				printf("\t\t������ѧУ��ź�ѧУ���ƣ�����\"0\"������\n");
				while (1) {
					printf("\t\t");
					scanf("%d", &schoolId);
					if (schoolId == 0) break;
					gets(schoolName);
					addSchool(&schs, schoolId, schoolName);
				}
				break;
			case 2:
				if (schs.length == 0) {
					printf("\t\t��˿յ�˳������Ҷ�Ӧ����������\n");
					break;
				}
				showSchools(schs);
				printf("\t\t��ѡ��");
				scanf("%d", &schoolId);
				removeSchool(&schs, schoolId);
				break;
			case 3:
				if (schs.length == 0) {
					printf("\t\t����û��ѧУ�μӱ�������ȥ�ø����ѧУ�����ɡ�\n");
					break;
				}
				showSchools(schs);
				break;
			case 4:
				if (schs.length == 0) {
					printf("\t\t����û��ѧУ�μӱ�������ȥ�ø����ѧУ�����ɡ�\n");
				}
				addProject(&pros, &schs);
				break;
			case 5:
				if (schs.length == 0) {
					printf("\t\t����û��ѧУ�μӱ�������ȥ�ø����ѧУ�����ɡ�\n");
					break;
				} else if (pros.length == 0) {
					printf("\t\t����û�б�����Ŀ����ȥ��ʼ�����ɡ�\n");
					break;
				}
				scanf("%d", &proId);
				removeProject(&pros, proId);
				break;
			case 6:
				if (pros.length == 0) {
					printf("\t\t����û�б�����Ŀ����ȥ��ʼ�����ɡ�\n");
					break;
				}
				showProjectsList(pros);
				break;
			case 7:
				if (pros.length == 0) {
					printf("\t\t����û�б�����Ŀ����ȥ��ʼ�����ɡ�\n");
					break;
				}
				showProjectsList(pros);
				printf("\t\t��ѡ��");
				scanf("%d", &proId);
				showProjectResult(pros.data[proId], schs);
				break;
			case 8:
				if (pros.length == 0) {
					printf("\t\t����û�б�����Ŀ����ȥ��ʼ�����ɡ�\n");
					break;
				}
				showProjectsList(pros);
				printf("\t\t��ѡ��");
				scanf("%d", &proId);
				showProjectResult1(pros.data[proId], schs);
				break;
			case 9:
				if (schs.length == 0) {
					printf("\t\t����û��ѧУ�μӱ�������ȥ�ø����ѧУ�����ɡ�\n");
					break;
				} else if (pros.length == 0) {
					printf("\t\t����û�б�����Ŀ����ȥ��ʼ�����ɡ�\n");
					break;
				}
				showSchools(schs);
				printf("\t\t��ѡ��");
				scanf("%d", &schoolId);
				showSchoolResult(schs, pros, schoolId);
				break;
			case 10:
				if (schs.length == 0) {
					printf("\t\t����û��ѧУ�μӱ�������ȥ�ø����ѧУ�����ɡ�\n");
					break;
				} else if (pros.length == 0) {
					printf("\t\t����û�б�����Ŀ����ȥ��ʼ�����ɡ�\n");
					break;
				}
				count(schs);
				break;
			case 0:
				exit(0);
				break;
			default:
				//TODO
				break;
		}
	}
}
