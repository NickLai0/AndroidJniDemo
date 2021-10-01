#include <stdio.h>

#define STUDENT_MAX 5
#define SCORE_MAX 4

int main(void){
	
	float score[STUDENT_MAX][SCORE_MAX]  = {
									 {56.3,75.6,25.4,80.0},
									 {55.3,77.5,55.4,60.0},
									 {86.3,75.8,25.0,80.0},
									 {96.3,75.8,65.4,80.0},
									 {86.3,75.8,25.0,80.0},
	};
	
	float studentAverage[STUDENT_MAX]={0}, courseAverage[SCORE_MAX]={0};
	int i,j;
	for(i = 0; i <STUDENT_MAX; i++) {
		for(j = 0; j <SCORE_MAX; j++) {
			studentAverage[i] += score[i][j];
			courseAverage[j] += score[i][j];
		}
		//Caculate the average score of each student.
		studentAverage[i] /= SCORE_MAX;
	}
	
	for(i = 0; i < SCORE_MAX; i++) {
		courseAverage[i] /=  STUDENT_MAX;
	}
	
	printf("StudentNo.   course1   course2   course3   course4   average\n");
	for(i = 0; i <STUDENT_MAX; i++) {
		printf("%10d",i+1);
		for(j = 0; j <SCORE_MAX; j++) {
			printf("%10.1f",score[i][j]);
		}
		printf("%10.1f\n", studentAverage[i]);
	}
	
	printf("\nCourseAve ");
	for(i = 0;i < SCORE_MAX; i++) {
		printf("%10.1f",courseAverage[i]);
	}
	
	return 0;
}