#include <stdlib.h>
#include <stdio.h>

int primfiu[15] = {0};
int frate_dr[15] = {0};
int chei[15] = {0};

int nods = 0;

void insertie(int cheie, int parinte)
{
    if (nods == 15)
    {
        printf("Memorie ocupata\n");
        return;
    }
    chei[nods] = cheie;
    if (parinte != 0)
    {
        if (primfiu[parinte - 1] == 0)
            primfiu[parinte - 1] = nods + 1;
        else
        {
            int aux = primfiu[parinte - 1];
            while (frate_dr[aux - 1] != 0)
            {
                aux = frate_dr[aux - 1];
            }
            frate_dr[aux - 1] = nods + 1;
        }
    }
    nods++;
}

int cautare(int nod)
{
    for (int i = 0; i < nods; i++)
        if (nod == chei[i])
            return i;
    return -1;
}

int update(int cheie, int cheie_noua)
{
    for (int i = 0; i < nods; i++)
    {
        if (chei[i] == cheie)
        {
            chei[i] = cheie_noua;
            return 1;
        }
    }
    return 0;
}

int parinte(int nod)
{
    for (int i = 0; i < nods; i++)
        if (primfiu[i] == nod || frate_dr[i] == nod)
            return i;
    return -1;
}

int primul_fiu(int nod)
{
    return primfiu[nod];
}
int frate_dreapta(int nod)
{
    return frate_dr[nod];
}

void afisare()
{
    printf("Index:      ");
    for (int i = 0; i < nods; i++)
    {
        printf("%-3d ", i);
    }
    printf("\n");

    printf("Chei:       ");
    for (int i = 0; i < nods; i++)
        printf("%-3d ", chei[i]);
    printf("\n");

    printf("PrimFiu:    ");
    for (int i = 0; i < nods; i++)
        printf("%-3d ", primfiu[i]);
    printf("\n");

    printf("FrateDr:    ");
    for (int i = 0; i < nods; i++)
        printf("%-3d ", frate_dr[i]);
    printf("\n");
}

void suprimare(int nod)
{
    if (nod < 0 || nod >= nods || chei[nod] == -1)
    {
        printf("Nodul nu exista sau este deja eliminat\n");
        return;
    }

    int primFiu = primfiu[nod];
    while (primFiu != 0)
    {
        suprimare(primFiu - 1);
        int frateDr = frate_dr[primFiu - 1];
        frate_dr[primFiu - 1] = -1;
        primfiu[nod] = frateDr;
        primFiu = frateDr;
    }

    chei[nod] = -1;
    primfiu[nod] = -1;
}

int main()
{
    int cheie, noua_cheie, nod;
    insertie(1, 0);
    insertie(2, 1);
    insertie(3, 1);
    insertie(4, 1);
    insertie(5, 2);
    insertie(6, 3);
    insertie(7, 3);
    insertie(8, 6);
    insertie(9, 6);
    insertie(10, 5);
    insertie(11, 5);
    insertie(12, 7);

    int optiune = 0;
    afisare();
    while (1)
    {
        printf("\n0.Iesire\n");
        printf("1.Cautare nod\n");
        printf("2.Schimbare cheie\n");
        printf("3.Surpimare\n");
        printf("4.Afisare parinte\n");
        printf("5.Afisare prim fiu\n");
        printf("6.Afisare frate dreapta\n");
        printf("7.Afisare arbore\n");
        printf("Optiune: ");
        scanf("%d", &optiune);
        switch (optiune)
        {
        case 0:
            exit(0);
        case 1:
            printf("Introduceti cheia pentru nodul dorit: ");
            scanf("%d", &cheie);
            printf("Nod %d", cautare(cheie));
            break;
        case 2:
            printf("Introduceti cheia pe care doriti sa so schimbati:");
            scanf("%d", &cheie);
            printf("Cheie noua: ");
            scanf("%d", &noua_cheie);
            if (update(cheie, noua_cheie))
                printf("Updatat\n");
            else
                printf("Chia n-a fost gasita\n");
            break;
        case 3:
            printf("Introduceti indexul nodului:");
            scanf("%d", &nod);
            suprimare(nod);
            break;
        case 4:
            printf("Introduceti indexul nodului: ");
            scanf("%d", &nod);
            printf("Index parinte: ", parinte(nod));
            break;
        case 5:
            printf("Introduceti indexul nodului: ");
            scanf("%d", &nod);
            printf("Index prim fiu: ", primul_fiu(nod));
            break;
        case 6:
            printf("Introduceti indexul nodului: ");
            scanf("%d", &nod);
            printf("Index frate dreapta: ", frate_dreapta(nod));
            break;
        case 7:
            printf("\n");
            afisare();
            break;
        default:
            break;
        }
    }
    return 0;
}