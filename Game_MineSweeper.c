#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int M;
int N;
#define MINE -1
///*Mang B luu bang dô` mi`n*/
int B[1000][1000];
/*Mang T luu trang tha´i ca´c o^*/
int T[1000][1000];
void init(){//HAM IN BAN DO MIN
    int i,j;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            B[i][j] = 0;
            T[i][j] = 0;
        }
    }
    B[1][2] = MINE;
    B[3][1] = MINE;
}
 
void init_mines(int k){//HAM RANDOM BOME
//	time_t t;
//	srand((unsigned) time(&t);
//	srand(time(0));
	srand((time)NULL);
	int i,j;
	for(i = 0; i < M; i++) 
        for(j = 0; j < N; j++) 
            B[i][j] = 0;
        
    int cnt=0,r,c;
    while(cnt<k){
    	r=rand()%M;
		c=rand()%N; 
	if(B[r][c] != MINE){
		B[r][c]=MINE;
		cnt++;
		}
	}
} 
 
void count_mines(){
	int i,j,h,c;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(B[i][j] == MINE){
		        for(h=i-1;h<=i+1;h++){
		            for(c=j-1;c<=j+1;c++){
		                if(B[h][c] != MINE)
		                    B[h][c]++;
		            }
		        }
	        }
		}
    }
}
 
void printMap1(){//IN BAN DO THEO QUY TAC 1
    int i,j,k;
    printf("     ");
    for(j=0; j<N; j++){
		if(j >= 10){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252);  // to mau hong dam
			printf("%2d   ", j);
		}
		else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252); // to mau hong dam
			printf("%d    ", j);
		}
	}
	printf("\n");
    printf("   ");
    for(k=0; k<=N*5-1; k++){ // In khung vien ngang 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); // Mau hong cho vien
		if(k == 0)
			printf("%c", 201); // Dk in duong cong xuong ben trai
		else if(k == N*5-1)   // Dk in duong cong xuong ben phai
			printf("%c", 187);		
		else printf("%c", 205); 
	}
	printf("\n");
    for(i=0;i<M;i++){
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252);  // to mau do
        printf("%2d", i);
        for(j=0;j<N;j++){
            if(B[i][j]==MINE){
                if(j == 0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); //Mau hong cho vien
					printf(" %c", 186); // in vien dung
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252); // to mau do cho X
					printf(" X ");
				}
				else if(j == N-1){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252); // to mau do cho X
					printf("   X ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253);  // Mau hong cho vien
					printf("%c", 186); // in vien dung
				}
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252); // to mau do
					printf("   X ");
				}
			}
			else if(B[i][j]==0){
				if(j == 0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); //Mau hong cho vien
					printf(" %c", 186); // in vien dung
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),250); // Mau xanh la cua o ko min 8 o xung quanh
					printf(" O ");
				}
				else if(j == N-1){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),250); // to mau xanh cho O
					printf("   O ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253);  // Mau hong cho vien
					printf("%c", 186); // in vien dung
				}
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),250); // to mau xanh la cua o ko co min 8 o xung quanh
					printf("   O "); // hinh tron dac biet
				}	
			} 
			else{
				if(j == 0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); //Mau hong cho vien
					printf(" %c", 186); // in vien dung
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); // Mau hong cho so
					printf(" %d ", B[i][j]);
				}
				else if(j == N-1){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); // mau hong cho vien
					printf("   %d ", B[i][j]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253);  // Mau hong cho vien
					printf("%c", 186); // in vien dung
				}
				else{ 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); // to mau hong cho so
					printf("   %d ", B[i][j]); 
				}
			} 
        }
        printf("\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); // Mau hong cho vien
        printf("   ");	
		for(k=0; k<=N*5-1; k++){  // in khung vien ngang cac dong con lai
			if(i == M-1 && k == 0) // DK in duong cong nguoc len ben trai
				printf("%c", 200);
			else if(i == M-1 && k == N*5-1)  // Dk in duong cong nguoc len ben phai
				printf("%c", 188);
			else if(k == 0 && i != M-1 ) // Dk in duong vien nga ba ben trai
				printf("%c", 204);
			else if(k == N*5-1 && i != M-1)
				printf("%c", 185);			
			else printf("%c", 205);
		}
		printf("\n"); 
    }
}
 
void printMap2(){//IN BAN DO THEO QUY TAC 2
	int i, j, k;
	printf("     ");
	for(j=0; j<N; j++){
		if(j >= 10){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252); // to mau hong dam
			printf("%2d   ", j);
		}
		else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252); // to mau hong dam
			printf("%d    ", j);
		}
	}	
	printf("\n");
	printf("   ");
	for(k=0; k<=N*5-1; k++){ // In khung vien ngang 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); // Mau hong cho vien
		if(k == 0)
			printf("%c", 201); // Dk in duong cong xuong ben trai
		else if(k == N*5-1)   // Dk in duong cong xuong ben phai
			printf("%c", 187);		
		else printf("%c", 205); 
	}
	printf("\n");
	for(i=0; i<M; i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252); // to mau hong dam
		printf("%2d", i);
 		for(j=0; j<N; j++){
 			if(T[i][j]==0){
				if(j == 0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); //Mau hong cho vien
					printf(" %c", 186);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),243); // Mau xanh bien nhat che o
					printf("%c%c%c", 178, 178, 178);
				}
				else if(j == N-1){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),243); // Mau xanh nhat cho o
					printf("  %c%c%c", 178, 178, 178);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253);  // Mau hong cho vien
					printf("%c", 186);
				}
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),243); // to mau xanh bien nhat che o
					printf("  %c%c%c", 178, 178, 178); // 3 Hinh chu nhat che o	
				}
			}	
			else if(B[i][j]==MINE){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252); // to mau do
				printf("  X"); // sua lai in bom thanh X nhe
			} 
 			else if(B[i][j] == 0){
				if(j == 0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); //Mau hong cho vien
					printf(" %c", 186); // in vien dung
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),250); // Mau xanh la cua o ko min 8 o xung quanh
					printf("%c%c%c", 178, 178, 178);
				}
				else if(j == N-1){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),250); // to mau xanh la cho o ko co min 8 xung quanh
					printf("  %c%c%c", 178, 178, 178);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253);  // Mau hong cho vien
					printf("%c", 186); // in vien dung
				}
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),250); // to mau xanh la cua o ko co min 8 o xung quanh
					printf("  %c%c%c", 178, 178, 178); // hinh tron dac biet
				}		
			}
 			else{
				if(j == 0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); //Mau hong cho vien
					printf(" %c", 186); // in vien dung
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); // Mau hong cho so
					printf(" %d ", B[i][j]);
				}
				else if(j == N-1){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253);
					printf("   %d ", B[i][j]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253);  // Mau hong cho vien
					printf("%c", 186); // in vien dung
				}
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); // to mau hong cho so
					printf("   %d ", B[i][j]); 
				}
			}
		}
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253); // Mau hong cho vien
		printf("   ");	
		for(k=0; k<=N*5-1; k++){  // in khung vien ngang cac dong con lai
			if(i == M-1 && k == 0) // DK in duong cong nguoc len ben trai
				printf("%c", 200);
			else if(i == M-1 && k == N*5-1)  // Dk in duong cong nguoc len ben phai
				printf("%c", 188);
			else if(k == 0 && i != M-1 ) // Dk in duong vien nga ba ben trai
				printf("%c", 204);
			else if(k == N*5-1 && i != M-1)
				printf("%c", 185);			
			else printf("%c", 205);
		}
		printf("\n");	
	}
}
int count_remain(){//HAM DEM SO O CHUA MO
	int i,j,count=0;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(T[i][j] == 0){
				count++;
			}
		}
	}
	return count;
}
 
void open_cell_1(int r,int c){//HAM MO O R,C THEO QUY TAC 1
    T[r][c]=1;
}
 
void open_cell_2(int r, int c) {
	int i, j;
    T[r][c] = 1;
    if (B[r][c] == 0) {
        for (i = -1; i < 2; i++) {
            for ( j = -1; j < 2; j++) {
                if (i != 0 || j != 0) { 
                    if (r + i >= 0 && r + i < M && c + j >= 0 && c + j < N) {
                        // gán nh?ng dó b?ng 1, t?c là m? 8 ô xung quanh.
                        T[r + i][c + j] = 1;
                    }
                }
            }
        }
    }
}
 
void open_cell_3(int r,int c){
	int i, j;
	if(T[r][c]==1) return;
	else{
    T[r][c] = 1;
    if (B[r][c] == 0) {
        for ( i = -1; i < 2; i++) {
            for ( j = -1; j < 2; j++) {
                if (i != 0 || j != 0) { 
                    if (r + i >= 0 && r + i < M && c + j >= 0 && c + j < N) {
                        if(T[r + i][c + j] == 0){
                        	open_cell_3(r+i,c+j);
						}     
                    }
                }
            }
        }
    }
	}
}

 
int main(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);  // to mau tim
	printf("						%c%c   %c%c %c %c%c   %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c     %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("						%c %c %c %c %c %c %c  %c %c       %c       %c     %c %c       %c       %c     %c %c       %c     %c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("						%c  %c  %c %c %c  %c %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c  %c  %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("						%c     %c %c %c   %c%c %c             %c %c %c %c %c %c       %c       %c       %c       %c  %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("						%c     %c %c %c    %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c   %c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c       %c%c%c%c%c%c%c %c    %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("\n");
	printf("SELECT MODE\n");
	printf("1.EASY: MAP 9x9 | 10 MINES\n");
	printf("2.NORMAL: MAP 16 x 16 | 40 MINES\n");
	printf("3.HARD: MAP 16 x 30 | 100 MINES\n");
	printf("4.MASTER: MAP 45 x 60 | 999 MINES\n");
	int n;
	scanf("%d", &n);
	if(n==1){
	int r,c;
	M=9,N=9;
	int k=10;
	init_mines(k);
	count_mines();
	while(1){
		
		printMap2();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249); // to mau xanh nuoc bien
		printf("Nhap o can mo: ");
		scanf("%d%d", &r, &c);
		while( r < 0 || r >= M || c < 0 || c >= N){
			printf("\n");
			printf("Nhap o can mo: ");
			scanf("%d%d", &r, &c);
			
		}	
		
		if(B[r][c] == MINE){
			printf("\n");
			printMap1();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244); // to mau do cho you lose
			printf("You lose.\n");
			break;
		}		 
		open_cell_3(r, c);
		if(count_remain() == k){
			printf("\n");
			printMap2();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),242); // to mau xanh cho you win
			printf("You win.\n");
			break;
		}
		printf("\n");	
	}
}
	else if(n==2){
	int r,c;
	M=16,N=16;
	int k=40;
	init_mines(k);
	count_mines();
	while(1){
		
		printMap2();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249); // to mau  xanh nuoc bien
		printf("Nhap o can mo: ");
		scanf("%d%d", &r, &c);
		while( r < 0 || r >= M || c < 0 || c >= N){
			printf("\n");
			printf("Nhap o can mo: ");
			scanf("%d%d", &r, &c);
			
		}	
		
		if(B[r][c] == MINE){
			printf("\n");
			printMap1();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244); // to mau do cho you lose
			printf("You lose.\n");
			break;
		}		 
		open_cell_3(r, c);
		if(count_remain() == k){
			printf("\n");
			printMap2();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),242); // to mau xanh cho you lose
			printf("You win.\n");
			break;
			}
		printf("\n");	
		}
	}else if(n==3){
	int r,c;
	M=16,N=30;
	int k=100;
	init_mines(k);
	count_mines();
	while(1){
		
		printMap2();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249); // to mau xanh nuoc bien
		printf("Nhap o can mo: ");
		scanf("%d%d", &r, &c);
		while( r < 0 || r >= M || c < 0 || c >= N){
			printf("\n");
			printf("Nhap o can mo: ");
			scanf("%d%d", &r, &c);
			
		}	
		
		if(B[r][c] == MINE){
			printf("\n");
			printMap1();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244); // to mau do cho you lose
			printf("You lose.\n");
			break;
		}		 
		open_cell_3(r, c);
		if(count_remain() == k){
			printf("\n");
			printMap2();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),242); // to mau xanh cho you win
			printf("You win.\n");
			break;
			}
		printf("\n");	
		}
	}else{
	int r,c;
	M=60,N=45;
	int k=2699;  // chi co 1 o ko co min :))
	init_mines(k);
	count_mines();
	while(1){
		
		printMap2();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245); // to mau xanh nuoc bien
		printf("Nhap o can mo: ");
		scanf("%d%d", &r, &c);
		while( r < 0 || r >= M || c < 0 || c >= N){
			printf("\n");
			printf("Nhap o can mo: ");
			scanf("%d%d", &r, &c);
			
		}	
		
		if(B[r][c] == MINE){
			printf("\n");
			printMap1();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244); // to mau do cho you lose
			printf("You lose.\n");
			break;
		}		 
		open_cell_3(r, c);
		if(count_remain() == k){
			printf("\n");
			printMap2();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),242); // to mau xanh cho you win
			printf("You win.\n");
			break;
		}
		printf("\n");	
	}
}	
	return 0;
}
