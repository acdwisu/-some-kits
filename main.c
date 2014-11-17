#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#define caption "\t\t\t\t\\ 'S o m e'   T o o l s /\n\t\t\t\t =======================\n\n\n\n"      //header

void opening();
void en_in();
void in_en();
void calc();
void tabelCalc();
void tambahEn_In();
void tambahIn_En();
void about();
void ulang(int menu);
void loading();
long int countWordEn();
long int countWordIn();
void keluar();

int i;
char en[280];
char in[280];
char input[50];
int menu = 1432;                     // variabel menu diisi nilai 1432

void main()
{
    int subMenu1;
    if (menu == 1432)                // menampilkan opening hanya jika menu = 1432
    {
        opening();
        system("cls");
    }
    puts(caption);
    system("color f0");
    printf("1. Terjemahkan Inggris -> Indonesia\n");
    printf("2. Terjemahkan Indonesia -> Inggris\n");
    printf("3. Kalkulator\n");
    printf("4. Tambahkan Kata\n");
    printf("5. Tentang\n");
    printf("6. Keluar\n");
    printf("=> "); scanf("%d", &menu);      // melakukan input nilai ke menu, sehingga apabila prosedur main() dipanggil kembali, opening tidak akan ditampilkan
    switch(menu)
    {
    case 1 :
        en_in();
        break;
    case 2 :
        in_en();
        break;
    case 3 :
        calc();
        break;
    case 4 :
        {
            system("cls");
            puts(caption);
            subMenu1:
            printf("1. Tambah kata Inggris -> Indonesia\n");
            printf("2. Tambah kata Indonesia -> Inggris\n");
            printf("-> "); scanf("%d", &subMenu1);
            switch (subMenu1)
            {
            case 1 :
                tambahEn_In();
                break;
            case 2 :
                tambahIn_En();
                break;
            default :
                goto subMenu1;
                break;
            }
        }
    case 5 :
        about();
        break;
    case 6 :
        system("cls");
        keluar();
        break;
    default :
        system("cls");
        main(menu);
        break;
    }
}

void opening()                              // prosedur opening
{
    int j = 1;
    system("color f0");
    char op[]   = "\n\n\n\n\n\t\t\tL o a d i n g";
    char ttk[]  = " . . . . .";
    char clear[]= "          ";
    char cap[]  = "\' S O M E \'   T O O L S";
    for (i=0; op[i] != 0; i++)              // menampilkan kata "Loading" per karakter
    {
        printf("%c", op[i]);
    }
    while (j <= 3)
    {
        for (i=0; ttk[i] != 0; i++)         // menampilkan array/string ttk per karakter, dalam jeda waktu 130 miliseconds
        {
            Sleep(130);
            printf("%c", ttk[i]);
        }
        Sleep(220);
        for (i=10; i>0; i--)                // melakukan backspace kursor dan menggantikan karakter dalam string ttk
        {                                   // per karakter dengan string clear
            printf("\b");
            printf("%c", clear[i]);
            printf("\b");
        }
        j++;
    }
    for (i=13; i>0; i--)
    {
        Sleep(20);
        printf("\b");
    }
    for (i=0; cap[i] != 0; i++)
    {
        Sleep(50);
        printf("%c", cap[i]);
    }
    printf("\n");
    printf("\n\t\t\tby\n\t\t\tAchmad Dwi Suriyanto\n\n");
    Sleep(3000);
}

void en_in()                                    // prosedur terjemah inggris ke indonesia
{
    system("cls");
    i = 0;
    puts(caption);
    char title [] = "Terjemahkan Inggris -> Indonesia";
    FILE *finEn, *finIn;
    finEn = fopen("en-in.txt", "r");            // (en-in.txt) data kata bahasa inggris, dalam mode read
    finIn = fopen("en-in0.txt", "r");           // (en-in0.txt) definisi dari kata bahasa inggris dalam bahasa indonesia, dalam mode read
    puts(title);
    printf("\n\n\n\n\n");
    printf("Inggris   : "); scanf("%s", &input);   // memasukkan kata dalam bahasa inggris

    fgets(in, sizeof (in), finIn);              // membaca data dari en-in0.txt dan dipindahkan ke variabel in
    while (fscanf(finEn, "%s", &en) == 1 && strcmpi(input, en) != 0)  // melakukan pengulangan selama dilakukan pembacaan dari en-in.txt ke variabel en
    {                                                                 // dan selama penyamaan string input dan en masih false (case insensitive)
        fgets(in, sizeof (in), finIn);
    }
    if (strcmpi(input, en) == 0)                // apabila proses perulangan sudah selesai, yakni penyamaan string input dan en sudah true
    {                                           // akan ditampilkan definisi dari kata yang diinput tadi
        i = 1;
        loading();
        printf("Indonesia : "); puts(in);
        ulang(menu);
    }
    else if (i == 0)                            // sedangkan apabila perulangan sudah selesai namun penyamaan string input dan en masih false
    {                                           // maka akan diberitahu bahwa kata yang diinput tadi tidak ditemukan (tidak terdapat dalam data en-in.txt), begitupula definisinya
        loading();
        printf("Kata tidak ditemukan.\n");
        ulang(menu);
    }
    fclose(finEn);
    fclose(finIn);
}

void in_en()                                   // prosedur terjemah indonesia ke inggris
{
    system("cls");
    i = 0;
    puts(caption);
    char title [] = "Terjemahkan Indonesia -> Inggris";
    FILE *finEn, *finIn;
    finIn = fopen("in-en.txt", "r");
    finEn = fopen("in-en0.txt", "r");
    puts(title);
    printf("\n\n\n\n\n");
    printf("Indonesia : "); scanf("%s", &input);

    fgets(en, sizeof (en), finEn);
    while (fscanf(finIn, "%s", &in) == 1 && strcmpi(input, in) != 0)
    {
        fgets(en, sizeof (en), finEn);
    }
    if (strcmpi(input, in) == 0)
    {
        i = 1;
        loading();
        printf("Inggris   : "); puts(en);
        ulang(menu);
    }
    else if (i == 0)
    {
        loading();
        printf("Kata tidak ditemukan.\n");
        ulang(menu);
    }
    fclose(finEn);
    fclose(finIn);
}

void calc()                         // prosedur kalkulator
{
    system("cls");
    float bil1;
    float bil2;
    float hasil;
    const float derajat = 3.14/180;
    char opr[10];
    puts(caption);
    printf("Kalkulator\n\n");
    printf("contoh :\"-> 3 x 5\"\n");
    printf("        \"-> 1 sin 60\"\n");
    printf("        \"-> 25 # 2\"(25 akar 2)\n\n");
    tabelCalc();
    printf("-> ");               // diminta agar melakukan input secara berurutan (ex : "2 x 5")
    scanf("%f", &bil1);          // menyimpan operand di variable bil1
    scanf("%s", &opr);           // menyimpan operator aritmatik di variabel opr
    scanf("%f", &bil2);          // menyimpan operand di variabel bil2
    if (strcmp(opr, "+") == 0)
    {
        hasil = bil1 + bil2;
    }
    else if (strcmp(opr, "-") == 0)
    {
        hasil = bil1 - bil2;
    }
    else if (strcmpi(opr, "x") == 0)    // apabila penyamaan string (case insensitive) opr dan "x" bernilai true
    {                                   // akan melakukan perhitungan
        hasil = bil1 * bil2;
    }
    else if (strcmp(opr, ":") == 0)
    {
        hasil = bil1 / bil2;
    }
    else if (strcmp(opr, "^") == 0)
    {
        hasil = pow(bil1, bil2);
    }
    else if (strcmp(opr, "#") == 0)
    {
        hasil = pow(bil1, 1.0/bil2);
    }
    else if (strcmpi(opr, "sin") == 0)          // apabila penyamaan string (case insensitive) opr dan "sin" bernilai true
    {                                           // melakukan perhitungan dengan memanggil fungsi sin()
        hasil = bil1 * sin(bil2*derajat);
    }
    else if (strcmpi(opr, "cos") == 0)
    {
        hasil = bil1 * cos(bil2*derajat);
    }
    else if (strcmpi(opr, "tan") == 0)
    {
        hasil = bil1 * tan(bil2*derajat);
    }
    else if (strcmpi(opr, "asin") == 0)
    {
        hasil = bil1 * asin(bil2)*180/3.14;
    }
    else if (strcmpi(opr, "acos") == 0)
    {
        hasil = bil1 * acos(bil2)*180/3.14;
    }
    else if (strcmpi(opr, "atan") == 0)
    {
        hasil = bil1 * atan(bil2)*180/3.14;
    }
    else
    {
        loading();
        printf("operator salah\n\n");
        system("cls");
        calc();
    }
    loading();
    printf("-> %.3f\n", hasil);
    ulang(menu);
}

void tabelCalc()                // tabel operator-operator yang dapat digunakan dalam prosedur calc()
{
    printf("_____________________________\n");
    printf("|  +  |   -  |   ^  |#(akar)|\n");
    printf("|  x  | asin | acos | atan  |\n");
    printf("|  :  |  sin |  cos |  tan  |\n");
    printf("=============================\n");
}

void ulang(int menu)                // prosedur untuk melakukan pengulangan
{
    int pil;
    Sleep(400);
    if (menu >= 1 && menu <= 5)
    {
        printf("\n\n1. Menu\n");
        printf("2. Ulangi\n");
        printf("3. keluar\n");
        printf("--> "); scanf("%d", &pil);
        switch(pil)
        {
            case 1 :
            {
                system("cls");
                main(menu);
                break;
            }
            case 2:
            {
                system("cls");
                if (menu == 1)          // apabila sebelumnya telah diinputkan nilai 1 ke variabel menu
                {                       // maka akan dilakukan pemanggilan prosedur en_in()
                    en_in();
                }
                else if (menu == 2)
                {
                    in_en();
                }
                else if (menu == 3)
                {
                    calc();
                }
                else if (menu == 4)
                {
                    main(menu);
                }
                else if (menu == 5)
                {
                    main(menu);
                }
                break;
            }
            case 3:
            {
                system("cls");
                keluar();
                break;
            }
            default :
            {
                system("cls");
                ulang(menu);
                break;
            }
        }
    }
}

void tambahEn_In()                // prosedur menambahkan kata inggris dan definisi bahasa indonesia
{
    FILE *faddEn, *faddIn;
    system("cls");
    faddEn = fopen("en-in.txt", "a");       // membuka data kata bahasa inggris, dalam mode rewrite
    faddIn = fopen ("en-in0.txt", "a");     // membuka data definisi bahasa indonesia, dalam mode rewrite
    puts(caption);
    printf("\n\n\nTambah kata Inggris -> Indonesia\n\n");
    printf("Inggris   : "); scanf("%s", &en);   // menginput kata dalam bahasa inggris dan disimpan ke variabel en
    fprintf(faddEn, "\n%s", en);                // membuat newline, lalu mencetak kata yang tersimpan dalam variabel en ke en-in.txt
    fflush(stdin);                              // membersihkan aliran input
    printf("Indonesia : "); gets(in);           // menginput definisi dalam bahasa indonesia dan disimpan ke array in
    fprintf(faddIn, "\n");                      // membuat new line
    fputs(in, faddIn);                          // mencetak definisi yang tersimpan dalam array in ke en-in0.txt
    fflush(stdin);
    fclose(faddEn);
    fclose(faddIn);
    loading();
    printf("selesai.\n");
    ulang(menu);
}

void tambahIn_En()              // prosedur menambahkan kata indonesia dan definisi bahasa inggris
{
    FILE *faddEn, *faddIn;
    system("cls");
    faddIn = fopen("in-en.txt", "a");
    faddEn = fopen ("in-en0.txt", "a");
    puts(caption);
    printf("\n\n\nTambah kata Indonesia -> Inggris\n\n");
    printf("Indonesia : "); scanf("%s", &in);
    fprintf(faddIn, "\n%s", in);
    fflush(stdin);
    printf("Inggris   : "); gets(en);
    fprintf(faddEn, "\n");
    fputs(en, faddEn);
    fflush(stdin);
    fclose(faddEn);
    fclose(faddIn);
    loading();
    printf("selesai.\n");
    ulang(menu);
}

long int countWordEn()           // fungsi menghitung jumlah kata dalam en-in.txt
{
    i = 0;
    FILE *fce;
    fce = fopen("en-in.txt", "r");
    while (! feof(fce))
    {
        fscanf(fce, "%s", &en);
        i++;
        fflush(stdin);
    }
    return i;                   // mengembalikkan nilai i
}

long int countWordIn()          // fungsi menghitung jumlah kata dalam in-en.txt
{
    i = 0;
    FILE *fci;
    fci = fopen("in-en.txt", "r");
    while (! feof(fci))
    {
        fscanf(fci, "%s", &in);
        i++;
        fflush(stdin);
    }
    return i;                   // mengembalikkan nilai i
}

void loading()                  // prosedur efek loading
{
    int h = 1;
    char ttk[]  = " . . . . .";
    char clear[]= "          ";
    puts("");
    while (h <= 2)
    {
        for (i=0; ttk[i] != 0; i++)
        {
            Sleep(80);
            printf("%c", ttk[i]);
        }
        Sleep(120);
        for (i=10; i>0; i--)
        {
            printf("\b");
            printf("%c", clear[i]);
            printf("\b");
        }
        h++;
    }
}

void keluar()               // prosedur untuk keluar
{
    loading();
    exit(1);
}

void about()                // prosedur tentang
{
    system("cls");
    puts(caption);
    printf("\n\n\n");
    printf("\'Some\' Tools coded by Achmad Dwi Suriyanto\n\n");
    printf("Inggris -> Indonesia : %ld kata\n", countWordEn());     // memanggil fungsi countWordEn()
    printf("Indonesia -> Inggris : %ld kata\n", countWordIn());     // memanggil fungsi countWordIn()
    printf("pustaka kamus : gKamus File Format v1.0 by Firmansyah, Ardhan Madras\n");
    ulang(menu);
}
