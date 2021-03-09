#include<stdio.h>

// Muhammad Ihsan Abdul Hakim
// 16020129

// membuat fungsi perpangkatan
float pangkat(float i, float l)
{
    if(l==0){
        return 1;                   // pengembalian value fungsi perpangkatan
    }
    else
        return i * pangkat(i,l-1);  // pengembalian value fungsi perpangkatan
}
// membuat fungsi persamaan kuadrat matematika a1*(x1)^2 + b1*(x1) + c
float fungsi(float a1,float x1,float b1,float x2,float c)
{
    return a1*pangkat(x1,2) + b1*x2 + c;  // pengembalian value fungsi persamaan kuadrat
}
int main (void){
    int i,l,n,operation,y,x;                            // deklarasi elemen 
    float a,b,bil1,bil2,a1,b1,x1,x2,c,s,dx,fa,fb,hasil;
    char finish;

    start:                                                // statement awal untuk pengulangan
    // kumpulan string dalam looping
        printf("\nOperasi Kalkulator\n");
        printf("------------------\n");
        printf("1. Penambahan\n");
        printf("2. Pengurangan\n");
        printf("3. Perkalian\n");
        printf("4. Pembagian\n");
        printf("5. Perpangkatan\n");
        printf("6. Perhitungan Integral Riemann Metode Trapesium\n");
        printf("Masukkan pilihan operasimu: "); 
        scanf("%d",&operation);                   // perintah menginput pilihan operasi kalkulator

        if(operation == 6){
            printf("\nOperasi Integral Riemann Metode Trapesium\n");
            printf("Bentuk fungsi yang berlaku : ax^2 + bx + C\n");  
            printf("elemen; batas bawah, batas atas, koef. a, koef. b, koef. c\n"); 
            printf("hasil integral berupa aproksimasi atau pendekatan limit\n");
            printf("semakin besar nilai partisi semakin dekat pula nilai integral sesungguhnya\n");
            printf("\nMasukkan batas bawah : "); // perintah menginput nilai batas bawah integral
            scanf("%f",&a);
            printf("Masukkan batas atas : ");  // perintah menginput nilai batas atas integral
            scanf("%f",&b);
            printf("Masukkan banyak partisi : "); // perintah menginput banyak partisi yang ingin didekati
            scanf("%d",&n);      
            printf("Masukkan a: ");              // perintah menginput koefisien suku pertama x^2
            scanf("%f",&a1);
            printf("Masukkan b: ");              // perintah menginput koefisien suku kedua x
            scanf("%f",&b1);
            printf("Masukkan c: ");             // perintah menginput konstanta
            scanf("%f",&c);
            printf("fungsi = %fX^2 + %fX + %f \n", a1,b1,c);  // output pengeluaran bentuk persamaan kuadrat
                     
            s=0;
            float partisi = n;                 // konversi antara bilangan integer ke dalam bilangan float
            float xi[n];
            dx = (b-a)/partisi;                // perhitungan delta x
            for(i=1;i<=n;i++){
                float j = i;
                xi[i] = a + j*dx;
                s += fungsi(a1,xi[i],b1,xi[i],c);   // looping sum fungsi persamaan kuadrat
            }
            fa = fungsi(a1,a,b1,a,c);          // fungsi persamaan kuadrat dengan substitusi bilangan "a"
            fb = fungsi(a1,b,b1,b,c);          // fungsi persamaan kuadrat dengan subtitusi bilangan "b"
            hasil = (0.5)*dx*(fa + 2*s + fb);
            printf("integral = %f\n",hasil);   // output program 5
        }    
        else if (operation > 0 && operation < 6){  
            printf("Masukkan nilai pertama: "); 
            scanf("%f",&bil1);                     // perintah menginput bilangan pertama
            printf("Masukkan nilai kedua: ");
            scanf("%f",&bil2);                     // perintah menginput bilangan kedua
            switch (operation){
                case 1:
                        hasil = bil1 + bil2;
                        printf("%f + %f = %f\n",bil1,bil2,hasil);   // output program 1
                        break;
                case 2:
                        hasil = bil1 - bil2;
                        printf("%f - %f = %f\n",bil1,bil2,hasil);  // output program 2
                        break;
                case 3:
                        hasil = bil1 * bil2;
                        printf("%f x %f = %f\n",bil1,bil2,hasil);  // output program 3
                        break;
                case 4:
                        hasil = bil1 / bil2;
                        printf("%f : %f = %f\n",bil1,bil2,hasil);  // output program 4
                        break;
                case 5:
                        hasil = pangkat(bil1,bil2);
                        printf("%f ^ (%f) = %f\n",bil1,bil2,hasil); // output program 5    
                        break;    
                default:
                        printf("Syntax Error\n"); // output bila masukkan salah
            }
        }
        else
            printf("Syntax Error\n");  // output bila masukkan salah
    printf("------------------\n");

    printf("Press 1 to continue or press anything to end this program!\n");  ;
    scanf("%d",&y);               // input pengulangan
    if(y == 1){
        goto start;                    // perintah lompat pada baris start
    }
return 0;    
}
