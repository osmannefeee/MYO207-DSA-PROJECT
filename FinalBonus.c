//Osman Efe Güleç
//2420161037
//https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=yjahz8rBKd

#include <stdio.h>

//tam sayi dizisini ekrana yazdırmamız için  
void dizi_yazdir(int dizi[], int BOYUT) {
    int i;
    for (i = 0; i < BOYUT; i++) {
        printf("%3d", dizi[i]);
    }
    printf("\n");
}

//takas işlemi için işaretçiler ile yaptığımız takaslama(swapping) kodu
void takas(int *ap, int *bp) {
    int gecici = *ap;
    *ap = *bp;
    *bp = gecici;
}

//baloncuk sıralamanın kodu 
void baloncuk_sirala(int dizi[], int BOYUT) {
    int i, j;
    int takas_oldu;
    //baloncuk sıralama için for döngüsü
    for (i = 0; i < BOYUT - 1; i++) {
        takas_oldu = 0;
        for (j = 0; j < BOYUT - i - 1; j++) {
            if (dizi[j] > dizi[j + 1]) {
                takas(&dizi[j], &dizi[j + 1]);
                takas_oldu = 1;
            }
        }
        if (takas_oldu == 0) break;
       //her tur sonucunu yazdırmak için 
        printf("%d. tur sonucu: ", i + 1);
        dizi_yazdir(dizi, BOYUT);
    }
}

//ikili aramanın kodu
int ikili_arama(int dizi[], int bas_ind, int son_ind, int aranan) {
    while (bas_ind <= son_ind) {
        int orta = bas_ind + (son_ind - bas_ind) / 2;//ikili arama böl ve fetih et taktiği için orta noktayı bulma 

        if (dizi[orta] == aranan)//aranan sayı bulundu
            return orta;

        if (dizi[orta] < aranan) //aranan sayı orta noktanın sağında 
            bas_ind = orta + 1;
        else
            son_ind = orta - 1; //aranan sayı orta noktanın solunda
    }
    return -1; //aranan sayı dizide yoksa -1 döndürür
}

int main() {
    int A[] = {60, 61, 55, 53, 8, 5, 19, 57, 52, 67, 74, 1};
    int N = sizeof(A) / sizeof(A[0]);//dizinin eleman sayisini sizeof fonksiyonu ile otamatik hesaplar
    int aranan_sayi, sonuc;

    printf("Orijinal Dizi:\n");
    dizi_yazdir(A, N);//orjinal diziyi bize yazdirir
    
    baloncuk_sirala(A, N);//baloncuk siralamayı bize yazdirir
    
    printf("Siralanmis Sonuc Dizisi:\n");
    dizi_yazdir(A, N);//sıralanmıs diziyi bize yazdirir

    printf("\nAranacak sayiyi giriniz: ");
    if (scanf("%d", &aranan_sayi) == 1) {
        sonuc = ikili_arama(A, 0, N - 1, aranan_sayi);//ikili arama fonksiyonunu bize çağırır

        if (sonuc != -1) //sonuç -1 değilse yani döngüyü tekrar döndürmeyecek ise sayı bulundu
            printf("Sonuc: %d sayisi %d. indiste bulundu.\n", aranan_sayi, sonuc);
        else // -1 ise sayı bulunamadı döngüye tekrar girilir 
            printf("Sonuc: %d sayisi dizide bulunamadi.\n", aranan_sayi);
    }

    return 0;
}