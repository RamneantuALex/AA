#include <stdio.h>

int C[100] = {0};
int FD[100] = {0};
int PF[100] = {0};

int nod = 0;

void insert(int cheie, int parinte)
{
    C[nod] = cheie;
    if (parinte != 0)
    {
        if (PF[parinte - 1] == 0)
        {
            PF[parinte - 1] = nod + 1;
        }
        else
        {
            int aux = PF[parinte - 1];
            while (FD[aux - 1] != 0)
            {
                aux = FD[aux - 1];
            }
            FD[aux - 1] = nod + 1;
        }
    }
    nod++;
}
int cautare(int cheie)
{
    for (int i = 0; i < nod; i++)
    {
        if (C[i] == cheie)
            return i;
    }
    return -1;
}

void update(int old, int new)
{
    for (int i = 0; i < nod; i++)
    {
        if (C[i] == new)
            return;
    }
    for (int i = 0; i < nod; i++)
    {
        if (C[i] == old)
            C[i] = new;
    }
    for (int i = 0; i < nod; i++)
    {
        if (PF[i] == old)
            PF[i] = new;
    }
    for (int i = 0; i < nod; i++)
    {
        if (FD[i] == old)
            FD[i] = new;
    }
}
int parinte(int cheie)
{
    for (int i = 0; i < nod; i++)
    {
        if (PF[i] == nod || FD[i] == nod)
            return i;
    }
    return -1;
}
int primul_fiu(int nod)
{
    return PF[nod];
}
int frate_dreapta(int nod)
{
    return FD[nod];
}

void afisare()
{
    printf("\n##############\n");
    printf("\nIndex:      ");
    for (int i = 0; i < nod; i++)
    {
        printf("%-3d ", i);
    }

    printf("\nChei:       ");
    for (int i = 0; i < nod; i++)
        printf("%-3d ", C[i]);

    printf("\nPrimFiu:    ");
    for (int i = 0; i < nod; i++)
        printf("%-3d ", PF[i]);

    printf("\nFrateDr:    ");
    for (int i = 0; i < nod; i++)
        printf("%-3d ", FD[i]);
    printf("\n");
}
void deleteNode(int cheie)
{
    if (cheie < 0 || cheie > nod || C[nod] == -1)
    {
        printf("Cheie gresita sau stearsa!\n");
    }
    int idx = cautare(cheie);
    if (idx == 0)
    {
        C[idx] = -1;
        PF[idx] = -1;
    }
}
int main()
{

    return 0;
}