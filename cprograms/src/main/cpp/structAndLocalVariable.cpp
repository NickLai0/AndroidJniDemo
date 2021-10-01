#include <stdio.h>

struct student{
    char name[10];
    int age;
    char sex;
};

struct student inputStudent(){
    struct student stu;
    printf("Input name:");
    gets(stu.name);
    printf("Input age,sex:");
    scanf("%d,%c",&stu.age,&stu.sex);
    printf("inputStudent-> &stu=%d, stu=%d\n", &stu, stu);
    printf("inputStudent-> name=%s, age=%d, sex=%c\n",stu.name, stu.age, stu.sex);
    printf("inputStudent-> size of stu is %d\n", sizeof(stu));
    return stu;
}

int main(void) { 
	struct student stu, *p, **pp;
	stu = inputStudent();
	printf("\n");
	printf("main-> &stu=%d, stu=%d\n", &stu, stu);
	printf("main-> name=%s, age=%d, sex=%c\n",stu.name, stu.age, stu.sex);
	printf("main-> size of stu is %d\n", sizeof(stu));
	
	p = &stu;
	printf("\n");
	printf("main-> &p=%d, p=%d, *p=%d\n", &p, p,*p);
	printf("main-> name=%s, age=%d, sex=%c\n",p->name, p->age, (*p).sex);
	printf("main-> size of p is %d\n", sizeof(p));
	
	const int N = 2;
	printf("\n");
	struct student stuArr[N];
	printf("int=%d, char=%d\n",sizeof(int), sizeof(char));
	printf("sizeof(struct student)=%d, sizeof(stuArr)=%d\n",sizeof(struct student), sizeof(stuArr));
	printf("main->  &stuArr=%d, stuArr=%d \n", &stuArr,stuArr);
	for(int i =0; i<N; i++) {
		printf("main-> &stuArr[%d]=%d, stuArr[%d]=%d\n",i,&stuArr[i],i,stuArr[i]);
	}
	
	return 0;
}

