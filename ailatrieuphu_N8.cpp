#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <Windows.h>
#define MAX 100
#define MAX_LIST 7
static int flag;
typedef struct QUESTION	
{
	char cauHoi[256];
	char A[256];
	char B[256];
	char C[256];
	char D[256];
	char dapAn;	
}ques;
//======================================================================================
// ho tro ham tu van tai cho
struct help
{
	int soghe;
	char dapantv;// dap an tu van	
};
ques *list; // luu danh sach
int n = 0; //so cau hoi
int score = 0; //diem so
//======================================================================================
void ngancach()
{
	printf("===============================================================================================\n");
}
void cont()
{
	printf("\nPress enter to continue...");
	fflush(stdin);
	getchar();
}
void luatChoi()
{
	ngancach();
	printf("=============================================[KET QUA]=======================================\n");
	if(score<5)
		printf("\t[he thong]: ban khong vuot qua muc mot cua chung toi nen ban khong co tien thuong\n");
	else if(score==5 || score<10)
	{
		printf("\t[he thong]: so diem cua ban tro ve moc 1: %d\n",500);
	}
	else if(score==10 || score<15)
	{
		printf("\t[he thong]: so diem cua ban tro ve moc 2: %d\n",1500);
	}
	else if(score==15)
	{
		printf("\t[he thong]: so diem cuoi cung cua ban la: %d\n",4500);
	}
	printf("//--------------------------------------------------------------------------------------------------------\n");
}
void theEnd()
{
	int k;
	char chon;
		printf("0 >> dung lai!\n");
		printf("1 >> tiep tuc!\n");
		fflush(stdin);
		scanf("%d",&chon);
		chon=toupper(chon);	// doi chu hoa	
		switch(chon)
		{
			case 0:
				printf("[He thong]: Nhan [enter] de chac chan ve quyet dinh cua minh!\n");
				getch();
				printf("[Lai Van Sam]: Hen gap lai ban lan sau!\n");
				luatChoi();
			exit(0);
			case 1:
				printf("[He thong]: Nhan [enter] de chac chan ve quyet dinh cua minh!\n");
				getch();
		}
}
//============================================================================================
bool docFile()
{
	FILE *f;
	char buff[256];
	f = fopen("input.txt","r");
	if (f==NULL)
	{
		printf("[he thong]:khong co du lieu cau hoi!\n");
		cont();
		return false;
	}
	n = 0;
	while(fgets(buff,256,f))
	{
		strcpy(list[n].cauHoi,buff);
		strcpy(list[n].A,fgets(buff,256,f));
		strcpy(list[n].B,fgets(buff,256,f));
		strcpy(list[n].C,fgets(buff,256,f));
		strcpy(list[n].D,fgets(buff,256,f));
		list[n].dapAn=fgets(buff,256,f)[0];
		n++;
	}
	fclose(f);
	printf("[He thong]: %d cau hoi duoc load!\n",n);
	cont();
	return true;
}

void ghiFile()
{
	FILE *f;
	char buff[256];
	int i;
	f = fopen("input.txt","a");
	for(i=0;i<n;i++)
	{
		fputs(list[i].cauHoi, f);
		fputs(list[i].A, f);
		fputs(list[i].B, f);
		fputs(list[i].C, f);
		fputs(list[i].D, f);
		buff[0]=list[i].dapAn;
		buff[1]='\0';
		fputs(buff,f);
		fputs("\n",f);
	}
	fclose(f);
	printf("[He thong]: %d cau hoi updated! \n",n);
	cont();
}

void creatQ()
{
	ques q;
	char t;
	do{
	printf("nhap cau hoi: \n");
	scanf(" %[^\n]s%c", &q.cauHoi);
	strcat(q.cauHoi,"\n");
	printf("A: ");
	scanf(" %[^\n]s", &q.A);
	strcat(q.A,"\n");
	printf("B: ");
	scanf(" %[^\n]s", &q.B);
	strcat(q.B,"\n");
	printf("C: ");
	scanf(" %[^\n]s", &q.C);
	strcat(q.C,"\n");
	printf("D: ");
	scanf(" %[^\n]s", &q.D);
	strcat(q.D,"\n");
	printf("Nhap dap an dung(A, B, C, D): ");
	scanf(" %c", &q.dapAn);
	q.dapAn=toupper(q.dapAn); //doi chu thuong thanh chu hoa

	list[n] = q;
	n++;
	
	printf("[he thong]: tiep tuc tao cau hoi(Y/N): ");
	scanf(" %c", &t);
	}while(t=='Y' || t=='y');
}

//------------------------------------------------------------------------------
void hoi_y_kien_khan_gia(int ma_tro_giup)
{
	// random cho dap an A
	int a=rand()%70;
		printf("\n A: ");
		
		for(int i=0;i<a/3;i++)// (*-*) moi mat cuoi tuong ung voi 3%
				printf("||");
		printf("%d %%\n",a);
		
	// random cho dap an B
	int b=rand()%(100-a);
		printf("\n B: ");
		
		for(int i=0;i<b/3;i++)
				printf("||");
		printf("%d %%\n",b);
		
	// random cho dap an C
	int c=rand()%(100-a-b);
		printf("\n C: ");
		
		for(int i=0;i<c/3;i++)
			printf("||");
		printf("%d %%\n",c);
	// phan tram cua %D=100-%A-%B-%C	
	int d=100-a-b-c;
		printf("\n D: ");
		for(int i=0;i<d/3;i++)
			printf("||");	
		printf("%d %%\n",d);	
}
void tu_van_tai_cho(int ma_tro_giup,help a[2])// mang chua nguoi choi	
{

	for(int i=0;i<3;i++)
	{
	 a[i].soghe=rand()%(100-1)+1;
	 int k=rand()%3;// random dap an
		switch(k)
		{
			case 0:a[i].dapantv='A';
				break;
			case 1:a[i].dapantv='B';
				break;
			case 2:a[i].dapantv='C';
				break;
			default:a[i].dapantv='D';
				break;
		}
	printf("\n >>chuc mung  ban  la nguoi thu %d  trong 3 nguoi- may man tham gia vao tro giup tu van tai cho ! ",i+1);
	printf("\n ***so: %d :theo toi %c la dap an dung! ",a[i].soghe,a[i].dapantv);
	}	
	printf("\n");
}
//ham qua tang
void qua(help a[2],int i_x)// i_x ma tro giup
{
	for(int i=0;i<3;i++)
	{
		if((list[i_x].dapAn,a[i].dapantv)==0 )  //so sanh chuoi
			printf("ban %d tra loi dung se duoc nhan nhan duoc 500k  phan thuong tu chuong trinh!\n",a[i].soghe);	
		else 
			printf(" rat tiec ban %d  chua nhan dc qua cua chuong trinh \n",a[i].soghe);
		
	}
	printf("\n");
		
}
//50/50
void chiadoi(int i)//  i ma tro giup
{	
	printf("cau %d: ",i);	
	for(int j=0;j<n;j++)// toi gt i
	if(j==i)
	{
		printf("%s\n",list[j].cauHoi);
		if(list[j].dapAn =='A')
			{
				 int n1=rand()%2; // 0-2 ->BCD  
				 printf("A:%s\n",list[j].A);                  
				 switch(n1)                           
				 {                                    
				 case 0:	printf("B:%s\n",list[j].B);// xuat A
				 	break;                              
				 case 1:	printf("C:%s\n",list[j].C);// xuat B
				 	break;                              
				 default:	printf("D:%s\n",list[j].D);// xuat C
				 	break;		                            
				}		                                  	
			}
		if(list[j].dapAn =='B')// B dung
		{
			int n2=rand()%2;// 0-2 ->ACD 
			printf("B:%s\n",list[j].B);
			
			switch(n2)
			{
				case 0: printf("A:%s\n",list[j].A);
					break;
				case 1:	printf("C:%s\n",list[j].C);
					break;
				default: printf("D:%s\n",list[j].D);
					break;	
			}
		}
		
		if(list[j].dapAn =='C')// C dung
			{
				printf("C:%s\n",list[j].C);
				int n3=rand()%2;// 0-2 ->ABD 
				switch(n3)
				{
				case 0:	printf("A:%s\n",list[j].A);
					break;
				case 1:	printf("B:%s\n",list[j].B);
					break;
				default: printf("D:%s\n",list[j].D);
					break;
				}
			}
			if(list[j].dapAn =='D')// D dung
				 {
					printf("D:%s\n",list[j].D);
					int n4=rand()%2;// 0-2 ->ABC 
						switch(n4)
					{
					case 0:	printf("A:%s\n",list[j].A);
						break;
					case 1:	printf("B:%s\n",list[j].B);
						break;
					default: printf("C:%s\n",list[j].C);
						break;	
					}
				 }
	}
}
//goi dien thoai nguoi than
void goi_dien_thoai(int ma_tro_giup)
{
	char p_help[20];                                 
	char dap_an;// chuoi luu dap an
	// nhap nguoi tro giup cho ban
	printf("\n ban muon nhan su tro giup tu :");
	fflush(stdin);
	gets(p_help);
	fflush(stdin);
	int nn=rand()%3;// 4 d.a gan ->0,1,2,(1 bien mac dinh)
		switch(nn)
		{
			case 1:dap_an='A';
				break;
			case 2:dap_an='B';
				break;
			case 3:dap_an='C';
				break;
			default:dap_an='D';
				break;
		}
		// in da dap an tro giup
	printf("\n Lai Van Sam: ban vua nhan duoc su tro giup tu: %s ",p_help);
	printf("\n %s: theo toi %c la dap an dung\n",p_help,dap_an);		
}
//===============================================================================
// su tro giup tu chuyen gia
void hoi_chuyen_gia(int ma_tro_giup)
{
	char dap_an;// chuoi luu dap an

	int nn=rand()%3;// nn:la bien luu phan du %3 , lay 4 d.a gan ->0,1,2,1 bien mac dinh
	switch(nn)// kq ngau nhien tuong ung voi cac dap an ABCD;
	{ 
		case 1:dap_an='A';//kq random=1->A
			break;
		case 2:dap_an='B';//kq random=2->B
			break;
		case 3:dap_an='C';//kq random=3->C
			break;
		default:dap_an='D';// cac random # mac dinh la D
			break;
	}
	switch(ma_tro_giup)// in dap an voi tuong chuyen gia
	{
		case 1 :printf("\n Gs Ngo Bao Chau:\"%c dap an nay chac chan la dap an dung!\"\n",dap_an);
			break;
		case 2:printf("\n Hoang Yen:\"%c dap an nay chac chan la dap an dung!\" -co ay khang dinh\n",dap_an);
			break;
		case 3:printf("\n Cuong dollar:\" chi co the la %c !\"\n",dap_an);
			break;
		case 4:printf("\n ngoc han:\" neu toi la ban toi se chon %c !\"\n",dap_an);
			break;
		default:printf("\n Truong Tan Sang:\" chi co the la %c !\"\n",dap_an);// #(1,2,3,4) thi dc mac dinh la obama
			break;
	}
}
//=========================================================================================
//-----------------------------------------------------------------------
//bo tro giup
void xoa(int chon,int a[6],int &m)
{
	for(int i=chon;i<m;i++)
	{
		a[i]=a[i+1];
	}
	m--;
	
}
int chon;
void menu2(int a1[6], int &m)
{
	
	m=6;
	for(int i=0;i<m;i++)
	{
		if(a1[i]==0)
			printf("0 >> khong su dung su tro giup\n");
		if(a1[i]==1)
			printf("1 >> goi dien thoai cho nguoi than\n");	
		if(a1[i]==2)
			printf("2 >> hoi y kien chuyen gia\n");	
		if(a1[i]==3)
			printf("3 >> hoi y kien khan gia trong truong quay\n");
		if(a1[i]==4)
			printf("4 >> tro giup 50/50\n");
		if(a1[i]==5)
		printf("5 >> tu van tai cho\n");				
	}
			printf("0 >> khong su dung su tro giup\n");
			printf(">> ban muon chon su tro giup nao (1, 2, 3, 4, 5): ");
			scanf("%d",&chon);
			//xoa(chon,a1,m);
			//printf("\n chon= %d\n",chon);
}
void bo_trogiup(int x)// id ma cau muon tro giup =>> x la so cau hoi tu 1->
{
	//int chon; // gia tri nay cua m la gia tri moi ma
	int b=6;
	int a1[5];
	for(int i=0;i<b;i++)
	{
		a1[i]=i;	
	}
	xoa(chon,a1,b);
	menu2(a1,b);
	help a[2];
	switch(chon) //chon lay gia tri o dau
	{
		case 1:goi_dien_thoai(x);
			break;
		case 2:hoi_chuyen_gia(x);
			break;
		case 3:	hoi_y_kien_khan_gia(x);
			break;
		case 4:chiadoi(x);
			break;
		case 5:tu_van_tai_cho(x,a);
			break;
		default:
			getch();
	}
}
//---------------------------------------------------------------------------------------------
//================================================================================
void ranDom(int c[14],int a,int b)//lay gia tri random tu a den b luu vao mang 5 phan tu sao cho khong co phan tu nao trung nhau -> phuc vu cho viec random cau hoi.
{
	c[0]=a+rand()%(b-a+1);//
	do 
	{
		
		c[1]=a+rand()%(b-a+1);
		
	}while(c[1]==c[0]);
	do 
	{
		
		c[2]=a+rand()%(b-a+1);
		
	}while(c[1]==c[2]||c[2]==c[0]);
	do 
	{
		
		c[3]=a+rand()%(b-a+1);
		
	}while(c[1]==c[3]||c[2]==c[3]||c[0]==c[3]);
	do 
	{
		
		c[4]=a+rand()%(b-a+1);
		
	}while(c[4]==c[0]||c[4]==c[1]||c[4]==c[2]||c[4]==c[3]);
	do 
	{
		
		c[5]=a+rand()%(b-a+1);
		
	}while(c[5]==c[0]||c[5]==c[1]||c[5]==c[2]||c[5]==c[3] || c[5]==c[4]);
	do 
	{
		
		c[6]=a+rand()%(b-a+1);
		
	}while(c[6]==c[0]||c[6]==c[1]||c[6]==c[2]||c[6]==c[3] || c[6]==c[4] || c[6]==c[5]);
	do 
	{
		
		c[6]=a+rand()%(b-a+1);
		
	}while(c[6]==c[0]||c[6]==c[1]||c[6]==c[2]||c[6]==c[3] || c[6]==c[4] || c[6]==c[5]);
	do 
	{
		
		c[7]=a+rand()%(b-a+1);
	}while(c[7]==c[0]||c[7]==c[1]||c[7]==c[2]||c[7]==c[3] || c[7]==c[4] || c[7]==c[5] || c[7]==c[6]);
	do 
	{
		
		c[8]=a+rand()%(b-a+1);
		
	}while(c[8]==c[0]||c[8]==c[1]||c[8]==c[2]||c[8]==c[3] || c[8]==c[4] || c[8]==c[5] || c[8]==c[6] || c[8]==c[7]);
	do 
	{
		
		c[9]=a+rand()%(b-a+1);
		
	}while(c[9]==c[0]||c[9]==c[1]||c[9]==c[2]||c[9]==c[3] || c[9]==c[4] || c[9]==c[5] || c[9]==c[6] || c[9]==c[7] || c[9]==c[8]);
	do 
	{
		
		c[10]=a+rand()%(b-a+1);
		
	}while(c[10]==c[0]||c[10]==c[1]||c[10]==c[2]||c[10]==c[3] || c[10]==c[4] || c[10]==c[5] || c[10]==c[6] || c[10]==c[7] || c[10]==c[8] || c[10]==c[9]);
	do 
	{
		
		c[11]=a+rand()%(b-a+1);
		
	}while(c[11]==c[0]||c[11]==c[1]||c[11]==c[2]||c[11]==c[3] || c[11]==c[4] || c[11]==c[5] || c[11]==c[6] || c[11]==c[7] || c[11]==c[8] || c[11]==c[9] || c[11]==c[10]);
	do 
	{
		
		c[12]=a+rand()%(b-a+1);
		
	}while(c[12]==c[0]||c[12]==c[1]||c[12]==c[2]||c[12]==c[3] || c[12]==c[4] || c[12]==c[5] || c[12]==c[6] || c[12]==c[7] || c[12]==c[8] || c[12]==c[9] || c[12]==c[10] || c[12]==c[11]);
	do 
	{
		
		c[13]=a+rand()%(b-a+1);
		
	}while(c[13]==c[0]||c[13]==c[1]||c[13]==c[2]||c[13]==c[3] || c[13]==c[4] || c[13]==c[5] || c[13]==c[6] || c[13]==c[7] || c[13]==c[8] || c[13]==c[9] || c[13]==c[10] || c[13]==c[11] || c[13]==c[12]);
	do 
	{
		
		c[14]=a+rand()%(b-a+1);
		
	}while(c[14]==c[0]||c[14]==c[1]||c[14]==c[2]||c[14]==c[3] || c[14]==c[4] || c[14]==c[5] || c[14]==c[6] || c[14]==c[7] || c[14]==c[8] || c[14]==c[9] || c[14]==c[10] || c[14]==c[11] || c[14]==c[12] || c[14]==c[13]);

}
void xuat(int a[], int n)
{
	for(int i=0; i<n; i++)
		printf("\n%4d ",a[i]);
}
void mangRand_Q(int a[15])
{
	int i;
	srand(time(NULL));
	for(i=0;i<15;i++)
	{
		ranDom(a,0,n-1);
	}
	//xuat(a,15);
}
void khungDiem()
{
	if(score<=5)
	{
		printf("[he thong]: so diem hien tai cua ban la: %d\n",score*100);
		if(score==5)
		{
			printf("[Lai Van Sam]: xin chuc mung! Ban da vuot qua moc thu nhat cua chuong trinh\n");
			printf("[Lai Van Sam]: ke tu bay gio ban co the dung cuoc choi de bao toan so diem\n");
			theEnd();
		}
	
				
	}
	else if(score<=10)
	{
		theEnd();
		if(score ==10)					
			printf("[Lai Van Sam]: xin chuc mung! Ban da vuot qua moc thu hai cua chuong trinh\n");
			printf("so diem hien tai cua ban la: %d\n",score*200);
	}
	else if(score<=15)
	{
		theEnd();
		if(score==15)
			printf("xin chuc mung ban la nguoi thang cuoc\n");
		printf("so diem hien tai cua ban la %d\n",score*300);
	}		
}
//===================================================================================
void xuatQ()
{
	int i,j;
	char a,t;
	int q[30];
	help b[2];
	mangRand_Q(q);
		for(i=0;i<15;i++)
	{
		ngancach();
		printf("[Lai Van Sam]: Cau hoi chuong trinh dua ra la:");
		printf("\n<cau %d> %s",i+1,list[q[i]].cauHoi);
		printf(">>A: %s",&list[q[i]].A);
		printf(">>B: %s",&list[q[i]].B);
		printf(">>C: %s",&list[q[i]].C);
		printf(">>D: %s",&list[q[i]].D);
		ngancach();
		bo_trogiup(q[i]);
		ngancach();
		printf("[Lai Van Sam]: Hay cho chung toi biet cau tra loi cua ban!:\n");
		printf("[Nguoi choi]: Cau tra loi cuoi cung cua toi la: \n");
		fflush(stdin);
		scanf("%c",&a);
		a=toupper(a);
		ngancach();
		if(list[q[i]].dapAn==a)
		{
			if(chon==5)
				qua(b,q[i]);
			score++;
			printf("[Lai Van Sam]: Xin Chuc Mung! Ban da tra loi dung cau hoi cua chung toi!\n");
			khungDiem();
		}

		else
			{
				printf("[Lai Van Sam] ban da tra loi sai cau hoi cu chung toi!\n");
				break;
			}
			
	}
	}
void playG()
{
	xuatQ();
	luatChoi();
	Sleep(700);			
}
	
void Guide()
{
	while(flag)
	{
		system("cls");
		printf("==CACH CHOI==\n+Dau tien chon vao chuc nang LOAD QUESTION de tai du lieu cau hoi -> chon tiep PLAY de choi game\n");
		printf("+Muon tao mot cau hoi moi chon CREATE QUESTION de tao cau hoi \n-> chon UPDATE QUESTION de tai cau hoi vua tao vao kho du lieu \n-> chon LOAD QUESTION de cap nhat cau hoi vua tao\n-> chon PLAY de choi");
		printf("\n(Nhan phim ENTER de quay lai MENU)");
		if(kbhit())
		{
			char key = getch();
			if(key == 13)	break;
		}
		Sleep(800);
	}
}int main()
{
		system("COLOR 70");
	char* menu[] = {"CREATE QUESTION", "UPDATE QUESTION", "LOAD QUESTION","PLAY","GUIDE","RELOAD", "EXIT\n", };
	int pointer = 0;flag =1; // con tro chi vi tri so 0
	list = (ques*)malloc(sizeof(ques)*MAX);
	while(1)
	{
		//xoa man hinh
		system("cls");
		//in ra man hinh
		printf("\t\t **************************************************************************\n");
		printf("\t\t *  ///\\\   ||  |||	  ///\\\\     ///\\\\\\  |||====|| |||  |||  |||   ||| *\n");
		printf("\t\t * ///==\\\  ||  |||_____	 ///==\\\\      ||    |||====|| |||==|||  |||___||| *\n");
		printf("\t\t *///    \\\ ||  |||_____	///    \\\\     || *  |||	      |||  |||  |||___||| *\n");
 		printf("\t\t **************************************************************************\n");
		printf("\n\t\t==>DOC KY PHAN HUONG DAN TRONG GUIDE TRUOC KHI CHOI\n\t\t(su dung phim mui ten va phim ENTER tren keyboard de su dung MENU)\n");
		for(int i=0;i<MAX_LIST;i++)
		{
			if(pointer == i)
			{
				printf("\n\t %c %s %c",175, menu[i], 174);
			}
			else
			{
				printf("\n\t[+] %s",menu[i]);
			}	
		}
		//xu ly keyboard
		while(1)
		
		{
			if(kbhit()) // neu co phim nhap vao
			{
				char key = getch(); //luu phim do lai de xu ly
				if(key==72)			// len
				{
					if(pointer > 0)	--pointer;
					else	pointer = MAX_LIST-1;
					break;
				}
				if(key == 80)		//xuong
				{
					if(pointer < MAX_LIST-1)	++pointer;
					else 	pointer =0;
					break;
				}
				if(key == 13)	//phim ENTER
				{
					switch(pointer)
					{
						case 0:
							printf("\nChu y: Nhap gia tri -1 vao phan dap an de quay lai menu\n!!");
							creatQ();
							break;
						case 1:
							ghiFile();
							break;
						case 2:
							docFile();
							break;
						case 3:
							playG();
							break;
						case 4:
							Guide();
							break;
						case 5:
							main();
							break;
						case 6:
							printf("\nGoodbye......");
							flag = -1;
							break;
						default:
							printf("\nERROR. This is bug!!!");
					}
					break;	
				}
			}
		}
		if(flag == -1)
		{
			break;
		}
		
		Sleep(100);
	}
	//end Menu
	printf("\nThank you very much!!");
	_getch();
	return 0;}