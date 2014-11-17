#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#define caption "\t\t\t\t\\ 'S o m e'   T o o l s /\n\t\t\t\t =======================\n\n\n\n" //judul

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
void keluar();

int i;
char en[280];
char in[280];
char input[50];
int menu = 111;

void main()
{
    int subMenu1;
    if (menu == 111)
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
    printf("=> "); scanf("%d", &menu);
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

void opening()
{
    system("color f0");
    char op[]   = "\n\n\n\n\n\t\t\tL o a d i n g . . . . .";
    char cap[]  = "\' S O M E \'   T O O L S";
    for (i=0; op[i] != 0; i++)
    {
        Sleep(150);
        printf("%c", op[i]);
    }
    for (i=23; i>0; i--)
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

void en_in()
{
    system("cls");
    i = 0;
    puts(caption);
    char title [] = "Terjemahkan Inggris -> Indonesia";
    FILE *finEn, *finIn;
    finEn = fopen("en-in.txt", "r");
    finIn = fopen("en-in0.txt", "r");
    puts(title);
    printf("\n\n\n\n\n\n\n");
    printf("Inggris   : "); scanf("%s", &input);

    fgets(in, sizeof (in), finIn);
    while (fscanf(finEn, "%s", &en) == 1 && strcmpi(input, en) != 0)
    {
        fgets(in, sizeof (in), finIn);
    }
    if (strcmpi(input, en) == 0)
    {
        i = 1;
        loading();
        printf("Indonesia : "); puts(in);
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

void in_en()
{
    system("cls");
    i = 0;
    puts(caption);
    char title [] = "Terjemahkan Indonesia -> Inggris";
    FILE *finEn, *finIn;
    finIn = fopen("in-en.txt", "r");
    finEn = fopen("in-en0.txt", "r");
    puts(title);
    printf("\n\n\n\n\n\n\n");
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

void calc()
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
    printf("-> ");
    scanf("%f", &bil1);
    scanf("%s", &opr);
    scanf("%f", &bil2);
    if (strcmp(opr, "+") == 0)
    {
        hasil = bil1 + bil2;
    }
    else if (strcmp(opr, "-") == 0)
    {
        hasil = bil1 - bil2;
    }
    else if (strcmp(opr, "x") == 0)
    {
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
    else if (strcmp(opr, "sin") == 0)
    {
        hasil = bil1 * sin(bil2*derajat);
    }
    else if (strcmp(opr, "cos") == 0)
    {
        hasil = bil1 * cos(bil2*derajat);
    }
    else if (strcmp(opr, "tan") == 0)
    {
        hasil = bil1 * tan(bil2*derajat);
    }
    else if (strcmp(opr, "asin") == 0)
    {
        hasil = bil1 * asin(bil2)*180/3.14;
    }
    else if (strcmp(opr, "acos") == 0)
    {
        hasil = bil1 * acos(bil2)*180/3.14;
    }
    else if (strcmp(opr, "atan") == 0)
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

void tabelCalc()
{
    printf("_____________________________\n");
    printf("|  +  |   -  |   ^  |#(akar)|\n");
    printf("|  x  | asin | acos | atan  |\n");
    printf("|  :  |  sin |  cos |  tan  |\n");
    printf("=============================\n");
}

void ulang(int menu)
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
                if (menu == 1)
                {
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

void tambahEn_In()
{
    FILE *faddEn, *faddIn;
    system("cls");
    faddEn = fopen("en-in.txt", "a");
    faddIn = fopen ("en-in0.txt", "a");
    puts(caption);
    printf("\n\n\nTambah kata Inggris -> Indonesia\n\n");
    printf("Inggris   : "); scanf("%s", &en);
    fprintf(faddEn, "\n%s", en);
    fflush(stdin);
    printf("Indonesia : "); gets(in);
    fprintf(faddIn, "\n");
    fputs(in, faddIn);
    fflush(stdin);
    fclose(faddEn);
    fclose(faddIn);
    loading();
    printf("selesai.\n");
    ulang(menu);
}

void tambahIn_En()
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

void loading()
{
    char loading[]="\n . . . . ";
    for(i=0;loading[i] != 0; i++)
    {
        Sleep(100);
        printf("%c",loading[i]);
    }
    for(i=18;i>0; i--)
    {
        Sleep(20);
        printf("\b");
    }
}

void keluar()
{
    loading();
    exit(1);
}

void about()
{
    system("cls");
    puts(caption);
    printf("\n\n\n");
    printf("\'Some\' Tools coded by Achmad Dwi Suriyanto\n\n");
    printf("pustaka kamus : gKamus File Format v1.0 by Firmansyah, Ardhan Madras\n\n\n");
    ulang(menu);
}
