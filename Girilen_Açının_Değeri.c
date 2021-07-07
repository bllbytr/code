#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#define PI 3.14

/**
    X0 ADC DEGERLERI
    Y0 % DEGERLERI

    X1 ADC DEGERLERI
    Y1 % DEGERLERI

    X2 ADC DEGERLERI
*/
float linearfonksiyonu(float x0, float y0, float x1, float y1, float x2)
{
    float l_result;
    float l_slope;
    float l_b;
    l_slope  = ( y1- y0)/( x1-x0);
    l_b      = y0 - ( l_slope * x0 );
    l_result = x2 * l_slope + l_b ;
    return l_result ;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void girilenacinin_uzunlugu_fonksiyonu(int x_aci_1, int x_aci_2, int x_aci_3, int x_aci_4, int x_aci_5, int x_aci_6, int x_aci_7, int x_aci_8, int x_aci_9, int x_aci_10,
                                       int x_uzunluk_1, int x_uzunluk_2, int x_uzunluk_3, int x_uzunluk_4, int x_uzunluk_5, int x_uzunluk_6, int x_uzunluk_7, int x_uzunluk_8, int x_uzunluk_9, int x_uzunluk_10,
                                       int alinan_aci, float *uzunluk_veren)
{

    // GIRILEN ACININ 0' A ESIT VE 0' DAN DAHA KUCUK OLMA DURUMUNDA CALISACAGI BLOK
    if(alinan_aci<=0)
    {
        *uzunluk_veren = linearfonksiyonu(x_aci_1, x_uzunluk_1, x_aci_2, x_uzunluk_2, alinan_aci);
    }

    // GIRILEN ACININ 0 ILA  100 ARASINDA OLMA DURUMUNDA CALISACAGI BLOK
    else if((alinan_aci>=x_aci_1) && (alinan_aci<x_aci_2))
    {
        *uzunluk_veren = linearfonksiyonu(x_aci_1, x_uzunluk_1, x_aci_2, x_uzunluk_2, alinan_aci);
    }

    // GIRILEN ACININ 100 ILA  200 ARASINDA OLMA DURUMUNDA CALISACAGI BLOK
    else if((alinan_aci>=x_aci_2) && (alinan_aci<x_aci_3))
    {
        *uzunluk_veren = linearfonksiyonu(x_aci_2, x_uzunluk_2, x_aci_3, x_uzunluk_3, alinan_aci);
    }

    // GIRILEN ACININ 200 ILA  300 ARASINDA OLMA DURUMUNDA CALISACAGI BLOK
    else if((alinan_aci>=x_aci_3) && (alinan_aci<x_aci_4))
    {
        *uzunluk_veren = linearfonksiyonu(x_aci_3, x_uzunluk_3, x_aci_4, x_uzunluk_4, alinan_aci);
    }

    // GIRILEN ACININ 300 ILA  400 ARASINDA OLMA DURUMUNDA CALISACAGI BLOK
    else if((alinan_aci>=x_aci_4) && (alinan_aci<x_aci_5))
    {
        *uzunluk_veren = linearfonksiyonu(x_aci_4, x_uzunluk_4, x_aci_5, x_uzunluk_5, alinan_aci);
    }

    // GIRILEN ACININ 400 ILA  500 ARASINDA OLMA DURUMUNDA CALISACAGI BLOK
    else if((alinan_aci>=x_aci_5) && (alinan_aci<x_aci_6))
    {
        *uzunluk_veren = linearfonksiyonu(x_aci_5, x_uzunluk_5, x_aci_6, x_uzunluk_6, alinan_aci);
    }

    // GIRILEN ACININ 500 ILA  600 ARASINDA OLMA DURUMUNDA CALISACAGI BLOK
    else if((alinan_aci>=x_aci_6) && (alinan_aci<x_aci_7))
    {
        *uzunluk_veren = linearfonksiyonu(x_aci_6, x_uzunluk_6, x_aci_7, x_uzunluk_7, alinan_aci);
    }

    // GIRILEN ACININ 600 ILA  700 ARASINDA OLMA DURUMUNDA CALISACAGI BLOK
    else if((alinan_aci>=x_aci_7) && (alinan_aci<x_aci_8))
    {
        *uzunluk_veren = linearfonksiyonu(x_aci_7, x_uzunluk_7, x_aci_8, x_uzunluk_8, alinan_aci);
    }

    // GIRILEN ACININ 700 ILA  800 ARASINDA OLMA DURUMUNDA CALISACAGI BLOK
    else if((alinan_aci>=x_aci_8) && (alinan_aci<x_aci_9))
    {
        *uzunluk_veren = linearfonksiyonu(x_aci_8, x_uzunluk_8, x_aci_9, x_uzunluk_9, alinan_aci);
    }

    // GIRILEN ACININ 800 ILA  850 ARASINDA OLMA DURUMUNDA CALISACAGI BLOK
    else if((alinan_aci>=x_aci_9) && (alinan_aci<x_aci_10))
    {
        *uzunluk_veren = linearfonksiyonu(x_aci_9, x_uzunluk_9, x_aci_10, x_uzunluk_10, alinan_aci);
    }

    // GIRILEN ACININ 850' DEN BUYUK OLMA OLMA DURUMUNDA CALISACAGI BLOK
    else if(alinan_aci>=x_aci_10)
    {
        *uzunluk_veren = linearfonksiyonu(x_aci_10, x_uzunluk_10, x_aci_10, x_uzunluk_10, alinan_aci);
    }
/**
    else
    {

    }
*/
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int girilenaci;

    float uzunluk_acisi;

    int aci_1 = 0, aci_2 = 100, aci_3 = 200, aci_4 = 300, aci_5 = 400, aci_6 = 500, aci_7 = 600, aci_8 = 700, aci_9 = 800, aci_10 = 850;

    int uzunluk_1 = 1000,
        uzunluk_2 = 2000,
        uzunluk_3 = 3000,
        uzunluk_4 = 4000,
        uzunluk_5 = 5000,
        uzunluk_6 = 6000,
        uzunluk_7 = 7000,
        uzunluk_8 = 8000,
        uzunluk_9 = 9000,
        uzunluk_10 = 10000;

    tekrarla: printf("Aci Gir : "); scanf("%d", &girilenaci);

    /** GIRILEN ACININ UZUNLUGUNU VERECEK OLAN; HESAPALAMA FONKSIYONUNA GONDERILEN DEGERLER*/
    girilenacinin_uzunlugu_fonksiyonu(aci_1, aci_2, aci_3, aci_4, aci_5, aci_6, aci_7, aci_8, aci_9, aci_10,
                                      uzunluk_1, uzunluk_2, uzunluk_3, uzunluk_4, uzunluk_5, uzunluk_6, uzunluk_7, uzunluk_8, uzunluk_9, uzunluk_10,
                                      girilenaci, &uzunluk_acisi);

    printf("Acinin Uzunlugu : %.2f \n\n", uzunluk_acisi);

    goto tekrarla;

    return 0;
}
