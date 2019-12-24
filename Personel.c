#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h> 
#include<conio.h>
//FONKS�YON PROTOT�PLER�
void Kayit_Sil();
void tc_bul();
void Kayit_Ekle();
void Personel_Listele();
void isimle_bul();
void kayitGuncelle();
//STRUCT TANIMLAMASI
typedef struct {
	char isim[100];
	char TCKimlikNo[100];
    char telefon[100];
	char eposta[100];
	char adres[100];
}personel;
personel person;
//MEN�
int main () {
	setlocale(LC_ALL, "Turkish");

	printf("				-----> PERSONEL B�LG� S�STEM� <-----\n"); 
	int islem;
	printf("		��LEMLER\n\n");
		printf("1. Kay�t Ekle\n2. Personel Listele\n3. Kayd� D�zenle\n4. TC Kimlik No ile Kay�t Bul\n5. �sim ile Kay�t Bul\n6. Kay�t Sil\n0. ��k��\n");	
			printf("Yapmak �stedi�iniz ��lem Numaras�n� Giriniz :  ");
			scanf("%d",&islem);
			printf("\n");
		switch(islem){
			case 1: Kayit_Ekle();          break;
			case 2: Personel_Listele();    break;
			case 3:	kayitGuncelle();	   break;
			case 4: tc_bul();		       break;
			case 5: isimle_bul();		   break;
			case 6: Kayit_Sil();  	       break;
			case 0: printf("Ba�ar�yla ��k�� Yap�ld� !!"); break;
			default: printf("Hatal� Tu�lama Yap�ld� Ana Men�ye Y�nlendiriliyorsunuz !!\n"); main();
		}
	return 0;
}
// KAYIT EKLEME 
void Kayit_Ekle(){
	FILE *fp;
	fp=fopen("Personel.txt","a");
	if(fp==NULL){
		printf("Dosya Olu�turalamad�...");
	}
	printf("�sim :  ");
	scanf("%s",&person.isim);
		printf("T.C. Kimlik No : ");
		scanf("%s",&person.TCKimlikNo);
			printf("Telefon : ");
			scanf("%s",&person.telefon);
				printf("E-posta : ");
				scanf("%s",&person.eposta);
					printf("Adres : ");
					scanf("%s",&person.adres);
					fwrite(&person,sizeof(person),1,fp);	
							printf("Kay�t Ba�ar�yla Tamamland�...\n");							
fclose(fp);
main();
}
//PERSONEL L�STELEME
void Personel_Listele() {
	FILE *fp;
	fp=fopen("Personel.txt","r");
	if(fp==NULL){
		printf("HATA");
		exit(1);
	}
	while(fread(&person,sizeof(person),1,fp)==1){
					printf("�sim : %s\n",person.isim);
					printf("TC Kimlik No : %s\n",person.TCKimlikNo);
					printf("Telefon : %s\n",person.telefon);
					printf("E-posta : %s\n",person.eposta);
					printf("Adres : %s\n\n",person.adres);
	}	
	printf("Kay�t Listelenmi�tir\n");
	fclose(fp);	
	main();
}
//�S�MLE KAYIT BULMA
void isimle_bul() {
		FILE *fp;
		fp=fopen("Personel.txt","rb+");
		char search[100];
		int x;
		printf("Bulmak �stedi�iniz �simi Giriniz :  ");
		scanf("%s",&search);
			while(fread(&person,sizeof(person),1,fp)==1){
				if(strcmp(search,person.isim)==0){
					printf("�sim : %s\n",person.isim);
					printf("TC Kimlik No : %s\n",person.TCKimlikNo);
					printf("Telefon : %s\n",person.telefon);
					printf("E-posta : %s\n",person.eposta);
					printf("Adres : %s\n",person.adres);
					printf("Kay�t Listelenmi�tir");
					x++;
				}
			}		
			if(x==0){
				printf("Kay�t Bulunamad�\n");
				main();
			}
	fclose(fp);
	main();
}
//KAYIT G�NCELLEME
void kayitGuncelle(){
	FILE *fp;
	fp=fopen("Personel.txt","rb+");
	char search[100];
	int x=0;
	int y=0;
	int z=0;
	
	printf("�simi Giriniz : \n");
	scanf("%s",&search);
	
	while (fread(&person,sizeof(person),1,fp)==1){
		if(strcmp(search,person.isim)==0){
			printf("�sim: %s\n",person.isim);
			printf("TC Kimlik No : %s\n",person.TCKimlikNo);
			printf("Telefon : %s\n",person.telefon);
			printf("E-posta : %s\n",person.eposta);
			printf("Adres : %s\n",person.adres);
			printf("\nKay�t Listelenmi�tir\n");
			x++;
		}
		z++;
			if(x==1){
				y+=z;
				x=2;
			}
	}	
	if(x==0){
		printf("Kayit Bulunamadi..");
		fclose(fp);
		main();
	}
	printf("Yeni �sim Giriniz : ");
	scanf("%s",&person.isim);
		printf("Yeni Tc Kimlik No : ");
		scanf("%s",&person.TCKimlikNo);
			printf("Yeni Telefon Numaras�n� Giriniz : ");
			scanf("%s",&person.telefon);
				printf("Yeni E-posta Adresini Giriniz : ");
				scanf("%s",&person.eposta);
					printf("Yeni Adres Giriniz : ");
					scanf("%s",person.adres);
					printf("\n");
					fseek(fp,(y-1)*sizeof(person),SEEK_SET);
					fwrite(&person,sizeof(person),1,fp);
					
					fclose(fp);
					printf("��lem Ba�ar�l�\n\n");
					main();
					
}
//TC �LE KAYIT BULMA
void tc_bul(){
	FILE *fp;
	fp=fopen("Personel.txt","rb+");
	
	if(fp==NULL){
		printf("HATA");
		exit(1);
	}
	char number[100];
	int x=0;
		printf("TC Kimlik No : ");
		scanf("%s",number);
			while(fread(&person,sizeof(person),1,fp)==1){
				if(strcmp(number,person.TCKimlikNo)==0){
					printf("�sim : %s\n",person.isim);
					printf("TC Kimlik No : %s\n",person.TCKimlikNo);
					printf("Telefon : %s\n",person.telefon);
					printf("E-posta : %s\n",person.eposta);
					printf("Adres : %s\n",person.adres);
					printf("Kay�t Listelenmi�tir");
					x++;
				}
			}
			if(x==0){
				printf("Kay�t Bulunamad�\n");
			}
			fclose(fp);
			main();
}
//KAYIT S�LME
void Kayit_Sil() {
	FILE *fp;
	fp=fopen("Personel.txt","rb+");
	FILE *fptr;
	fptr=fopen("temp.txt","wb+");
		if(fp==NULL){
			printf("HATA");
			exit(1);
		}
		if(fptr==NULL){
			printf("HATA");
			exit(1);
		}
		char number[100];
		int x=0;
		printf("TC Kimlik No : ");
		scanf("%s",&number);
		
			while(fread(&person,sizeof(person),1,fp)==1){
				if(strcmp(number,person.TCKimlikNo)!=0){
					fwrite(&person,sizeof(person),1,fptr);
				}
				else {
					x++;
				}
			}
			if(x==0){
				printf("BULUNAMADI HATA");
			}
			fclose(fp);
			fclose(fptr);
			remove("Personel.txt");
			rename("temp.txt","personel.txt");
				printf("��lem Ba�ar�l�...\n");
				main();
}
















