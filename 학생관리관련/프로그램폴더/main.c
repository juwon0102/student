//2021-06-09 17:36
//2021, Jun 9th
//This code will update!
//Made by Rapiz(KISHA)

#include <stdio.h>//Basic Header(�⺻���� ���) 
#include <stdlib.h>//qsort, more...(�������Լ�, ���..) 
#include <windows.h>//I will use!!(������Ʈ �Ŀ� ����!) 
#include <string.h>//�̰͵�! this too! 
#include <stdbool.h>

#define MAX 50
#define Finish 100
#define cls system("cls")
#define wait Sleep(1500)

typedef struct _student {
	char name[20];//maximum is 20 letters(�ִ� 20����) 
	int number;//�й� 
	int k, e, m;//kor, eng, math
	double avg;//average
	int sum;//���� 
	char r;//���, rank 
} student;

student stu[MAX];

bool kor = false;
bool eng = true;

//change x, y and print string
//x, y��ǥ�� �ٲٰ� ���ڿ� ��� 
void gotoxy(int x, int y, const char *s) {
	COORD p = { x, y };//input x, y
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);//change x, y
	printf("%s", s);//print string
}

//to input any value type(�ƹ� ������ �ڷ����� �Է¹ޱ� ���ؼ� 
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
	int i;//�ݺ�(loop) 
	int n;//n value(n��) 
	int mF = 500;
	
	int x = 24, y = 10;//�⺻���� x, y��ǥ(basically x, y) 
	
	int choose, clang;//�޴� ���ð�(menu choose value) 
	FILE *fin = fopen("inputInfo.txt", "r"), *fout1 = fopen("NumberList.db", "w"), *fout2 = fopen("RankList.db", "w");
	if(fin != NULL) {
		if(eng == true && kor == false) {
			gotoxy(x, y, "roading...");
			fscanf(fin, "%d", &n);
			for(i = 0; i < n; i++) {
				//input k, e, m(��, ��, �� ���� �Է¹���) 
				fscanf(fin, "%d %s %d %d %d", &stu[i].number, stu[i].name, &stu[i].k, &stu[i].e, &stu[i].m);
				stu[i].sum = stu[i].k + stu[i].e + stu[i].m;//�������ϱ� 
				stu[i].avg = stu[i].sum / 3.0;//��ձ��ϱ� 
			}
			wait;//��ٸ�(wait 1500ms) 
			Sleep(mF);//more frame(�߰� ������) 
			cls;
			system("title Rank Acquisition Program");//�������ϱ� ���α׷� 
			gotoxy(x, y, "1.print Student ID in order");//�й������� ��� 
			gotoxy(x, y+1, "2.print rank in order");//���������� ��� 
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
					printf("\n\n�� �ٲ�����ϴ�!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				} else if(clang == 1 && eng == false && kor == true){//�ѱ����ε� �� �� �� 
					printf("\n\nYou already to use That language!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				} else if(clang == 2 && eng == true && kor == false) {//�����ε� �� �� �� 
					printf("\n\nYou already to use That language!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				}
			}
		} else if(eng == false && kor == true) {
			gotoxy(x, y, "�ε���...");
			fscanf(fin, "%d", &n);
			for(i = 0; i < n; i++) {
				//input k, e, m(��, ��, �� ���� �Է¹���) 
				fscanf(fin, "%d %s %d %d %d", &stu[i].number, stu[i].name, &stu[i].k, &stu[i].e, &stu[i].m);
				stu[i].sum = stu[i].k + stu[i].e + stu[i].m;//�������ϱ� 
				stu[i].avg = stu[i].sum / 3.0;//��ձ��ϱ� 
			}
			wait;//��ٸ�(wait 1500ms) 
			Sleep(mF);//more frame(�߰� ������) 
			cls;
			system("title �������ϱ� ���α׷�");//�������ϱ� ���α׷� 
			gotoxy(x, y, "1.�й������� ����ϱ�");//�й������� ��� 
			gotoxy(x, y+1, "2.��������� ���");//���������� ��� 
			gotoxy(x, y+2, "3.����");
			gotoxy(x, y+3, "4.������\n");
			printf("�����Է� : ");
			scanf("%d", &choose);
			if(choose == 1) {
				qsort(stu, n, sizeof(student), comp1);
				cls;
				printf("�����...");
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
					printf("%d�й� %s�� ���� : %d, ���� : %d, ���� : %d, ��� : %.2lf, %c ���\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
					fprintf(fout1, "%d�й� %s�� ���� : %d, ���� : %d, ���� : %d, ��� : %.2lf, %c ���\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
				}
				wait;
				Sleep(mF + 200);
				cls;
				main();
			} else if(choose == 2) {
				qsort(stu, n, sizeof(student), comp2);
				cls;
				printf("�����...");
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
					printf("%d�й� %s�� ���� : %d, ���� : %d, ���� : %d, ��� : %.2lf, %c ���\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
					fprintf(fout2, "%d�й� %s�� ���� : %d, ���� : %d, ���� : %d, ��� : %.2lf, %c ���\n", stu[i].number, stu[i].name, stu[i].k, stu[i].e, stu[i].m, stu[i].avg, stu[i].r);
				}
				wait;
				Sleep(mF + 200);
				cls;
				main();
			} else if(choose == 3) {
				cls;
				wait;
				gotoxy(x, y, "-------��� ���-------\n\n\n");
				gotoxy(x, y+1, "1.�ѱ���");
				gotoxy(x, y+2, "2.����");
				gotoxy(x, y+3, "���� : ");
				scanf("%d", &clang);
				if(clang == 1 && eng == true && kor == false) {
					eng = false;
					kor = true;
					printf("\n\n�� �ٲ�����ϴ�!!\n\n");
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
					printf("\n\n�̹� �� �� ������Դϴ�!!\n\n");
					wait;
					Sleep(mF);
					cls;
					main();
				} else if(clang == 2 && eng == true && kor == false) {
					printf("\n\n�̹� �� �� ������Դϴ�!!\n\n");
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
			printf("���α׷��� ������! ���α׷� ��ٿ�ε� ���ּ���!\n");
			wait;
			Sleep(mF * mF);//2500ms
			exit(0);
		} else if(eng == true && kor == true) {
			cls;
			wait;
			printf("Hey, Don't joke.\n�峭ġ��������.\n");
			wait;
			Sleep(mF * mF);//2500ms
			exit(0);
		} else {
			printf("error");
			exit(0);
		}
		
	} else {
		perror("FILE ERROR ");
		exit(0);//little same return 0;(return 0;�� �����) 
	}
	
	return Finish;//return 100(same)//(���� 100�� ����) 
}
