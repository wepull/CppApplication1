#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int modifData(char mode,
              int *money,
              int *lvl,
              int *exp,
              int *inventory,
              int inventory_S);

int main()
{
    bool isInputValid = true;
    
    char *input   = new  char[16];
    char *command = new  char[8];
    
    int inventory_S = 8;
    int *inventory  = new  int[inventory_S];
    
    int lvl      = 1;
    int money    = 10;
    int exp      = 0;
    
    printf("%d\n", inventory_S);
    
    inventory[0] = 0;
    for (int i = 1; i < inventory_S; i++) inventory[i] = -1;
        
    printf("Economy game; Type 'help <command>' to help."
           "To EXIT type 'exit'.\n");
    
    while (true)
    {
        printf("$: ");
        scanf("%s", input);
        
        if (input[0] == '\n')
        {
            printf("Error: Empty input\n");
            continue;
        }
        
        for (int i = 1; i < 16; i++)
        {
            
            if (input[i - 1] == ' ' && input[i] == ' ')
            {
                printf("Error: Double space\n");
                isInputValid = false;
                break;
            }
        }
        
        if (!isInputValid) continue;
            
        sscanf(input, "%s", command);
        
        if (strcmp(command, "exit") == 0)
        {
            printf("Do you want to EXIT? (Remember to save first)\nyes|no: ");
            scanf("%s", input);
            sscanf(input, "%s", command);
            
            if (strcmp(command, "yes") == 0) break;
            else printf("Cancelled \n");
        }
        
        else if (strcmp(command, "help") == 0)
            printf("Commands:\n"
                   " exit                    Closes the program\n"
                   " help                    Show this list\n"
                   " stats                   Show player stadistics\n"
                   " work                    Gain money\n"
                   " save                    Save player data\n"
                   " load                    Loads player data\n"
                   " reset                   Resets all progress, USE THIS WITH CAUTION\n"
                   " items                   Show item names and theirs ID's and skins\n"
                   " buy   <item> <amount>   Buy a itme from shop\n"
                   " sell  <item> <amount>   Sell a item\n"
                   " make  <itmem1> <item2>  Make an item \n");
        
        else if (strcmp(command, "stats") == 0)
        {
            printf("Stadistics:\n"
                   " Level: %d\n"
                   " Money: %d\n"
                   " Experience: %d\n",
                   lvl, money, exp);
            printf("Inventory: \n");
            
            for (int i = 0; i < inventory_S; i++)
            {
                
                if (inventory[i] == -1) continue;
                else printf("|%d (#%d)| ", inventory[i], i);
            }
            printf("\n");
        }
        
        else if (strcmp(command, "work") == 0)
        {
            int * gain = new int[2];
            
            gain[0] = 1 * lvl    + (lvl * lvl);
            gain[1] = 1 + rand() % (6 + lvl);
            
            printf("You gained: $%d + %d xp\n", gain[0], gain[1]);
            
            money += gain[0];
            exp   += gain[1];
            
            if (exp == 7 * (lvl + lvl)) printf("Level up %d", ++lvl);
            delete[] gain;
        }
        
        else if (strcmp(command, "save") == 0) modifData('s', &money, &lvl, &exp, inventory, inventory_S);
        
        else if (strcmp(command, "load") == 0) modifData('l', &money, &lvl, &exp, inventory, inventory_S);
        
        else if (strcmp(command, "reset") == 0)
        {
            if (modifData('r', &money, &lvl, &exp, inventory, inventory_S) == 1) break;
        }

        else if (strcmp(command, "shop") == 0)
            printf(" ID |Name    |Price |ID |Name    |Price\n"
                   " 1  |Stick   |$4    |2  |Rock    |$6\n"
                   " 3  |Wood    |$12   |4  |Stone   |$18\n"
                   " 5  |Planks  |$26   |6  |Coal    |$35\n"
                   " 7  |Iron    |$56   |8  |Copper  |$78\n");
        
        else if (strcmp(command, "buy") == 0)
        {
            printf("Select an item to buy (type '.c' to cancell)\nitem: ");
            
            char *item    = new char[8];
            int  *item_Id = new int;
            int  *amount  = new int;
            
            scanf("%s", item);
            if (strcmp(item, "stick") == 0) item_Id = 0;
            else if (strcmp(item, "rock") == 0) *item_Id = 1;
            
            else if (strcmp(item, "wood") == 0) *item_Id = 2;

            else if (strcmp(item, "stone") == 0) *item_Id = 3;

            else if (strcmp(item, "planks") == 0) *item_Id = 4;

            else if (strcmp(item, "coal") == 0) *item_Id = 5;

            else if (strcmp(item, "iron") == 0) *item_Id = 6;

            else if (strcmp(item, "copper") == 0) *item_Id = 7;

            else if (strcmp(item, ".q") == 0) printf("Cancelled\n");
            
            else
            {
                delete[] item;
                delete   amount;
                delete   item_Id;
                printf("Error: Unkown item '%s'", item);
                continue;
            }
            
            printf("amount (Not minus that 1): ");
            scanf("%d", amount);
            
            if (*amount < 1)
            {
                printf("Amount to tiny\n");
                delete[] item;
                delete   amount;
                delete   item_Id;
                continue;
            }
            
            switch(*item_Id)
            {
              case 0:
                if (money < 4)
                {
                    printf("Not enough money\n");
                    delete[] item;
                    delete   amount;
                    continue;
                }
                
                if (money < (4 * (*amount)))
                {
                    printf("Unable to buy colect $%d more to buy it x%d\n", (4 * (*amount)) - money, (*amount));
                    delete[] item;
                    delete   amount;
                    delete   item_Id;
                    continue;
                }
                inventory[0] += *amount;
                money        -= (*amount) * 4;
                
                printf("Buied %d stick(s) -%d\n", *amount, 2 * (*amount));
                break;
              case 1:
                
                break;
              case 2:
                
                break;
              case 3:
                
                break;
              case 4:
                
                break;
              case 5:
                
                break;
              case 6:
                
                break;
              case 7:
                if ((*amount) < 1 || money < 4)
                {
                    printf("Empty money or/and amount requests\n");
                    delete[] item;
                    delete   amount;
                    continue;
                }
                
                if (money < (4 * (*amount)))
                {
                    printf("Unable to buy colect $%d more to buy it x%d\n", (4 * (*amount)) - money, (*amount));
                    delete[] item;
                    delete   amount;
                    continue;
                }
                inventory[0] += *amount;
                money        -= (*amount) * 4;
                
                printf("Buied %d stick(s) -%d\n", *amount, 2 * (*amount));
            }
            
            delete[] item;
            delete   amount;
            delete   item_Id;
        }
        
        else if (strcmp(command, "sell") == 0) printf("Commong soon\n");
        
        else if (strcmp(command, "make") == 0) printf("Comming soon\n");
        
        else printf("Error unknown command\n");
    }
    printf("[Program finished]");
    return 0;
}

int modifData(char mode,
              int *money,
              int *lvl,
              int *exp,
              int *inventory,
              int inventory_S)
{
    FILE *dataFPtr;
    if (mode == 's')
    {
        dataFPtr = fopen("player.esav", "wb");
        
        fwrite(money, sizeof(int), 1, dataFPtr);
        fwrite(lvl,   sizeof(int), 1, dataFPtr);
        fwrite(exp,   sizeof(int), 1, dataFPtr);
        
        fwrite(inventory, sizeof(int),inventory_S, dataFPtr);
        printf("Saved data\n");
    }
    else if (mode == 'l')
    {
        dataFPtr = fopen("player.esav", "rb");
        
        fread(money, sizeof(int), 1, dataFPtr);
        fread(lvl,   sizeof(int), 1, dataFPtr);
        fread(exp,   sizeof(int), 1, dataFPtr);
        
        fread(inventory, sizeof(int), inventory_S, dataFPtr);
        printf("Loaded data\n");
    }
    else
    {
        char *c_Reset = new char[4];
        
        char *c_Key   = new char[4];
        printf("Do you want to reset you data\n"
               "IT CAN BE UNDONE!\nyes|no: ");
               
        scanf("%s", c_Reset);
        sscanf(c_Reset, "%s", c_Key);
        
        if (strcmp(c_Key, "yes") != 0)
        {
            printf("Cancelled\n");
            fclose(dataFPtr);
            delete[] c_Reset;
            delete[] c_Key;
        }
        int d_Inventory[inventory_S];
        d_Inventory[0] = 0;
        
        int *num = new int;
        
        for (int i = 1; i < inventory_S; i++) d_Inventory[i] = -1;
        dataFPtr = fopen("player.esav", "wb");
        *num = 10;
        
        fwrite(num, sizeof(int), 1, dataFPtr);
        *num = 1;
        
        fwrite(num, sizeof(int), 1, dataFPtr);
        *num = 0;
        
        fwrite(num, sizeof(int), 1, dataFPtr);
        
        fwrite(d_Inventory, sizeof(int), inventory_S, dataFPtr);
        fclose(dataFPtr);
        printf("Reseted now closing...\n");
        return 1;
    }
    fclose(dataFPtr);
    return 0;
}