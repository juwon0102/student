//2021-06-09 17:36
//2021, Jun 9th
//This code will update!
//Made by Rapiz(KISHA)

#include <stdio.h>//Basic Header(기본적인 헤더) 
#include <stdlib.h>//qsort, more...(퀵정렬함수, 등등..) 
#include <windows.h>//I will use!!(업데이트 후에 쓸것!) 
#include <string.h>//이것도! this too! 
#include <stdbool.h>

#define MAX 50
#define Finish 100
#define cls system("cls")
#define wait Sleep(1500)

typedef struct _student {
	char name[20];//maximum is 20 letters(최대 20글자) 
	int number;//학번 
	int k, e, m;//kor, eng, math
	double avg;//average
	int sum;//총점 
	char r;//등급, rank 
} student;

student stu[MAX];

bool kor = false;
bool eng = true;

//change x, y and print string
//x, y좌표를 바꾸고 문자열 출력 
void gotoxy(int x, int y, const char *s) {
	COORD p = { x, y };//input x, y
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);//change x, y
	printf("%s", s);//print string
}

//to input any value type(아무 종류의 자료형을 입력받기 위해서 
//function to print Student ID in order
int comp1(const void *a, const void *b) {
	student *sum1 = (student *)a;
	student *sum2 = (student *)b;
	
	if(sum1->number > sum2->number) {
		return 1;
	}
	
	if(sum1->number < sum2->number) {
		return -1;
	}
	
	return 0;
}

//function to print rank in order
int comp2(const void *a, const void *b) {
	student *sum1 = (student *)a;
	student *sum2 = (student *)b;
	
	if(sum1->avg > sum2->avg) {
		return 1;
	}
	
	if(sum1->avg < sum2->avg) {
		return -1;
	}
	
	return 0;
}

int main() {
	int i;//반복(loop) 
	int n;//n value(n값) 
	int mF = 500;
	
	int x = 24, y = 10;//기본적인 x, y좌표(basically x, y) 
	
	int choose, clang;//메뉴 선택값(menu choose value) 
	FILE *fin = fopen("inputInfo.txt", "r"), *fout1 = fopen("NumberList.db", "w"), *fout2 = fopen("RankList.db", "w");
	if(fin != NULL) {
		if(eng == true && kor == false) {
			gotoxy(x, y, "roading...");
			fscanf(fin, "%d", &n);
			for(i = 0; i < n; i++) {
				//input k, e, m(국, 영, 수 점수 입력받음) 
				fscanf(fin, "%d %s %d %d %d", &stu[i].number, stu[i].name, &stu[i].k, &stu[i].e, &stu[i].m);
				stu[i].sum = stu[i].k + stu[i].e + stu[i].m;//총점구하기 
				stu[i].avg = stu[i].sum / 3.0;//평균구하기 
			}
			wait;//기다림(wait 1500ms) 
			Sleep(mF);//more frame(추가 프레임) 
			cls;
			system("title Rank Acquisition Program");//석차구하기 프로그램 
			gotoxy(x, y, "1.print Student ID in order");//학번순으로 출력 
			gotoxy(x, y+1, "2.print rank in order");//등수순서대로 출력 
			gotoxy(x, y+2, "3.Select Language");
			gotoxy(x, y+3, "4.EXIT\n");
			printf("input number : ");
			scanf("%d", &choose);//save to choose var
			if(choose == 1) {
				qsort(stu, n, sizeof(student), comp1);
				cls;
				printf("printing...");
				wait;
				Sleep(mF + 200);
				cls;
				for(i = 0; i < n; i++) {
					if(stu[i].avg >= 10 && stu[i].avg <= 20) stu[i].r = 'F';
					if(stu[i].avg >= 20 && stu[i].avg <= 30) stu[i].r = 'E';
					if(stu[i].avg >= 30 && stu[i].avg <= 45) stu[i].r = 'D';
					if(stu[i].avg >= 45 && stu[i].avg <= 60) stu[i].r = 'C';
					if(stu[i].avg >= 60 && stu[i].avg <= 80) stu[i].r = 'B';
					if(stu[i].avg >= 80 && stu[i].avg <= 100) stu[i].r = 'A';
					printf("%dID %s Kor : %d, Eng : %d, Mat : %d, avg : %.2lf, %c Rank\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
					fprintf(fout1, "%dID %s Kor : %d, Eng : %d, Mat : %d, avg : %.2lf, %c Rank\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
				}
				wait;
				Sleep(mF + 200);
				cls;
				main();
			} else if(choose == 2) {
				qsort(stu, n, sizeof(student), comp2);
				cls;
				printf("Printing...");
				wait;
				Sleep(mF + 200);
				cls;
				for(i = 0; i < n; i++) {
					if(stu[i].avg >= 10 && stu[i].avg <= 20) stu[i].r = 'F';
					if(stu[i].avg >= 20 && stu[i].avg <= 30) stu[i].r = 'E';
					if(stu[i].avg >= 30 && stu[i].avg <= 45) stu[i].r = 'D';
					if(stu[i].avg >= 45 && stu[i].avg <= 60) stu[i].r = 'C';
					if(stu[i].avg >= 60 && stu[i].avg <= 80) stu[i].r = 'B';
					if(stu[i].avg >= 80 && stu[i].avg <= 100) stu[i].r = 'A';
					printf("%dID %s Kor : %d, Eng : %d, Mat : %d, avg : %.2lf, %c Rank\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
					fprintf(fout2, "%dID %s Kor : %d, Eng : %d, Mat : %d, avg : %.2lf, %c Rank\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
				}
				wait;
				Sleep(mF + 200);
				cls;
				main();
			} else if(choose == 3) {
				cls;
				wait;
				gotoxy(x, y, "-------Language Lists-------\n\n\n");
				gotoxy(x, y+1, "1.Korean");
				gotoxy(x, y+2, "2.English");
				gotoxy(x, y+3, "Choose : ");
				scanf("%d", &clang);
				if(clang == 1 && eng == true && kor == false) {
					eng = false;
					kor = true;
					printf("\n\nLanguage Is Changed!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				} else if(clang = 2 && eng == false && kor == true) {
					eng = true;
					kor = false;
					printf("\n\n언어가 바뀌었습니다!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				} else if(clang == 1 && eng == false && kor == true){//한국어인데 또 고를 시 
					printf("\n\nYou already to use That language!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				} else if(clang == 2 && eng == true && kor == false) {//영어인데 또 고를 시 
					printf("\n\nYou already to use That language!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				}
			}
		} else if(eng == false && kor == true) {
			gotoxy(x, y, "로딩중...");
			fscanf(fin, "%d", &n);
			for(i = 0; i < n; i++) {
				//input k, e, m(국, 영, 수 점수 입력받음) 
				fscanf(fin, "%d %s %d %d %d", &stu[i].number, stu[i].name, &stu[i].k, &stu[i].e, &stu[i].m);
				stu[i].sum = stu[i].k + stu[i].e + stu[i].m;//총점구하기 
				stu[i].avg = stu[i].sum / 3.0;//평균구하기 
			}
			wait;//기다림(wait 1500ms) 
			Sleep(mF);//more frame(추가 프레임) 
			cls;
			system("title 석차구하기 프로그램");//석차구하기 프로그램 
			gotoxy(x, y, "1.학번순으로 출력하기");//학번순으로 출력 
			gotoxy(x, y+1, "2.등수순으로 출력");//등수순서대로 출력 
			gotoxy(x, y+2, "3.언어선택");
			gotoxy(x, y+3, "4.나가기\n");
			printf("숫자입력 : ");
			scanf("%d", &choose);
			if(choose == 1) {
				qsort(stu, n, sizeof(student), comp1);
				cls;
				printf("출력중...");
				wait;
				Sleep(mF + 200);
				cls;
				for(i = 0; i < n; i++) {
					if(stu[i].avg >= 10 && stu[i].avg <= 20) stu[i].r = 'F';
					if(stu[i].avg >= 20 && stu[i].avg <= 30) stu[i].r = 'E';
					if(stu[i].avg >= 30 && stu[i].avg <= 45) stu[i].r = 'D';
					if(stu[i].avg >= 45 && stu[i].avg <= 60) stu[i].r = 'C';
					if(stu[i].avg >= 60 && stu[i].avg <= 80) stu[i].r = 'B';
					if(stu[i].avg >= 80 && stu[i].avg <= 100) stu[i].r = 'A';
					printf("%d학번 %s님 국어 : %d, 영어 : %d, 수학 : %d, 평균 : %.2lf, %c 등급\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
					fprintf(fout1, "%d학번 %s님 국어 : %d, 영어 : %d, 수학 : %d, 평균 : %.2lf, %c 등급\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
				}
				wait;
				Sleep(mF + 200);
				cls;
				main();
			} else if(choose == 2) {
				qsort(stu, n, sizeof(student), comp2);
				cls;
				printf("출력중...");
				wait;
				Sleep(mF + 200);
				cls;
				for(i = 0; i < n; i++) {
					if(stu[i].avg >= 10 && stu[i].avg <= 20) stu[i].r = 'F';
					if(stu[i].avg >= 20 && stu[i].avg <= 30) stu[i].r = 'E';
					if(stu[i].avg >= 30 && stu[i].avg <= 45) stu[i].r = 'D';
					if(stu[i].avg >= 45 && stu[i].avg <= 60) stu[i].r = 'C';
					if(stu[i].avg >= 60 && stu[i].avg <= 80) stu[i].r = 'B';
					if(stu[i].avg >= 80 && stu[i].avg <= 100) stu[i].r = 'A';
					printf("%d학번 %s님 국어 : %d, 영어 : %d, 수학 : %d, 평균 : %.2lf, %c 등급\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
					fprintf(fout2, "%d학번 %s님 국어 : %d, 영어 : %d, 수학 : %d, 평균 : %.2lf, %c 등급\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
				}
				wait;
				Sleep(mF + 200);
				cls;
				main();
			} else if(choose == 3) {
				cls;
				wait;
				gotoxy(x, y, "-------언어 목록-------\n\n\n");
				gotoxy(x, y+1, "1.한국어");
				gotoxy(x, y+2, "2.영어");
				gotoxy(x, y+3, "선택 : ");
				scanf("%d", &clang);
				if(clang == 1 && eng == true && kor == false) {
					eng = false;
					kor = true;
					printf("\n\n언어가 바뀌었습니다!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				} else if(clang = 2 && eng == false && kor == true) {
					eng = true;
					kor = false;
					printf("\n\nLanguage Is Changed!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				} else if(clang == 1 && eng == false && kor == true) {
					printf("\n\n이미 그 언어를 사용중입니다!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				} else if(clang == 2 && eng == true && kor == false) {
					printf("\n\n이미 그 언어를 사용중입니다!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				}
			}
		} else if(eng == false && kor == false) {
			cls;
			wait;
			printf("Something wrong! Please Redownload this Program!!\n");
			printf("프로그램에 오류남! 프로그램 재다운로드 해주세영!\n");
			wait;
			Sleep(mF * mF);//2500ms
			exit(0);
		} else if(eng == true && kor == true) {
			cls;
			wait;
			printf("Hey, Don't joke.\n장난치지마세요.\n");
			wait;
			Sleep(mF * mF);//2500ms
			exit(0);
		} else {
			printf("error");
			exit(0);
		}
		
	} else {
		perror("FILE ERROR ");
		exit(0);//little same return 0;(return 0;와 비슷함) 
	}
	
	return Finish;//return 100(same)//(리턴 100과 같음) 
}
