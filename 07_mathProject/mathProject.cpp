#include<iostream>
#include<cstdlib>
#include<string>
#include<time.h>
using namespace std;
/*we don't have many questions,
so solve them all  one by one*/
enum soruSeviyeleri { kolay = 1, orta = 2, zor = 3, soruMix = 4 };
enum islemTurleri { arti = 1, eksi = 2, carpi = 3, bolum = 4, islemTuruMix = 5 };



string islemTuruEkranaBasmak(islemTurleri secilenislemTuru)
{
    switch (secilenislemTuru)
    {
    case arti:
        return "+";
        break;
    case eksi:
        return "-";
        break;
    case carpi:
        return "x";
        break;
    case bolum:
        return "/";
        break;


    default:
        return "\nislemTuruEkranaBasmak sorun var\n";
        break;
    }


}
islemTurleri enumislemTuruSecmek()
{
    short secim;
    do
    {
        cout << "islem turu: arti[1],eksi[2],carpi[3],bolum[4],mix[5] ? sayisini seciniz\n";
        cin >> secim;
    } while (secim < 1 || secim>5);

    return (islemTurleri)secim;

}
soruSeviyeleri enumSoruSeviyesiSecmek()
{
    short secim;
    do
    {
        cout << "soru seviyesi: kolay[1],orta[2],zor[3],mix[4] sayisini seciniz\n";
        cin >> secim;
    } while (secim < 1 || secim>4);

    return (soruSeviyeleri)secim;


}




int rastgeleSayi(int altSinir, int ustSinir)
{
    return rand() % ((ustSinir - altSinir) + 1) + altSinir;

}

void terminalRenk(bool dogru)
{
    if (dogru)
    {
        system("color 2F");
    }
    else
    {
        system("color 4F");
        cout << "\a";
    }
}

int soruSayisiAlmak()
{
    int soruSayisi = 0;
    cout << "test kac soruluk olacak\n";
    cin >> soruSayisi;
    return (soruSayisi);
}

string tabloyaBasmakicinislemTuru(islemTurleri islemTur)
{
    string islemturu[5] = { "arti","eksi","carpi","bolum" ,"mix" };
    return islemturu[islemTur - 1];

}

string tabloyaBasmakiciniSoruLeveli(soruSeviyeleri soruLeveli)
{
    string soruLeveliu[4] = { "kolay","orta","zor","mix" };
    return soruLeveliu[soruLeveli - 1];

}


struct stSoru
{
    int sayi1;
    int say2;
    soruSeviyeleri soruSevityesi;
    islemTurleri islemTuru;
    int dogruCevap;
    int kullanicininGirdiCevap;
    bool cevapDogruMu = false;

};

struct stSinav
{
    stSoru diziSoru[100];
    short soruSayisi;
    int doguruCevapsayisi = 0;
    int yanlisCevapSayisi = 0;
    soruSeviyeleri soruSevityesi2;
    islemTurleri islemTuru2;
    bool gectiMi = false;

};

int Hesaplayici(int sayi1, int sayi2, islemTurleri  secilenislem)
{

    switch (secilenislem)
    {
    case arti:
        return (sayi1 + sayi2);


    case  eksi:
        return (sayi1 - sayi2);


    case bolum:
        return (sayi1 / sayi2);

    case carpi:
        return (sayi1 * sayi2);

    default:
        return 999;


    }

}

soruSeviyeleri rastgeleSoruSeviyesiAlmak()
{
    return (soruSeviyeleri)rastgeleSayi(1, 3);
}

//1)bu kısımda önceki fonksiyonlardan yararlanarak  tek tek soru ouşturuyoruz
//bir soru olusturdugumuzu var sayalım
//bunu dizinin sıfırıncı kutusuna saklıyoruz tum bilgileri ile birlikete 
//burada stSinav için 5 bilgisini aldık  sayi1,sayi2,soruleveli,islemturu ve dogruCevap değişkenini aldık 
stSoru soruOlusturmak(soruSeviyeleri soruSeviyesi, islemTurleri islemTuru)
{
    stSoru olusturulacakSoru;
    if (soruSeviyesi == soruSeviyeleri::soruMix)
    {
        soruSeviyesi = (soruSeviyeleri)rastgeleSayi(1, 3);
    }
    if (islemTuru == islemTurleri::islemTuruMix)
    {
        islemTuru = (islemTurleri)rastgeleSayi(1, 4);
    }
    olusturulacakSoru.islemTuru = islemTuru;

    switch (soruSeviyesi)
    {
    case soruSeviyeleri::kolay:
        olusturulacakSoru.sayi1 = rastgeleSayi(1, 10);
        olusturulacakSoru.say2 = rastgeleSayi(1, 10);
        olusturulacakSoru.soruSevityesi = soruSeviyesi;

        olusturulacakSoru.dogruCevap = Hesaplayici(olusturulacakSoru.sayi1, olusturulacakSoru.say2, olusturulacakSoru.islemTuru);
        return olusturulacakSoru;



    case soruSeviyeleri::orta:
        olusturulacakSoru.sayi1 = rastgeleSayi(11, 50);
        olusturulacakSoru.say2 = rastgeleSayi(11, 50);
        olusturulacakSoru.soruSevityesi = soruSeviyesi;

        olusturulacakSoru.dogruCevap = Hesaplayici(olusturulacakSoru.sayi1, olusturulacakSoru.say2, olusturulacakSoru.islemTuru);
        return olusturulacakSoru;


    case soruSeviyeleri::zor:
        olusturulacakSoru.sayi1 = rastgeleSayi(51, 99);
        olusturulacakSoru.say2 = rastgeleSayi(51, 99);
        olusturulacakSoru.soruSevityesi = soruSeviyesi;

        olusturulacakSoru.dogruCevap = Hesaplayici(olusturulacakSoru.sayi1, olusturulacakSoru.say2, olusturulacakSoru.islemTuru);
        return olusturulacakSoru;

   
    }


}



//2)bir ustteki fonksiyonu kullanarak oluşturduğumuz soruları burada dizinin kutularına yerleştiriyoruz
void sinavOlustur(stSinav& sinav)
{
    for (int soru = 0; soru < sinav.soruSayisi; soru++)
    {
        sinav.diziSoru[soru] = soruOlusturmak(sinav.soruSevityesi2, sinav.islemTuru2);
    }

}

int soruCevapAlmak()
{
    int cevap = 0;
    cin >> cevap;
    return cevap;
}

void soruYazdir(stSinav& sinav, short soruNumarasi)
{
    cout << "\n";
    cout << "soru [" << soruNumarasi + 1 << "/" << sinav.soruSayisi << "]\n\n";
    cout << sinav.diziSoru[soruNumarasi].sayi1 << endl;
    cout << sinav.diziSoru[soruNumarasi].say2 << " ";
    cout << islemTuruEkranaBasmak(sinav.diziSoru[soruNumarasi].islemTuru);
    cout << "\n______________" << endl;
}
void cevapKarsilastirmak(stSinav& sinav, short soruNumarasi)
{


    if (sinav.diziSoru[soruNumarasi].kullanicininGirdiCevap != sinav.diziSoru[soruNumarasi].dogruCevap)
    {
        sinav.diziSoru[soruNumarasi].cevapDogruMu = false;
        sinav.yanlisCevapSayisi++;
        cout << "hatali cevap\n";
        cout << "dogru cevap: ";
        cout << sinav.diziSoru[soruNumarasi].dogruCevap;
        cout << "\n";

    }
    else
    {
        sinav.diziSoru[soruNumarasi].cevapDogruMu = true;
        sinav.doguruCevapsayisi++;
        cout << "cevap dogru :-)\n";
    }
    cout << endl;
    terminalRenk(sinav.diziSoru[soruNumarasi].cevapDogruMu);

}

//3)burada ise önceki adımda  doldurulmuş olan soru cevapları ile kullanıcıdan alacağımız soru cevapların
//karşılaştırıyoruz
//burada stSinav'ın son 2 değişkenini aldık kullanicininGirdiCevap ve gectiMi
void soruSormakVelistelemek(stSinav& sinav)
{
    //burada soruNUmarasi yerine "i " gibi düşün
    for (short soruNUmarasi = 0; soruNUmarasi < sinav.soruSayisi; soruNUmarasi++)
    {

        soruYazdir(sinav, soruNUmarasi);
        sinav.diziSoru[soruNUmarasi].kullanicininGirdiCevap = soruCevapAlmak();
        cevapKarsilastirmak(sinav, soruNUmarasi);

    }
    sinav.gectiMi = (sinav.doguruCevapsayisi >= sinav.yanlisCevapSayisi);

}

string sonKontrol(bool gecmek)
{
    if (gecmek)
    {
        return "gecti :-)";

    }
    else
        return "kaldi :-) ";
}
void soucTablosuYazdir(stSinav sinav)
{
    cout << "\n";
    cout << "__________________________\n\n";
   
          cout<<sonKontrol(sinav.gectiMi)<<endl;
    cout << "__________________________\n\n";
     cout << "ozet: "<<endl;
    cout << "soru numarsi: " << sinav.soruSayisi << endl;
    cout << "soru leveli : " << tabloyaBasmakiciniSoruLeveli(sinav.soruSevityesi2) << endl;
    cout << "islem turu  : " << tabloyaBasmakicinislemTuru(sinav.islemTuru2) << endl;
    cout << "dogru cevap sayisi :" << sinav.doguruCevapsayisi << endl;
    cout << "yanlis cevap cevap sayisi: " << sinav.yanlisCevapSayisi << endl;
    cout << "___________________________\n\n";

}
void oyunisleyisi()
{
    stSinav sinav;
    sinav.soruSayisi = soruSayisiAlmak();
    sinav.soruSevityesi2 = enumSoruSeviyesiSecmek();
    sinav.islemTuru2 = enumislemTuruSecmek();
    sinavOlustur(sinav);
    soruSormakVelistelemek(sinav);
    soucTablosuYazdir(sinav);


}

void terminalReset()
{
    system("cls");
    system("color 0F");

}
void basla()
{
    char tekrarOynamak = 'e';
    do
    {
        terminalReset();
        oyunisleyisi();
        cout << "tekrar oynayalim mi? E/H\n";
        cin >> tekrarOynamak;
    } while (tekrarOynamak == 'e' || tekrarOynamak == 'E');

}
int main()
{
    srand((unsigned)time(NULL));

    basla();
    return 0;



}