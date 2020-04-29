/**
*
* @author Aslıhan Çetiner aslihan.cetiner@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* G171210014 1-C 
* </p>
*/
#include "Rastgele.h"

// Random class i icin olusturma fonksiyonu yazildi.
Rastgele RastgeleOlustur(){
	Rastgele this;
	this = (Rastgele)malloc(sizeof(struct RASTGELE));
	this->randomruret=&RandomRUret;
	this->randomyasuret=&RandomYasUret;
	this->randomuret=&RandomUret;
	this->Yoket=&RastgeleYoket;
	this->lfsr = 0xACE1u;
	this->previous = 0;
	this->bit = 0x00000;
	return this;
}

// Sistem clock unu alabilmek icin fonksiyon yazildi.
int system_clock(){
	clock_t t1;
	t1 = clock();
	return t1;
}
// verilen aralıkta Rastgele sayi ureten fonksiyon yazildi.
int RandomRUret(const Rastgele rast){
	rast->bit = ((rast->lfsr >> 0) ^ (rast->lfsr >> 2) ^ (rast->lfsr >> 3) ^ (rast->lfsr >> 5) ) & 1;
	rast->lfsr = (rast->lfsr >> 1) | (rast->bit << 15);
	rast->previous = rast->lfsr;
	return (rast->lfsr * (unsigned)system_clock()) % 100;
}
//  yaş için 0-100 aralığında Rastgele sayi ureten fonksiyon yazildi.
unsigned RandomYasUret(const Rastgele rast){
	rast->bit = ((rast->lfsr >> 0) ^ (rast->lfsr >> 2) ^ (rast->lfsr >> 3) ^ (rast->lfsr >> 5) ) & 1;
	rast->lfsr = (rast->lfsr >> 1) | (rast->bit << 15);
	rast->previous = rast->lfsr;
	return (rast->lfsr * (unsigned)system_clock()) % 100;
}
// 0-10 arası Rastgele sayi ureten fonksiyon yazildi.
int RandomUret(const Rastgele rast){
	rast->bit = ((rast->lfsr >> 0) ^ (rast->lfsr >> 2) ^ (rast->lfsr >> 3) ^ (rast->lfsr >> 5) ) & 1;
	rast->lfsr = (rast->lfsr >> 1) | (rast->bit << 15);
	rast->previous = rast->lfsr;
	return (rast->lfsr * (unsigned)system_clock()) % 10;
}

// Yoket fonksiyonu yazildi.
void RastgeleYoket(Rastgele ras){
	if(ras == NULL) return;
	free(ras);
	ras = NULL;
}