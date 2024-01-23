#include <stdio.h>

int liber = 0;
int Key[100];
int Parent[100];

void insert(int key, int parent)
{
    if (liber == 0)
    {
        Parent[0] = 0;
        Key[0] = key;
        liber++;
    }
    else
    {
        Parent[liber] = parent;
        Key[liber] = key;
        liber++;
    }
}
int search(int key)
{
    for (int i = 0; i < liber; i++)
    {
        if (Key[i] == key)
            return i;
    }
    return -1;
}
void deleteNode(int cheie)
{
    int idx = search(cheie); // cautam nodul de sters

    // nu exista nodul
    if (idx == -1)
        return;
    if (idx == 0)
    {
        Parent[idx] = -1;
        Key[idx] = -1;
    }
    Key[idx] = -1;
    for (int i = 0; i < liber; i++)
    {
        if (Parent[i] == cheie)
        {

            Parent[i] = -1;
            for (int j = 0; j < liber; j++)
            {
                if (Parent[j] == Key[i])
                {
                    deleteNode(Parent[j]);
                }
            }
            Key[i] = -1;
            deleteNode(i);
        }
    }
}
int update(int vechi, int nou)
{
    int n = search(vechi);
    Key[n] = nou;
    return n;
}
void afisare()
{
    printf("\n##############\n");
    printf("Index: ");
    for (int i = 0; i < liber; i++)
    {
        printf("%d ", i);
    }

    if (liber > 0)
    {
        printf("\nParents: ");
        for (int i = 0; i < liber; i++)
        {
            printf("%d ", Parent[i]);
        }

        printf("\nKeys: ");
        for (int i = 0; i < liber; i++)
        {
            printf("%d ", Key[i]);
        }
    }
    else
    {
        printf("\n[Empty]");
    }

    printf("\n##############\n");
}

int main()
{
    int opt, key, parent, oldKey, newKey;

    insert(2, 0);
    insert(3, 2);
    insert(4, 2);
    insert(5, 3);
    insert(6, 4);

    while (1)
    {
        printf("1.Afisare\n");
        printf("2.Inserare\n");
        printf("3.Stergere\n");
        printf("4.Update\n");
        printf("5.Iesire\n");
        printf("Alegeti o optiune\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            afisare();
            break;

        case 2:
            printf("Introduceti cheia si parintele (cheie parinte): ");
            scanf("%d %d", &key, &parent);
            insert(key, parent);
            break;

        case 3:
            printf("Introduceti cheia pentru stergere: ");
            scanf("%d", &key);
            deleteNode(key);
            break;

        case 4:
            printf("Introduceti vechea si noua cheie (veche noua): ");
            scanf("%d %d", &oldKey, &newKey);
            update(oldKey, newKey);
            break;

        case 5:
            return 0;

        default:
            printf("Optiune invalida. Incercati din nou.\n");
        }
    }

    return 0;
}