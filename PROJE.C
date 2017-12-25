#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
int kontrol(char *b)
{

	int u,i=0,sonuc=1;
	char *b1;
	b1=b;
	u=strlen(b);
	while(i<u)
	{
	 if(isdigit(*b)==0)
	{
	sonuc=0;
	break;
	}
	i++;
	b++;
	}
	return sonuc;

}

void aracekle(int a)
{
		int i=0,u;
	char *p,*c;
	float *asb;
	p=(char*)malloc((sizeof(char)*20)*4);
	c=(char*)malloc((sizeof(char)*20)*3);
	asb=(float*)calloc(sizeof(float),3);


	printf("** Marka :"); scanf("%s",p);
	printf("** Seri  :"); scanf("%s",p+20);
	printf("** Model :"); scanf("%s",p+40);
	printf("** Renk  :"); scanf("%s",p+60);

	printf("** Yil   :"); scanf("%s",c);while(kontrol(c)==0){printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c);}
	printf("** Km    :"); scanf("%s",c+20);while(kontrol(c+20)==0){printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c+20);}
	printf("** Fiyat :"); scanf("%s",c+40);while(kontrol(c+40)==0){printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c+40);}

	*asb=atof(c);
	*(asb+1)=atof(c+20);
	*(asb+2)=atof(c+40);

	FILE *galeri;

	if((galeri=fopen("aracbilgileri.txt","a"))!=0)
	{

	printf("\n\t%s\t%s\t%s\t%s\t%.f\t%.f\t%.f\tTL",strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),*(asb),*(asb+1),*(asb+2));
   fprintf(galeri,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",a+1,strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),*(asb),*(asb+1),*(asb+2));
	  fflush(galeri);fclose(galeri);
	  printf("\n\n\t** Arac Basarili Bir Sekilde Eklendi. **");
	}
	else printf("Dosya Bulunamadi.");
	free(p);
	free(c);
	free(asb);
}

aracbilgileri(int c)
{
	char *marka,*seri,*model,*renk,secim[10];
	int *sira,i=0,b,sec,a=1;
	float *yil,*km,*fiyat;

	marka=(char*)malloc((sizeof(char)*20)*c);
	seri=(char*)malloc((sizeof(char)*20)*c);
	model=(char*)malloc((sizeof(char)*20)*c);
	renk=(char*)malloc((sizeof(char)*20)*c);
	yil=(float*)calloc(sizeof(float),c);
	km=(float*)calloc(sizeof(float),c);
	fiyat=(float*)calloc(sizeof(float),c);
	sira=(int*)calloc(sizeof(int),c);
	FILE *galeri;
	if((galeri=fopen("aracbilgileri.txt","r"))!=0)
	{
	while(!feof(galeri))
	{

		fscanf(galeri,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",(sira+i),(marka+i*20),(seri+i*20),(model+i*20),(renk+i*20),(yil+i),(km+i),(fiyat+i));
		//printf("%d ) %s\t%s\t%s\t%s\t%.f\t%.f\t%.f\t\n",*(sira+i),(marka+i*20),(seri+i*20),(model+i*20),(renk+i*20),*(yil+i),*(km+i),*(fiyat+i));
		i++;
		if((i+1)%20==1)
		a++;

	}	fclose(galeri);
	}

	else printf("dosya bulunamadi.");
	i=0,b=1;
	printf("     MARKA\tSERI\t MODEL\tRENK\tYIL\t  KM\tFIYAT\t\n");printf("     -----\t----\t -----\t----\t---\t  --\t-----\t\n");
	while(i<c)
	{

		if(i<b*20 && i<c)
		{
			printf("%d ) %s\t%s\t%s\t%s\t%.f\t%.f\t%.f\tTL\n",*(sira+i),(marka+i*20),(seri+i*20),(model+i*20),(renk+i*20),*(yil+i),*(km+i),*(fiyat+i));

			i++;
			if(i==c)
			{

			printf("\n\t%d.Sayfadasiniz.\tToplam Sayfa :%d\n1-)Onceki Sayfa\t0-)Ana menu\n",b,a);printf("Secim Yap  :");

			scanf("%s",secim);
			while(kontrol(secim)==0)
			{printf("Lutfen Gecerli Bir Deger Giriniz :");scanf("%s",secim);
			}sec=atoi(secim);
			while(b==1 && sec==1)
			{
				printf("Zaten Ilk Sayfadasiniz.Secim Yapiniz :");scanf("%s",secim);sec=atoi(secim);
			}sec=atoi(secim);

			while(atoi(secim)>1 || atoi(secim)<0 || kontrol(secim)==0)
			{printf("Yanlis Secim Yaptiniz :"); scanf("%s",secim);

			}
			sec=atoi(secim); system("cls");printf("     MARKA\tSERI\t MODEL\tRENK\tYIL\t  KM\tFIYAT\t\n");printf("     -----\t----\t -----\t----\t---\t  --\t-----\t\n");
			switch(sec)
			{
				case 1 : b--; i=(b-1)*20; break;
				case 0 : system("cls");printf("Devam Etmek Icin Bir Tusa Basin."); break;
			}
		}

		}
		else
		{
		printf("\t%d.Sayfadasiniz.\tToplam Sayfa :%d\n1-)Onceki Sayfa\t2-)Sonraki Sayfa\t 0-)Ana Menu\n",b,a);
		printf("Secim Yap  :");

		scanf("%s",secim);

		sec=atoi(secim);
		while( (b==1 && sec==1) || sec<0 || sec>2 || kontrol(secim)==0)
		{

			if(sec==1)
			{
				printf("\nZaten Ýlk Sayfadasiniz.Secim Yapiniz :\n");while(atoi(secim)==1 || kontrol(secim)==0){
				scanf("%s",secim);};
			}
			//else if(sec==0){break;}
			else { printf("Yanlis Secim Yaptiniz.Lutfen Tekrar Deneyiniz.");while(kontrol(secim)==0 || atoi(secim)>2 || atoi(secim)<0) {
			scanf("%s",secim);}}
	sec=atoi(secim);
		}if(sec==0){printf("Devam Etmek Icin Bir Tusaa Basin.");break;
		}system("cls"); printf("     MARKA\tSERI\t MODEL\tRENK\tYIL\t  KM\tFIYAT\t\n");printf("     -----\t----\t -----\t----\t---\t  --\t-----\t\n");
		switch(sec)
		{
			case 2 : b++; break;
			case 1 : b--; break;
		}
		i=(b-1)*20;
		}
	}
	free(marka);free(seri);free(model);free(renk);free(sira);free(yil);free(km);free(fiyat);


}

	void arama(int c){
	char *ma,*se,*mo,*re,*aranan,sec[10];
	float *km,*yil,*fiyat,bellek;
	int i=0,sonuc,*sira,*sayi,secim3,a=0,k=0,j=0,b;
	yil=(float*)calloc(sizeof(float),c);
	km=(float*)calloc(sizeof(float),c);
	fiyat=(float*)calloc(sizeof(float),c);
	sira=(int*)calloc(sizeof(int),c);
	sayi=(int*)calloc(sizeof(int),c);
	aranan=(char*)malloc(sizeof(char)*20);
	ma=(char*)malloc((sizeof(char)*20)*c);
	se=(char*)malloc((sizeof(char)*20)*c);
	mo=(char*)malloc((sizeof(char)*20)*c);
	re=(char*)malloc((sizeof(char)*20)*c);

	printf("\n\t*****************************************\n");
	printf("\t***                                   ***\n");
	printf("\t***      ARAMA TURLERI                ***\n");
	printf("\t***     --------------                ***\n");
	printf("\t***         1-) ** MARKA **           ***\n");
	printf("\t***         2-) ** SERI  **           ***\n");
	printf("\t***         3-) ** MODEL **           ***\n");
	printf("\t***         4-) ** RENK  **           ***\n");
	printf("\t***                                   ***\n");
	printf("\t***         0-) ** ANAMENU **         ***\n");
	printf("\t***                                   ***\n");
	printf("\t*****************************************\n");
	printf("\t*** Secim Yapiniz  :");scanf("%s",sec);while(kontrol(sec)==0  ||atoi(sec)<0 || atoi(sec)>4)
	{
		printf("Gecerli Bir Sayi Giriniz:"); scanf("%s",sec);
	}secim3=atoi(sec);
	FILE *galeri;
	if(secim3!=0)
	{

	if((galeri=fopen("aracbilgileri.txt","r"))!=0)
	{

	while(!feof(galeri))
	{
		fscanf(galeri,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",(sira+i),(ma+20*i),(se+20*i),(mo+20*i),(re+20*i),(yil+i),(km+i),(fiyat+i));
	i++;

	}
	printf("Aranacak Bilgiyi Giriniz:");
	scanf("%s",aranan);
system("cls");
	fclose(galeri);
	}else printf("dosya bulunamadi.");

	i=0;
	while(i<c)
	{
		switch(secim3)
		{

		case 1:
		{
			sonuc=strcmp(strupr(aranan),(ma+20*i));
		if(sonuc==0)
		{
			*(sayi+k)=*(sira+i);
			//printf("%d ) %s\t%s\t%s\t%s\t%.f\t%.f\t%.f\t\n",*(sira+i),(ma+20*i),(se+20*i),(mo+20*i),(re+20*i),*(yil+i),*(km+i),*(fiyat+i));

			if((k+1)%20==1)
			a++;
			k++;
		}

		i++;
			break;
		}

		case 2 :{
			sonuc=strcmp(strupr(aranan),(se+20*i));
			if(sonuc==0)
			{*(sayi+k)=*(sira+i);
			//printf("%d ) %s\t%s\t%s\t%s\t%.f\t%.f\t%.f\t\n",*(sira+i),(ma+20*i),(se+20*i),(mo+20*i),(re+20*i),*(yil+i),*(km+i),*(fiyat+i));
			if((k+1)%20==1)
		a++;
			k++;
			}
			i++;
			break;
		}
		case 3 : {
			sonuc=strcmp(strupr(aranan),(mo+20*i));
			if(sonuc==0)
			{*(sayi+k)=*(sira+i);
			//printf("%d ) %s\t%s\t%s\t%s\t%.f\t%.f\t%.f\t\n",*(sira+i),(ma+20*i),(se+20*i),(mo+20*i),(re+20*i),*(yil+i),*(km+i),*(fiyat+i));
			if((k+1)%20==1)
		a++;
			k++;
			}
			i++;
			break;
		}
		case 4 : {
			sonuc=strcmp(strupr(aranan),(re+20*i));
			if(sonuc==0)
			{*(sayi+k)=*(sira+i);
			//printf("%d ) %s\t%s\t%s\t%s\t%.f\t%.f\t%.f\t\n",*(sira+i),(ma+20*i),(se+20*i),(mo+20*i),(re+20*i),*(yil+i),*(km+i),*(fiyat+i));
			if((k+1)%20==1)
			a++;
			k++;

			}
			i++;
			break;
		}
		}

	}

	i=0,b=1;
	if(k!=0)
	{
	printf("     MARKA\tSERI\t MODEL\tRENK\tYIL\t  KM\tFIYAT\t\n");printf("     -----\t----\t -----\t----\t---\t  --\t-----\t\n");
	while(i<k)
	{

		if(i<b*20 && i<k)
		{
			j=*(sayi+i)-1;
			printf("%d ) %s\t%s\t%s\t%s\t%.f\t%.f\t%.f\tTL\n",*(sira+j),(ma+j*20),(se+j*20),(mo+j*20),(re+j*20),*(yil+j),*(km+j),*(fiyat+j));
			j++;
			i++;
			if(i==k)
			{

			printf("\n %d.Sayfadasiniz.\tToplam Sayfa Sayisi :%d\t Bulunan Arac Sayisi:%d\n\t  1-)Onceki Sayfa\t   0-)Ana menu\t   ",b,a,k);printf("Secim Yap  :");



			scanf("%s",sec);
			while(kontrol(sec)==0)
			{printf("Lutfen Gecerli Bir Deger Giriniz :");scanf("%s",sec);
			}secim3=atoi(sec);
			while(b==1 && secim3==1)
			{
				printf("Zaten Ilk Sayfadasiniz.Secim Yapiniz :"); scanf("%s",sec);secim3=atoi(sec);
			}secim3=atoi(sec);

			while(atoi(sec)>1 || atoi(sec)<0 || kontrol(sec)==0)
			{printf("Yanlis Secim Yaptiniz :"); scanf("%s",sec);


			}
			secim3=atoi(sec);system("cls");printf("     MARKA\tSERI\t MODEL\tRENK\tYIL\t  KM\tFIYAT\t\n");printf("     -----\t----\t -----\t----\t---\t  --\t-----\t\n");
			switch(secim3)
			{
				case 1 : b--; i=(b-1)*20; break;
				case 0 : system("cls");printf("Devam Etmek Icin Bir Tusa Basin."); break;
			}
		}

		}

		else
		{
		printf("  %d.Sayfadasiniz.\tToplam Sayfa :%d\t Bulunan Arac Sayisi :%d\n  1-)Onceki Sayfa\t2-)Sonraki Sayfa\t 0-)Ana Menu\n",b,a,k);
		printf("Secim Yap  :");

		scanf("%s",sec);
		secim3=atoi(sec);

		while( (b==1 && secim3==1) || secim3<0 || secim3>2 || kontrol(sec)==0)
		{

			if(secim3==1)
			{
				printf("\nZaten Ýlk Sayfadasiniz.Secim Yapiniz :\n");while(atoi(sec)==1 || kontrol(sec)==0){
				scanf("%s",sec);}

			}
			else { printf("Yanlis Secim Yaptiniz.Lutfen Tekrar Deneyiniz.");while(kontrol(sec)==0 || atoi(sec)>2 || atoi(sec)<0){
				scanf("%s",sec);
			}}
secim3=atoi(sec);
		}if(secim3==0){printf("Devam Etmek Icin Bir Tusa Basin.");break;
		} system("cls");printf("     MARKA\tSERI\t MODEL\tRENK\tYIL\t  KM\tFIYAT\t\n");printf("     -----\t----\t -----\t----\t---\t  --\t-----\t\n");
		switch(secim3)
		{
			case 2 : b++; break;
			case 1 : b--; break;
		}
		i=(b-1)*20;
		}
	}
     }else {printf("** Aramanizla eslesen arac bulunamadi. **"); getch(); }

	free(ma);free(se);free(mo);free(re);free(aranan);
	free(yil);free(km);free(fiyat);
	fflush(galeri);
	fclose(galeri);
}else {
printf("Arama Islemi Iptal Edildi.Devam Etmek Icin Bir Tusa Basin.");
}
}

void duzenle(int c)
{
	char *ma,*se,*mo,*re,*y,secs[10];
	float *km,*yil,*fiyat;
	int i=0,sonuc,*sira,*sayi,secim3,secim4;
	yil=(float*)calloc(sizeof(float),c);
	km=(float*)calloc(sizeof(float),c);
	fiyat=(float*)calloc(sizeof(float),c);
	sira=(int*)calloc(sizeof(int),c);
	ma=(char*)malloc((sizeof(char)*20)*c);
	se=(char*)malloc((sizeof(char)*20)*c);
	mo=(char*)malloc((sizeof(char)*20)*c);
	re=(char*)malloc((sizeof(char)*20)*c);
	y=(char*)malloc((sizeof(char)*20)*3);
	FILE *galeri;

	printf("\n\t*****************************************\n");
	printf("\t***                                   ***\n");
	printf("\t***      ARAC DUZENLE                 ***\n");
	printf("\t***     --------------                ***\n");
	printf("\t***                                   ***\n");
	printf("\t***  *                              * ***\n");
	printf("\t***  * DUZENLENECEK   ARAC NUMARASI * ***\n");
	printf("\t***  *                              * ***\n");
	printf("\t***                                   ***\n");
	printf("\t***         0-) ** ANAMENU **         ***\n");
	printf("\t***                                   ***\n");
	printf("\t*****************************************\n");
	printf("\t*** Secim Yapiniz   :");scanf("%s",secs);
	while(kontrol(secs)==0 || atoi(secs)<0 || atoi(secs)>c)
	{
		printf("Lutfen Gecerli Bir Deger Giriniz   :");scanf("%s",secs);
	}secim4=atoi(secs);
	if(secim4!=0)
	{

	if((galeri=fopen("aracbilgileri.txt","r"))!=0)
	{
		while(!feof(galeri))
		{
			fscanf(galeri,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",(sira+i),(ma+20*i),(se+20*i),(mo+20*i),(re+20*i),(yil+i),(km+i),(fiyat+i));
			//printf("%s\t\t%s\t%s\t%s\t%.f\t%.f\t%.f\t\n",(ma+20*i),(se+20*i),(mo+20*i),(re+20*i),*(yil+i),*(km+i),*(fiyat+i));
			i++;
		}

		fclose(galeri);


	i=(secim4-1);
	printf("ONCEKI BILGI   \tYENI BILGI\n");
	printf("Marka :%s\t",(ma+20*i)); scanf("%s",(ma+20*i));
	printf("Seri  :%s\t",(se+20*i)); scanf("%s",(se+20*i));
	printf("Model :%s\t",(mo+20*i)); scanf("%s",(mo+20*i));
	printf("Renk  :%s\t",(re+20*i)); scanf("%s",(re+20*i));
	printf("Yil   :%.f\t",*(yil+i));   scanf("%s",(y));   while(kontrol(y)==0){printf("Lutfen Deger Giriniz :"); scanf("%s",y);}
	printf("Km    :%.f\t",*(km+i));    scanf("%s",(y+20));while(kontrol(y+20)==0){printf("Lutfen Deger Giriniz :"); scanf("%s",y+20);}
	printf("Fiyat :%.f\t",*(fiyat+i)); scanf("%s",(y+40));while(kontrol(y+40)==0){printf("Lutfen Deger Giriniz :"); scanf("%s",y+40);}
	*(yil+i)=atof(y);
	*(km+i)=atof(y+20);
	*(fiyat+i)=atof(y+40);

	i=0;
	if((galeri=fopen("aracbilgileri.txt","w"))!=0)
	{
		while(i<c)
		{
			fprintf(galeri,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",*(sira+i),strupr(ma+20*i),strupr(se+20*i),strupr(mo+20*i),strupr(re+20*i),*(yil+i),*(km+i),*(fiyat+i));
			i++;
		}
		fflush(galeri);
		fclose(galeri);
		printf("Arac Bilgileri Degistirildi.");
	}else printf("Dosya Acilamadi.(8)");
	}
	else printf("Dosya Acilamadi.(7)");


	}else printf("\n**Cikis Yapiliyor.Devam Etmek Icin Bir Tusa Basin.**");
	free(ma);free(se);free(mo);free(re);free(y);
	free(yil);free(km);free(fiyat);free(sira);
}
void sirala(int c)
{
	char *ma,*se,*mo,*re,s1[10];
	float *km,*yil,*fiyat,bellek;
	int *sira,*sayi,y,x,j=0,bellek1,*p,secim1;
	yil=(float*)calloc(sizeof(float),c);
	km=(float*)calloc(sizeof(float),c);
	fiyat=(float*)calloc(sizeof(float),c);
	sira=(int*)calloc(sizeof(int),c);
	sayi=(int*)calloc(sizeof(int),c);
	ma=(char*)malloc((sizeof(char)*20)*c);
	se=(char*)malloc((sizeof(char)*20)*c);
	mo=(char*)malloc((sizeof(char)*20)*c);
	re=(char*)malloc((sizeof(char)*20)*c);
	int i=0;

		printf("\n\t******************************************\n");
		printf("\t***          SIRALAMA TURLERI          ***\n");
		printf("\t***                                    ***\n");
		printf("\t***     1-) Fiyata Gore  *(AZALAN)*    ***\n");
		printf("\t***     2-) Fiyata Gore   *(ARTAN)*    ***\n");
		printf("\t***     3-) Yila Gore  *(B.KUCUGE)*    ***\n");
		printf("\t***     4-) Yila Gore  *(K.BUYUGE)*    ***\n");
		printf("\t***     5-) Km a Gore  *(B.BUYUGE)*    ***\n");
		printf("\t***     6-) Km a Gore  *(K.BUYUGE)*    ***\n");
		printf("\t***                                    ***\n");
		printf("\t***     0-) Ana Menu                   ***\n");
		printf("\t***                                    ***\n");
		//printf("\t******************************************\n");
		printf("\t******************************************\n");
		printf("\t***       Lutfen Secim Yapiniz  :  ");scanf("%s",s1);while(kontrol(s1)==0 || atoi(s1)<0 || atoi(s1)>6){
			printf("Lutfen Dogru Bir Deger Giriniz  :");scanf("%s",s1);
		}secim1=atoi(s1);

	if(secim1!=0)
	{

	FILE *galeri;
	if((galeri=fopen("aracbilgileri.txt","r"))!=0)
	{
	while(!feof(galeri))
	{

		fscanf(galeri,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",(sira+i),(ma+20*i),(se+20*i),(mo+20*i),(re+20*i),(yil+i),(km+i),(fiyat+i));
		//printf("%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",*(sira+i),(ma+50*i),(se+50*i),(mo+50*i),(re+50*i),*km,*yil,*(fiyat+i));
	i++;
	}
	fclose(galeri);
	int i=1;


	switch(secim1)
	{
	case 1 :
	for(x=0; x<c; x++)
	{
		for(y=0; y<c; y++)
		{
			if(*(fiyat+y)<*(fiyat+x))
			{
			bellek=*(fiyat+y);
			bellek1=*(sira+y);
			*(fiyat+y)=*(fiyat+x);
			*(sira+y)=*(sira+x);
			*(fiyat+x)=bellek;
			*(sira+x)=bellek1;

			}
		}
	}
	break;
	case 2 :
		for(x=0; x<c; x++)
	{
		for(y=0; y<c; y++)
		{
			if(*(fiyat+y)>*(fiyat+x))
			{
			bellek=*(fiyat+y);
			bellek1=*(sira+y);
			*(fiyat+y)=*(fiyat+x);
			*(sira+y)=*(sira+x);
			*(fiyat+x)=bellek;
			*(sira+x)=bellek1;
			}
		}
	}
	break;
	case 3 :
		for(x=0; x<c; x++)
	{

		for(y=0; y<c; y++)
		{
			if(*(yil+y)<*(yil+x))
			{
			bellek=*(yil+y);
			bellek1=*(sira+y);
			*(yil+y)=*(yil+x);
			*(sira+y)=*(sira+x);
			*(yil+x)=bellek;
			*(sira+x)=bellek1;

			}



		}
	}break;
	case 4 :
		for(x=0; x<c; x++)
	{

		for(y=0; y<c; y++)
		{
			if(*(yil+y)>*(yil+x))
			{
			bellek=*(yil+y);
			bellek1=*(sira+y);
			*(yil+y)=*(yil+x);
			*(sira+y)=*(sira+x);
			*(yil+x)=bellek;
			*(sira+x)=bellek1;

			}



		}
	}break;
	case 5 :
		for(x=0; x<c; x++)
		{

		for(y=0; y<c; y++)
		{
			if(*(km+y)<*(km+x))
			{
			bellek=*(km+y);
			bellek1=*(sira+y);
			*(km+y)=*(km+x);
			*(sira+y)=*(sira+x);
			*(km+x)=bellek;
			*(sira+x)=bellek1;

			}
		}
	}break;
	case 6 :
			for(x=0; x<c; x++)
	{

		for(y=0; y<c; y++)
		{
			if(*(km+y)>*(km+x))
			{
			bellek=*(km+y);
			bellek1=*(sira+y);
			*(km+y)=*(km+x);
			*(sira+y)=*(sira+x);
			*(km+x)=bellek;
			*(sira+x)=bellek1;

			}
		}
	}break;

	case 0 :break;

	}
	printf("\n\n\n");
	i=0;
	if((galeri=fopen("aracbilgileri.txt","r"))!=0)
	{
	while(!feof(galeri))
	{
		fscanf(galeri,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",(sayi+i),(ma+20*i),(se+20*i),(mo+20*i),(re+20*i),(km+i),(yil+i),(fiyat+i));
	//	printf("%d )%s\t%s\t%s\t%s\t%.f\t%.f\t%.f\t\n",*(sayi+i),(ma+20*i),(se+20*i),(mo+20*i),(re+20*i),*(km+i),*(yil+i),*(fiyat+i));
	i++;
	}
	fclose(galeri);
		i=0;
system("cls");
	if((galeri=fopen("aracbilgileri.txt","w"))!=0)
	{

	for(x=0; x<c; x++)
	{

		for(y=0; y<c; y++)
		{
			if(*(sira+i)==*(sayi+y))
			{

			fprintf(galeri,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",i+1,(ma+20*y),(se+20*y),(mo+20*y),(re+20*y),*(km+y),*(yil+y),*(fiyat+y));
			}

		}
		i++;
	}
		 fflush(galeri);
		 fclose(galeri);
		}else printf("dosya acilamadi.");
		       aracbilgileri(c);
} else printf("dosya acilamadi.");
}else printf("galeri dosyasi acilamadi.");
}else printf("cikis");
  free(ma);free(se);free(mo);free(re);
  free(yil);free(km);free(fiyat);
  free(sira);free(sayi);
}

void secenekler(int c)
{      // printf("\n");
	printf("\n\t******************************************\n");
	printf("\t***                                    ***\n");
	printf("\t***       1-) Arac Ekle                ***\n");
	printf("\t***       2-) Arac Sil                 ***\n");
	printf("\t***       3-) Araclari Listele         ***\n");
	printf("\t***       4-) Araclari Sirala          ***\n");
	printf("\t***       5-) Arac Bul                 ***\n");
	printf("\t***       6-) Arac Duzenle             ***\n");
	printf("\t***       0-) Cikis                    ***\n");
	printf("\t***                                    ***\n");
	printf("\t***         %d arac var.               ***\n",c);
	printf("\t******************************************\n");
	printf("\t***       Lutfen Secim Yapiniz  :  ");
}
void aracsil(int a)
{

	char *ma,*se,*mo,*re,sil[10];
	float *yil,*km,*fiyat;
	int silinen,i=0,j=0,eleman,*sira;
	ma=(char*)malloc((sizeof(char)*20*4)*a);
	se=(char*)malloc((sizeof(char)*20*4)*a);
	mo=(char*)malloc((sizeof(char)*20*4)*a);
	re=(char*)malloc((sizeof(char)*20*4)*a);
	sira=(int*)calloc(sizeof(int),a);
	int k;
	yil=(float*)calloc(sizeof(float),3*a);
	km=(float*)calloc(sizeof(float),3*a);
	fiyat=(float*)calloc(sizeof(float),3*a);
	printf("\n\t*****************************************\n");
	printf("\t***                                  ****\n");
	printf("\t***  0 -) ANA MENU                   ****\n");
	printf("\t***                                  ****\n");
	printf("\t*****************************************\n");
	printf("\t***                                  ****\n");
	printf("\t***  Silinecek Arac Numarasi  :  ");scanf("%s",sil);while(kontrol(sil)==0 || atoi(sil)<0 ||atoi(sil)>a)
	{
	printf("Lutfen Gecerli Bir Arac Numarasi Giriniz  :"); scanf("%s",sil);

	}silinen=atoi(sil);
	if(silinen!=0)
	{

	FILE *galeri;
	if((galeri=fopen("aracbilgileri.txt","r"))!=0)
	{

	while(!feof(galeri))
	{

		fscanf(galeri,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",(sira+i),(ma+i*20),(se+i*20),(mo+i*20),(re+i*20),(yil+i),(km+i),(fiyat+i));
		i++;
	}
	fclose(galeri);

	i=0;
	if((galeri=fopen("aracbilgileri.txt","w"))!=0)
	{


	while(i<a)
	{
	while((i+1)!=silinen && i<a)
	{

		fprintf(galeri,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",*(sira+j),(ma+i*20),(se+i*20),(mo+i*20),(re+i*20),*(yil+i),*(km+i),*(fiyat+i));
	i++;
	j++;
	}
	i++;

	}

	printf("\n%d.Arac Silindi.Devam Etmek Icin Bir Tusa Basin.\n",silinen);
	 fflush(galeri);
	 fclose(galeri);
	}else printf("(2)dosya acilamadi.");
	}else printf("(1)dosya acilamadi.");
	}else{
system("cls");
	printf("\nSilme Islemi Iptal Edildi.Devam Etmek Icin Bir Tusa Basin.");

	}free(ma);
	free(se);
	free(mo);
	free(re);
	free(km);
	free(yil);
	free(fiyat);
	free(sira);
}

int hesapla()
{
 char *bilgi;
 float *sbilgi;
 int *sira,i=1;
 bilgi=(char*)malloc((sizeof(char)*20)*4);
 sbilgi=(float*)calloc((sizeof(float)*3),1);
 sira=(int*)calloc(sizeof(int),1);
 FILE *galeri;
 if((galeri=fopen("aracbilgileri.txt","r"))!=0)
 {


 while(!feof(galeri))
{
	bilgi=(char*)realloc(bilgi,(sizeof(char)*20*4)*i);//((sizeof(char)*50)*4)
	sira=(int*)realloc(sira,(sizeof(int)*i));
	sbilgi=(float*)realloc(sbilgi,(sizeof(float)*3)*i);

	fscanf(galeri,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t\n",sira,bilgi,bilgi+20,bilgi+40,bilgi+60,sbilgi,sbilgi+1,sbilgi+2);
 //	printf("%d ) %s\t%s\t%s\t%s\t%.f\t%.f\t%.f\t\n",*sira,bilgi,bilgi+20,bilgi+40,bilgi+60,*sbilgi,*(sbilgi+1),*(sbilgi+2));
	i++;
}

}else printf("Sayac dosyayi acilamadi.Lutfen programý yeniden baslatiniz.\n\n\n");
fflush(galeri);
fclose(galeri);
free(bilgi);
free(sbilgi);



 return *sira;
free(sira);
fflush(galeri);

}
int main()
{
	int secim=1,b,secim1;
	char s[10],s1[10];
	FILE *galeri;
if((galeri=fopen("aracbilgileri.txt","a"))!=0)
{
  fclose(galeri);
} else{printf("dosya yok");
}

	while(secim!=0)
	{
system("cls");
	while(secim!=0)
	{
	b=hesapla();

	secenekler(b);
	scanf("%s",s);while(kontrol(s)==0 || (0>atoi(s) || atoi(s)>6)){printf("\nLutfen Dogru Bir Deger giriniz :");scanf("%s",s);  }	printf("\n\n");
	secim=atoi(s);
system("cls");

	if(secim==1)
	{
		aracekle(b);
		getch();
		break;
	}
	else if(secim==2)
	{
		if(b==0)
		{
			printf("Kayitli Arac Bulunamadi.");

		}
		else{
		aracsil(b);
		}
		getch();
		break;
	}
	else if(secim==3)
	{
		if(b==0)
		{
			printf("Kayitli Arac Bulunamadi."); getch();
		}
		else {
		aracbilgileri(b);
		}
		break;
	}
	else if(secim==4)
	{
			if(b==0)
		{
			printf("Kayitli Arac Bulunamadi.");  getch();

		}
		else {
system("cls");

		sirala(b);
system("cls");
}
		break;
	}
	else if(secim==5)
	{
		if(b==0)
		{
			printf("Kayitli Arac Bulunamadi.");  getch();
		}
		else{
		arama(b);
		}
		break;
	}
	else if(secim==6)
	{
		if(b==0)
		{
			printf("Kayitli Arac Bulunamadi.");

		}
		else{
		duzenle(b);
		}
		getch();
		break;
	}
	else break;
}
}
return 1;
	getch();
}
