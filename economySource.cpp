#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "Boulde_ES_MX.h"

void buy(const char *item, int *inventory,
         int *money,
         int *amount,
         int *item_Id,
         int lvl,
         int price)
{
    if ((*item_Id) > 1 && (*item_Id) < 4)
    {

        if (lvl < 2)
        {

            printf(lvlRequieredDlg, 2);

            return;
        }
    }

    else if ((*item_Id) > 3 && (*item_Id) < 6)
    {

        if (lvl < 4)
        {

            printf(lvlRequieredDlg, 4);

            return;
        }
    }

    else
    {

        if (lvl < 6 && (*item_Id) > 5)
        {

            printf(lvlRequieredDlg, 6);

            return;
        }
    }

    if ((*money) < price)
    {

        printf(enoughMoney);

        return;
    }

    if ((*money) < (price * (*amount)))
    {

        printf(unableBuy, (price * (*amount)) - (*money), (*amount));

        return;
    }

    if (inventory[*item_Id] == -1)
        inventory[*item_Id] = 0;

    inventory[*item_Id] += *amount;
    *money -= (*amount) * price;

    printf(buied, *amount, item, price * (*amount));

    return;
}

int modifData(char mode, int *money, int *lvl,
              int *exp, int *inventory, int inventory_S)
{

    FILE *dataFPtr;

    if (mode == 's')
    {

        dataFPtr = fopen("player.esav", "wb");

        fwrite(money, sizeof(int), 1, dataFPtr);
        fwrite(lvl, sizeof(int), 1, dataFPtr);
        fwrite(exp, sizeof(int), 1, dataFPtr);

        fwrite(inventory, sizeof(int), inventory_S, dataFPtr);
        printf(savedDataDlg);
    }

    else if (mode == 'l')
    {

        dataFPtr = fopen("player.esav", "rb");

        fread(money, sizeof(int), 1, dataFPtr);
        fread(lvl, sizeof(int), 1, dataFPtr);
        fread(exp, sizeof(int), 1, dataFPtr);

        fread(inventory, sizeof(int), inventory_S, dataFPtr);
        printf(loadedDataDlg);
    }

    else
    {

        char *c_Reset = new char[4];

        char *c_Key = new char[4];
        printf(resetConfirmDlg);

        scanf("%s", c_Reset);
        sscanf(c_Reset, "%s", c_Key);

        if (strcmp(c_Key, "yes") != 0)
        {

            printf(cancelledDlg);
            fclose(dataFPtr);
            delete[] c_Reset;
            delete[] c_Key;
        }

        int *d_Inventory = new int[inventory_S];
        d_Inventory[0] = 0;

        int *num = new int;

        for (int i = 1; i < inventory_S; i++)
            d_Inventory[i] = -1;

        dataFPtr = fopen("player.esav", "wb");
        *num = 10;

        fwrite(num, sizeof(int), 1, dataFPtr);
        *num = 1;

        fwrite(num, sizeof(int), 1, dataFPtr);
        *num = 0;

        fwrite(num, sizeof(int), 1, dataFPtr);

        fwrite(d_Inventory, sizeof(int), inventory_S, dataFPtr);
        fclose(dataFPtr);
        printf(resetingDlg);
        return 1;
    }

    fclose(dataFPtr);
    return 0;
}

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int x = (b + sqrt(pow(b, 2) + (4 * a * b))) / (2 * a);
    bool isInputValid = true;

    char *input = new char[16];
    char *command = new char[8];

    int inventory_S = 8;
    int *inventory = new int[inventory_S];

    int lvl = 1;
    int money = 10;
    int exp = 0;

    inventory[0] = 0;
    for (int i = 1; i < inventory_S; i++)
        inventory[i] = -1;

    printf(initDlg);

    while (true)
    {

        printf("$: ");
        scanf("%s", input);

        if (input[0] == '\n')
        {

            printf(emptyCmdDlg);
            continue;
        }

        for (int i = 1; i < 16; i++)
        {

            if (input[i - 1] == ' ' && input[i] == ' ')
            {

                printf(doubleSDlg);
                isInputValid = false;
                break;
            }
        }

        if (!isInputValid)
            continue;

        sscanf(input, "%s", command);

        if (strcmp(command, "exit") == 0)
        {

            printf(confirmExitDlg);
            scanf("%s", input);
            sscanf(input, "%s", command);

            if (strcmp(command, "yes") == 0)
                break;

            else
                printf(cancelledDlg);
        }

        else if (strcmp(command, "help") == 0)
            printf(helpDlg);

        else if (strcmp(command, "stats") == 0)
        {

            printf(statsDlg, lvl, money, exp);
            printf(statsInveDlg);

            for (int i = 0; i < inventory_S; i++)
            {

                if (inventory[i] == -1)
                    continue;
                else
                    printf("|x%d (#%d)", inventory[i], i);
            }

            printf("|\n");
        }
        
        else if (strcmp(command, "work") == 0)
        {

            int *gain = new int[2];

            gain[0] = 1 * lvl + (lvl * lvl);
            gain[1] = 1 + rand() % (6 + lvl);

            printf(workGainDlg, gain[0], gain[1]);

            money += gain[0];
            exp += gain[1];

            if (exp == 7 * (lvl + lvl))
                printf(levelUpDlg, ++lvl);
            delete[] gain;
        }

        else if (strcmp(command, "save") == 0)
            modifData('s', &money, &lvl, &exp, inventory, inventory_S);

        else if (strcmp(command, "load") == 0)
            modifData('l', &money, &lvl, &exp, inventory, inventory_S);

        else if (strcmp(command, "reset") == 0)
        {

            if (modifData('r', &money, &lvl, &exp, inventory, inventory_S) == 1)
                break;
        }

        else if (strcmp(command, "shop") == 0)
            printf(shopDlg);

        else if (strcmp(command, "buy") == 0)
        {

            printf(buyDlg);

            char *item = new char[8];
            int *item_Id = new int;
            int *amount = new int;

            scanf("%s", item);
            if (strcmp(item, stick) == 0)
                *item_Id = 0;

            else if (strcmp(item, rock) == 0)
                *item_Id = 1;

            else if (strcmp(item, wood) == 0)
                *item_Id = 2;

            else if (strcmp(item, stone) == 0)
                *item_Id = 3;

            else if (strcmp(item, planks) == 0)
                *item_Id = 4;

            else if (strcmp(item, coal) == 0)
                *item_Id = 5;

            else if (strcmp(item, iron) == 0)
                *item_Id = 6;

            else if (strcmp(item, copper) == 0)
                *item_Id = 7;

            else if (strcmp(item, ".q") == 0)
                printf(cancelledDlg);

            else
            {

                delete[] item;
                delete amount;
                delete item_Id;
                printf(unknownItemDlg, item);
                continue;
            }

            printf(amountDlg);
            scanf("%d", amount);

            if (*amount < 1)
            {

                printf(tinyAmountDlg);
                delete[] item;
                delete amount;
                delete item_Id;
                continue;
            }

            switch (*item_Id)
            {

            case 0:
                buy(item, inventory, &money, amount, item_Id, lvl, 4);
                break;

            case 1:
                buy(item, inventory, &money, amount, item_Id, lvl, 6);
                break;

            case 2:
                buy(item, inventory, &money, amount, item_Id, lvl, 12);
                break;

            case 3:
                buy(item, inventory, &money, amount, item_Id, lvl, 18);
                break;

            case 4:
                buy(item, inventory, &money, amount, item_Id, lvl, 26);
                break;

            case 5:
                buy(item, inventory, &money, amount, item_Id, lvl, 35);
                break;

            case 6:
                buy(item, inventory, &money, amount, item_Id, lvl, 56);
                break;

            case 7:
                buy(item, inventory, &money, amount, item_Id, lvl, 78);
                break;
            }

            delete[] item;
            delete amount;
            delete item_Id;
        }

        else if (strcmp(command, "sell") == 0)
            printf(commingSoonDlg);

        else if (strcmp(command, "make") == 0)
            printf(commingSoonDlg);

        else
            printf(unknownCmdDlg);
    }

    printf(programFinishDlg);
    return 0;
}