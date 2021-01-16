
// Mücahid IŞIK 2018

#include <time.h>
#include <fstream>
#include <stdlib.h> 
#include <iostream>
#include <string.h>
#include <sstream> 
#include <iomanip> 


using namespace std;
int Gnumara = 99;
int sinifSayisi = 1;
int satirr1 = 0;
int satirr2 = 0;
int satirr3 = 0;
int satirr4 = 0;
int satirr5 = 0;
int baslikSayisi = 0;

char solUstKose = 201;
char duz = 205;
char sagUstKose = 187;
char solAltKose = 200;
char sagAltKose = 188;
char dikey = 186;

void ustYazdir(int elemanSayisi)
{

	cout << solUstKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;
	}
	cout << sagUstKose;
}

void altYazdir(int elemanSayisi)
{
	cout << solAltKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;
	}
	cout << sagAltKose;
}


class Ogrenci
{
private:

public:
	string isim;
	string soyisim;
	int numara;
	//DosyaYonetim dosyam;
	Ogrenci()
	{
		/*isim = dosyam.isimGetir();
		soyisim = dosyam.soyisimGetir();
		numara = dosyam.numaraGetir();*/
		srand(time(NULL));

		int sayac = 0;
		string getirilenIsim;
		string isimler[200];
		int kacinci = rand() % 200;

		ifstream txtOku("isimler.txt");
		while (txtOku >> getirilenIsim)
		{
			isimler[sayac] = getirilenIsim;
			sayac++;
			if (sayac == 200)
			{
				break;
			}
		}
		isim = isimler[kacinci];
		txtOku.close();

		int sayac2 = 0;
		string getirilenSoyIsim;
		string soyIsimler[200];
		int kacinci2 = rand() % 200;

		ifstream txtOku2("soyisimler.txt");
		while (txtOku2 >> getirilenSoyIsim)
		{
			soyIsimler[sayac2] = getirilenSoyIsim;
			sayac2++;
			if (sayac2 == 200)
			{
				break;
			}
		}
		soyisim = soyIsimler[kacinci2];
		txtOku2.close();
		Gnumara++;
		numara = Gnumara;

	};

	string getIsim()
	{
		return isim;
	}
	string getSoyIsim()
	{
		return soyisim;
	}
	int getNumara()
	{
		return numara;
	}

};


class Sinif
{
public:
	char alfabe[23] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Y','Z' };
	string sinifIsmi;
	int kacinciSinif;
	int kacOgrenci = 0;
	Ogrenci* ogrenciler[100];

	Sinif()
	{
		srand(time(NULL));
		int kacinci = rand() % 23;
		sinifIsmi = alfabe[kacinci];
		kacinciSinif = sinifSayisi;
		sinifSayisi++;
	}

	void ogrenciEkle(Ogrenci* ogr)
	{
		ogrenciler[kacOgrenci] = ogr;
		kacOgrenci++;
	}
	void ogrenciSil(int ogrNo)
	{

		for (int i = 0; i < 100; i++)
		{
			int gecici = ogrenciler[i]->numara;
			if (gecici == ogrNo)
			{
				ogrenciler[i] = NULL;
			}
		}

		int j = 0;
		Ogrenci* temp[100];
		for (int i = 0; i < 100; i++)
		{
			if (ogrenciler[i] == NULL)
			{

			}
			else
			{
				temp[j] = ogrenciler[i];
				j++;
			}
		}

		for (int i = 0; i < 100; i++)
		{
			ogrenciler[i] = NULL;
		}

		for (int i = 0; i < 100; i++)
		{
			ogrenciler[i] = temp[i];
		}
		kacOgrenci--;
	}

};


class DosyaYonetim
{
public:
	string isimGetir()
	{
		srand(time(NULL));

		int sayac = 0;
		string getirilenIsim;
		string isimler[200];
		int kacinci = rand() % 200;

		ifstream txtOku("isimler.txt");
		while (txtOku >> getirilenIsim)
		{
			isimler[sayac] = getirilenIsim;
			sayac++;
			if (sayac == 200)
			{
				break;
			}
		}
		string isim = isimler[kacinci];

		txtOku.close();
		return isim;
	}

	string soyisimGetir()
	{
		srand(time(NULL));

		int sayac = 0;
		string getirilenSoyIsim;
		string soyIsimler[200];
		int kacinci = rand() % 200;

		ifstream txtOku2("soyisimler.txt");
		while (txtOku2 >> getirilenSoyIsim)
		{
			soyIsimler[sayac] = getirilenSoyIsim;
			sayac++;
			if (sayac == 200)
			{
				break;
			}
		}
		string soyIsim = soyIsimler[kacinci];

		txtOku2.close();
		return soyIsim;
	}

	int numaraGetir()
	{
		Gnumara++;
		return Gnumara;
	}

	void ogrenciKaydet(Ogrenci* ogrencim)
	{

	}

	void sinifKaydet(Sinif* sinifim)
	{
		ofstream myfile;
		myfile.open("kayitlar.txt");
		myfile << sinifim->kacinciSinif << sinifim->sinifIsmi << endl;
		myfile << sinifim->kacOgrenci << endl;
		int sayi = sinifim->kacOgrenci;
		for (int i = 0; i < sayi; i++)
		{
			myfile << sinifim->ogrenciler[i]->isim << sinifim->ogrenciler[i]->soyisim << sinifim->ogrenciler[i]->numara << endl;
		}
		myfile.close();
	};


	//•	kayitlar.txt dosyasındaki verileri okuyup bu verilere göre bir Okul nesnesi oluşturup getirecek bir fonksiyona sahip olmalıdır.
};


class Okul
{
public:
	string basliklar[100];
	string satir1[100];
	string satir2[100];
	string satir3[100];
	string satir4[100];
	string satir5[100];

	Okul()
	{
		int kacTane = 999;
		int sayac = 0;
		string veri;
		ifstream txtOku("kayitlar.txt");
		while (txtOku >> veri)
		{
			if (sayac == 0)
			{
				basliklar[baslikSayisi] = veri;
				baslikSayisi++;
				sayac++;
			}
			else if (sayac == 1)
			{
				stringstream geek(veri);
				geek >> kacTane;
				sayac++;
			}
			else if (sayac == 2 && kacTane != 0)
			{
				satir1[satirr1] = veri;
				satirr1++;
				sayac++;
				kacTane--;
				if (kacTane == 0)
				{
					sayac = 0;
				}
			}
			else if (sayac == 3 && kacTane != 0)
			{
				satir2[satirr2] = veri;
				satirr2++;
				sayac++;
				kacTane--;
				if (kacTane == 0)
				{
					sayac = 0;
				}
			}
			else if (sayac == 4 && kacTane != 0)
			{
				satir3[satirr3] = veri;
				satirr3++;
				sayac++;
				kacTane--;
				if (kacTane == 0)
				{
					sayac = 0;
				}
			}
			else if (sayac == 5 && kacTane != 0)
			{
				satir4[satirr4] = veri;
				satirr4++;
				sayac++;
				kacTane--;
				if (kacTane == 0)
				{
					sayac = 0;
				}
			}
			else if (sayac == 6 && kacTane != 0)
			{
				satir5[satirr5] = veri;
				satirr5++;
				sayac++;
				kacTane--;
				if (kacTane == 0)
				{
					sayac = 0;
				}
			}
			txtOku.close();
		}

	}
	void ekranaYazdir()
	{
		for (int i = 0; i < baslikSayisi; i++)
		{
			ustYazdir(16);
		}
		cout << endl;
		for (int i = 0; i < baslikSayisi; i++)
		{
			cout << dikey << setw(9) << basliklar[i] << setw(8) << dikey;
		}
		cout << endl;
		for (int i = 0; i < baslikSayisi; i++)
		{
			altYazdir(16);
		}
		cout << endl;
		for (int i = 0; i < satirr1; i++)
		{
			cout << dikey << setw(9) << satir1[i] << setw(8) << dikey;
		}
		for (int i = 0; i < satirr2; i++)
		{
			cout << dikey << setw(9) << satir2[i] << setw(8) << dikey;
		}
		for (int i = 0; i < satirr3; i++)
		{
			cout << dikey << setw(9) << satir3[i] << setw(8) << dikey;
		}
		for (int i = 0; i < satirr4; i++)
		{
			cout << dikey << setw(9) << satir4[i] << setw(8) << dikey;
		}
		for (int i = 0; i < satirr5; i++)
		{
			cout << dikey << setw(9) << satir5[i] << setw(8) << dikey;
		}


	}

};


class Program
{
public:
	Okul okulum;
	void calistir()
	{
		int secim = 0;
		string sinifAdi;
		int ogrNo;
		while (secim != 6)
		{

			okulum.ekranaYazdir();
			cout << "1. Ogrenci Ekle" << endl;
			cout << "2. Sinif Ekle" << endl;
			cout << "3. Ogrenci Degistir" << endl;
			cout << "4. Ogrenci Sil" << endl;
			cout << "5. Sinif Sil" << endl;
			cout << "6. Cikis" << endl;
			cin >> secim;

			while (secim > 6 || secim < 1)
			{
				cout << "Hatali secim yaptiniz...  Tekrar Deneyiniz....: ";
				cin >> secim;
			}
			switch (secim)
			{
			case 1:
				cout << "sinif adi : "; cin >> sinifAdi;

				system("pause");
				system("cls");
				break;
			case 2:
				system("pause");
				system("cls");
				break;
			case 3:
				cout << "ogrenci no : "; cin >> ogrNo;
				system("pause");
				system("cls");
				break;
			case 4:
				cout << "ogrenci no : "; cin >> ogrNo;
				system("pause");
				system("cls");
				break;
			case 5:
				cout << "sinif adi : "; cin >> sinifAdi;
				system("pause");
				system("cls");
				break;
			case 6:

				break;
			}
		}


	}
};


int main()
{
	Program prog;
	prog.calistir();

}