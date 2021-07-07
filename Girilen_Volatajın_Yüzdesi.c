#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <conio.h>
#include <math.h>
#include <time.h>

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

void yuzde_yon_fonksiyonu(int x_adc_min, int x_adc_max, int x_adc_center, int x_adc_center_dead, int x_adc_reverse, int x_adc_min_alarm, int x_adc_max_alarm, int x_girilenvoltaj, float *joystikyuzde, uint8_t *joystikyon)
{
//(adc_max, adc_min, adc_center, adc_center_dead, adc_max_alarm, adc_min_alarm, adc_reverse, girilenvoltaj, joystikyuzde, joystikyon);

    int max_a=0, min_a=0;
    // MAX-ALARMDAN SONRA YANI 4750 DEGERINDEN SONRA YON & YUZDE 0 OLACAK SEKILDE EKRANA VERIYOR
    if(x_girilenvoltaj >= (x_adc_max + x_adc_min_alarm))
    {
        *joystikyon = 0;
        *joystikyuzde = 0;
    }

    // 4500 ILA 4750 ARASINDA OLAN DEGERLER
    else if((x_girilenvoltaj>=x_adc_max) && (x_girilenvoltaj<x_adc_max + x_adc_min_alarm))
    {
        *joystikyon = 1;
        *joystikyuzde = 100;
    }

    // 2750 ILA 4500 ARASINDA OLAN DEGERLERI LINEAR FONKSIYONU GONDERIP, ISLEM SONRASI EKRANA VERECEK OLAN BOLUM
    else if((x_girilenvoltaj>=x_adc_center + x_adc_min_alarm) && (x_girilenvoltaj<x_adc_max))
    {
        *joystikyon = 1;
        *joystikyuzde = linearfonksiyonu((x_adc_center + x_adc_min_alarm), 0, x_adc_max, 100, x_girilenvoltaj);
    }

    // 2250 ILA 2750 ARASINDA OLACAK OLAN DEGERLERI OLU BOLGE OLARAK; YUZDE & YON SIFIR OLACAK SEKILDE VERECEK
    else if((x_girilenvoltaj>=x_adc_center - x_adc_min_alarm) && (x_girilenvoltaj<x_adc_center + x_adc_min_alarm))
    {
        *joystikyon = 0;
        *joystikyuzde = 0;
    }

    // 500 ILA 2250 ARASINDA OLAN DEGERLERI LINEAR FONKSIYONU GONDERIP, ISLEM SONRASI EKRANA VERECEK OLAN BOLUM
    else if((x_girilenvoltaj>=x_adc_min) && (x_girilenvoltaj<x_adc_center - x_adc_min_alarm))
    {
        *joystikyon = 2;
        *joystikyuzde = linearfonksiyonu((x_adc_center - x_adc_min_alarm), 0, x_adc_min, 100, x_girilenvoltaj);
    }

    // 300 ILA 500 ARASINDA OLAN DEGERLERI MIN DERECE OLACAK SEKILDE VERECEK
    else if((x_girilenvoltaj>=x_adc_min-x_adc_center_dead) && (x_girilenvoltaj<x_adc_min))
    {
        *joystikyon = 2;
        *joystikyuzde = 100;
    }

    // 300' DEN ASAGI OLACAK SEKILDE HESAPLAMA YAPACAK OLAN FONKSIYON
    else if(x_girilenvoltaj<x_adc_min-x_adc_center_dead)
    {
        *joystikyon = 0;
        *joystikyuzde = 0;
    }
/**
    else
    {

    }
*/
}



int main()
{
    // KULLANICIDAN ALINACAK OLAN DEGER, DEGISKENI
    int girilenvoltaj;

    // DEGISKENLERIN SABIT DEGERLERI; MAX - MIN - CENTER - CENTRE_DEAD
    int adc_max=4500, adc_min=500, adc_center=2500, adc_center_dead=200;

    //MAX & MIN ALARM DEGISKENLERI ve DEGERLERI
    int adc_max_alarm=4700, adc_min_alarm=250, adc_reverse=0;

    // JOYSTIK YON ve YUZDE DEGERLERI PROGRAM HESAPLAYACAK
    float joystikyuzde;
    uint8_t joystikyon;

    tekrarla : printf("Voltaj Degeri : "); scanf("%d",&girilenvoltaj);

    /** YUZDE VE YON VERECEK OLAN HESAPALAMA FONKSIYONUNA GONDERILEN DEGERLER*/
    yuzde_yon_fonksiyonu(adc_min, adc_max, adc_center, adc_center_dead, adc_reverse, adc_min_alarm, adc_max_alarm, girilenvoltaj, &joystikyuzde, &joystikyon);

    printf("Joystik Yon   : %d \n", joystikyon);
    printf("Joystik Yuzde : %.2f \n\n", joystikyuzde);

    goto tekrarla;
    return 0;
}

