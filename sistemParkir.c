#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define MAX 30

struct parkir{
    char hurufDepanPlat[MAX];
    int noPlat;
    char hurufBelakangPlat[MAX];
    char warnaKendaraan[MAX];
    int durasi;
    char golongan[MAX];
    struct parkir *next;
}*front, *frontNode, *rear, *temp, *p;

int count = 0;

void menu()
{
	printf("SISTEM PEMBAYARAN PARKIR KENDARAAN PERTOKOAN X\n");
	printf("----------------------------------------------\n");
    printf("1. add data kendaraan pada antrean\n");
    printf("2. pembayaran parkir (delete data)\n");
    printf("3. display all data\n");
	printf("4. search\n");
    printf("5. exit\n");
    printf("----------------------------------------------\n");
}

int compareString(char value1[], char value2[]){
	int result;
	result = strcmp(value1, value2);
	return result;
}

void createQueue(){
    front = NULL;
	rear = NULL;
}

void enqueue(char newPlatDepan[], int newPlatNo, char newPlatBelakang[], char newWarna[], int newDur, char newGol[]){
    fflush(stdin);
	
    if (rear == NULL){
        rear = (struct parkir *)malloc(1*sizeof(struct parkir));
        rear->next = NULL;
        strcpy(rear->hurufDepanPlat, newPlatDepan);
        rear->noPlat = newPlatNo;
        strcpy(rear->hurufBelakangPlat, newPlatBelakang);
        strcpy(rear->warnaKendaraan, newWarna);
        rear->durasi = newDur;
        strcpy(rear->golongan, newGol);
        front = rear;
    }
    else{
        temp=(struct parkir *)malloc(1*sizeof(struct parkir));
        rear->next = temp;
        strcpy(temp->hurufDepanPlat, newPlatDepan);
        temp->noPlat = newPlatNo;
        strcpy(temp->hurufBelakangPlat, newPlatBelakang);
        strcpy(temp->warnaKendaraan, newWarna);
        temp->durasi = newDur;
        strcpy(temp->golongan, newGol);
        temp->next = NULL;
        rear = temp;
    }
    count++;
}

int biayaParkir(int durasiParkir, char golKendaraan[]){
	int totalBiaya;
	double pembulatanDurasi;
	if(durasiParkir <= 5){
		totalBiaya = 0;
	}
	else if(durasiParkir > 5 && durasiParkir <= 60){
		if((compareString(golKendaraan, "R2")) == 0){
			totalBiaya = 5000;
		}
		if((compareString(golKendaraan, "R4")) == 0){
			totalBiaya = 10000;
		}
	}
	else if(durasiParkir > 60){
		pembulatanDurasi = ceil(durasiParkir/60.0);
		if((compareString(golKendaraan, "R2")) == 0){
			totalBiaya = 5000 + ((pembulatanDurasi-1)*1000);
		}
		if((compareString(golKendaraan, "R4")) == 0){
			totalBiaya = 10000 + ((pembulatanDurasi-1)*1000);
		}
	}
	return totalBiaya;
}

void dequeue(){
    fflush(stdin);
	frontNode = front;
 
    if (frontNode == NULL){
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else{
    	if (frontNode->next != NULL){
            frontNode = frontNode->next;
			printf("No plat kendaraan: %s %d %s\n", front->hurufDepanPlat, front->noPlat, front->hurufBelakangPlat);
            printf("Biaya parkir kendaraan: %d\n", biayaParkir(front->durasi, front->golongan));
            printf("Data berhasil di dequeue!\n\n");
			printf("Data dengan plat nomor kendaraan %s %d %s telah terhapus!", front->hurufDepanPlat, front->noPlat, front->hurufBelakangPlat);
            free(front);
            front = frontNode;
        }
        else{
			printf("No plat kendaraan: %s %d %s\n", front->hurufDepanPlat, front->noPlat, front->hurufBelakangPlat);
            printf("Biaya parkir kendaraan: %d\n", biayaParkir(front->durasi, front->golongan));
            printf("Data berhasil di dequeue!\n\n");
			printf("Data dengan plat nomor kendaraan %s %d %s telah terhapus!", front->hurufDepanPlat, front->noPlat, front->hurufBelakangPlat);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
	}  
}

void printNode(struct parkir *p)
{
    printf("\n|\t%s %d %s\t|\t%s\t|\t%d\t|\t%s\t|\n", p->hurufDepanPlat, p->noPlat, p->hurufBelakangPlat, p->warnaKendaraan, p->durasi, p->golongan);
    printf("-------------------------------------------------------------------------");
}

void display(){
	frontNode = front;
	
	printf("-------------------------------------------------------------------------");
	printf("\n|\tPlat Nomor\t|\tWarna\t|\tDurasi\t|\tGol\t|\n");
	printf("-------------------------------------------------------------------------");
 	
    if ((frontNode == NULL) && (rear == NULL)){
        printf("\nQueue is empty");
    }
    while (frontNode != rear){
        printNode(frontNode);
        frontNode = frontNode->next;
    }
    if (frontNode == rear){
    	printNode(frontNode);	
	}
}

void search(char searchPlatDepan[], int searchPlatNo, char searchPlatBelakang[])
{
    frontNode = front;
	
	while (frontNode != rear){
        if ((compareString(frontNode->hurufDepanPlat, searchPlatDepan) == 0) && (frontNode->noPlat == searchPlatNo) && (compareString(frontNode->hurufBelakangPlat, searchPlatBelakang) == 0)){
            printf("\nData kendaraan ditemukan:\n");
            printNode(frontNode);
            return;
        }
        frontNode = frontNode->next;
    }
    if ((frontNode == rear) && (compareString(frontNode->hurufDepanPlat, searchPlatDepan) == 0) && (frontNode->noPlat == searchPlatNo) && (compareString(frontNode->hurufBelakangPlat, searchPlatBelakang) == 0)){
    	printf("\nData kendaraan ditemukan:\n");
		printNode(frontNode);
		return;	
	}
	printf("\nData kendaraan dengan nomor plat %s %d %s tidak ditemukan", searchPlatDepan, searchPlatNo, searchPlatBelakang);
}

int main()
{
    int platNo, dur;
    char platDepan[30], platBelakang[30], warna[30], gol[30];
    char pilihMenu;
 	
	  createQueue();
 	
    do
    {
    	menu();
    	printf("\n\nPilih menu yang tersedia: ");
	    scanf("%d", &pilihMenu);
        switch(pilihMenu)
        {
        case 1:
        	system("cls");
			printf("Masukkan plat no kendaraan (ex: L 1234 LL): ");
			scanf("%s %d %s", &platDepan, &platNo, &platBelakang);
            
            //warna kendaraan
			printf("Masukkan warna kendaraan (1. Hitam, 2. Putih, 3. Lainnya): ");
            scanf("%s", &warna);
			if(compareString(warna, "1") == 0){
				strcpy(warna, "Hitam");
			}
			if(compareString(warna, "2") == 0){
				strcpy(warna, "Putih");
			}
			if(compareString(warna, "3") == 0){
				strcpy(warna, "Lainnya");
			}
			
			printf("Masukkan durasi parkir kendaraan (dalam menit): ");
            scanf("%d", &dur);
			
			//golongam kendaraan
			printf("Masukkan golongan kendaraan (1. R2, 2. R4): ");
            scanf("%s", &gol);
			if(compareString(gol, "1") == 0){
				strcpy(gol, "R2");
			}
			if(compareString(gol, "2") == 0){
				strcpy(gol, "R4");
			}
			
            enqueue(platDepan, platNo, platBelakang, warna, dur, gol);
            system("cls");
            break;
        case 2:
        	system("cls");
            dequeue();
            getch();
            system("cls");
            break;
        case 3:
        	system("cls");
            display();
            getch();
            system("cls");
            break;
	case 4:
        	system("cls");
            printf("MASUKKAN PLAT NOMOR YANG DATANYA INGIN DICARI");
			printf("\nMasukkan plat no kendaraan (ex: L 1234 LL): ");
			scanf("%s %d %s", &platDepan, &platNo, &platBelakang);
            search(platDepan, platNo, platBelakang);
            getch();
            system("cls");
            break;
        case 5: 
        	exit(0);
			break;
		default:
			system("cls");
			printf("Menu yang dipilih salah, tekan enter untuk memasukkan ulang menu!");
			getch();
			system("cls");
        }
    } while (pilihMenu != '5');
}