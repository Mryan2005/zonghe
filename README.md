# 综合

## 功能

- [ ] 添加和删除学校
- [ ] 添加和删除项目
- [ ] 输入相关的项目名次
- [ ] 各学校的成绩单
- [ ] 团体总分报表

## 类：学生

1. 学校
2. 姓名
3. 成绩

```c
typedef struct stdu {
    char name[256];
    int score;
    int schoolId;
} stdu;
```

## 类：项目

1. 项目编号
2. 类型符（区分取前五名还是前三名）输入

```c
typedef struct project {
    char projectId;
    int getPreN;
    stdu *data[100];
    int length;
} project

typedef struct projects {
    project projects[50];
    int length;
} projects

```

## 每个项目结束时的输入

```c
1 3
1 venti mengde 100
…… …… …… ……
n ab abc 100
```

## 各学校的成绩单和团体总分报表

```c
typedef struct school {
    int schoolId;
    char schoolName[256];
    stdu *data[50];
    int length;
    int boysScoreSum;
    int girlsScoreSum;
} school;

typedef struct schools {
    school schools[20];
    int length;
} schools;
```

## 输入

```c
void add(project *pros) {
    int length, proId, getPreN;
    scanf("%d %d %d", &length, &proId, &getPreN);
    pros[proId-1].projectId = proId;
    pros[proId-1].length = length;
    pros[proId-1].getPreN = getPreN;
    for(stdu *p = pros[proId-1].data; p < pros[proId-1].data+pros[proId-1].length; p++) {
        scanf("%s %d %d", p->name, &p->schoolId, &p->score);
    }
}
void classify(project *pros, school *schs) {
    for(stdu *p = pro->data; p < pro->data+pro->length; p++) {
       schs[p->schoolId][schs->length++] = p;
    }
}
```


