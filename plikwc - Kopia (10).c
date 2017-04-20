#include<iostream.h>   jakis randomowy tekst

#include<stdlib.h>
main()
{
randomize;

const int kol=5;
const int wie=5;
const size=kol*wie;

int tablica[kol][wie];

int i,j;


for (i=0;i<kol;i++)
	 {
	  for(j=0;j<wie;j++)
		{
		 tablica[i][j]=random(100);// wstawienie wartosci
		}
	 }



for ( i=0;i<kol;i++)
	 {
	  for(j=0;j<wie;j++)
		{
		 cout<<tablica[i][j]<<"\t";//wyswietlenie tablicy dwuwymiarowej
		}
		cout<<endl;
	 }



int tab[size];
int numer=0;


for ( i=0;i<kol;i++)
	 {
	  for(j=0;j<wie;j++)
		{
		tab[numer]=tablica[i][j];// wstawienie do tablicy jednowymiarowej
		numer++;
		}
	 }



int s=size;
int l,pom;


for (;s!=0;s--)
	 {
	 for (l=1;l!=size;l++)
		{
		 if (tab[l]<tab[l-1])
			 {
			 pom=tab[l-1];
			 tab[l-1]=tab[l];    //sortowanie
			 tab[l]=pom;
			 }
		}
	 }



cout<<endl;

numer=0;
for ( i=0;i<kol;i++)
	 {
	  for(j=0;j<wie;j++)
		{
		tablica[i][j]=tab[numer];// wstawienie do tablicy dwuwymiarowej
		numer++;
		}
	 }



cout<<endl;

for ( i=0;i<kol;i++)
	 {
	  for(j=0;j<wie;j++)
		{
		 cout<<tablica[i][j]<<"\t ";//wyswietlenie tablicy dwuwymiarowej
		}
		cout<<endl;
	 }




}










