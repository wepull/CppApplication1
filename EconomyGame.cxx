#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <ctime>

const char moneyTag[6] = "Money";
const char levelTag[6] = "Level";
const char workedTag[12] = "TimesWorked";
const char realTimesWorkedTag[16] = "RealTimesWorked";

short int inventory[6] = { 0, -1, -1, -1, -1, -1
};

class User {

    private:

        unsigned long int money = 0;

    unsigned int level = 1;
    unsigned int timesWorked = 0;
    unsigned int realTimesWorked = 0;

    public:

        unsigned int show(const char value[]) {

            if (strcmp(value, "Level") == 0) {

                return level;

            } else if (strcmp(value, "TimesWorked") == 0) {

                return timesWorked;

            } else if (strcmp(value, "RealTimesWorked") == 0) {

                return realTimesWorked;

            } else

                return 0;

        }

    unsigned long int showLong(const char value[]) {

        if (strcmp(value, "Money") == 0) {

            return money;

        } else {

            return 0;

        }

    }

    void setInt(const char name[], unsigned long int value) {

        if (strcmp(name, "Level") == 0) {

            level = value;
            return;

        } else if (strcmp(name, "TimesWorked") == 0) {

            timesWorked = value;
            return;

        } else if (strcmp(name, "RealTimesWorked") == 0) {

            realTimesWorked = value;
            return;

        } else {

            printf("No \n");
            return;

        }

    }

    void setIntLong(const char name[], unsigned long int value) {

        if (strcmp(name, "Money") == 0) {

            money = value;
            return;

        } else {

            printf("No \n");
            return;

        }

    }

    void showStats() {

        printf("Player stats: \n");

        printf("Money: %lu ", money);
        printf("Level: %u\n", level);
        printf("TimesWorked: %u", timesWorked);

        printf("Inventory:");

        for (unsigned short int i = 0; i < 6; i++) {

            if (inventory[i] < 0) {

                continue;

            }

            switch (i) {

            case 0:

                printf("stick: ");
                break;

            case 1:

                printf("stone: ");
                break;

            case 2:

                printf("wood: ");
                break;

            case 3:

                printf("iron: ");
                break;

            case 4:

                printf("gold: ");
                break;

            case 5:

                printf("diamond: ");
                break;

            }

            printf("%u ", inventory[i]);
        }

        printf("\n\n");

    }

    void levelUp() {

        if (timesWorked > (unsigned int) 10 + (2 * (level * 2)) / 2) {

            printf("Level Up to %u !!!\n", level + 1);
            printf("Gained exta bonus of $%lu \n\n", (unsigned long int) level * 100 + level * 10);

            level++;
            money += (unsigned long int) level * 10 + level;

            timesWorked = 0;

        }

        timesWorked++;
        realTimesWorked++;

    }

    unsigned short int work() {

        if (money >= 2147000) {

            printf("GAME OVER\nTHE return 0; HAS REACHED\n\nTHANKS FOR PLAYING :)\n\n");

            printf("Money: %lu \n", money);
            printf("Level: %u \n", level);

            printf("Times worked: %u \n", realTimesWorked);
            return 0;

        }

        unsigned long int gain = 0;

        srand((int) level * 2 + timesWorked - time(NULL));

        gain = (unsigned long int)(level * 5) + (rand() % (10 * level));

        if (gain == 0) {

            gain = rand() % 10;

        }

        printf("You earned: $%lu \n", gain);

        money += gain;

        levelUp();

        return 1;

    }

    void buy(const char name[], unsigned short int value) {

        if (strcmp(name, "stick") == 0) {

            if (inventory[0] == -1 && level < 1) {

                printf("Error: Unable to buy, Level 1 reatched reqired\n");
                return;

            }

            if (money < 7 * value) {

                printf("Error: No enough money\n");
                return;

            }

            if (inventory[0] == -1) {

                (inventory[0]) ++;

            }

            inventory[0] += value;
            money -= 7 * value;

            printf("Buied %u stick(s)\n", value);

        } else if (strcmp(name, "stone") == 0) {

            if (inventory[1] == -1 && level < 2) {

                printf("Error: Unable to buy, Level 2 reatched reqired\n");
                return;

            }

            if (money < 14 * value) {

                printf("Error: No enough money\n");
                return;

            }

            if (inventory[1] == -1) {

                (inventory[1]) ++;

            }

            inventory[1] += value;
            money -= 14 * value;

            printf("Buied %u stone(s)\n", value);

        } else if (strcmp(name, "wood") == 0) {

            if (inventory[2] == -1 && level < 4) {

                printf("Error: Unable to buy, Level 4 reatched reqired\n");
                return;

            }

            if (money < 28 * value) {

                printf("Error: No enough money\n");
                return;

            }

            if (inventory[2] == -1) {

                (inventory[2]) ++;

            }

            inventory[2] += value;
            money -= 28 * value;

            printf("Buied %u wood(s)\n", value);

        } else if (strcmp(name, "iron") == 0) {

            if (inventory[3] == -1 && level < 6) {

                printf("Error: Unable to buy, Level 6 reatched reqired\n");
                return;

            }

            if (money < 56 * value) {

                printf("Error: No enough money\n");
                return;

            }

            if (inventory[3] == -1) {

                (inventory[3]) ++;
            }

            inventory[3] += value;
            money -= 56 * value;

            printf("Buied %u iron(s)\n", value);

        } else if (strcmp(name, "gold") == 0) {

            if (inventory[4] == -1 && level < 8) {

                printf("Error: Unable to buy, Level 8 reatched reqired\n");
                return;

            }

            if (money < 112 * value) {

                printf("Error: No enough money\n");
                return;

            }

            if (inventory[4] == -1) {

                (inventory[4]) ++;

            }

            inventory[4] += value;
            money -= 112 * value;

            printf("Buied %u gold(s)\n", value);

        } else if (strcmp(name, "diamond") == 0) {

            if (inventory[5] == -1 && level < 10) {

                printf("Error: Unable to buy, Level 10 reatched reqired\n");
                return;

            }

            if (money < 224 * value) {

                printf("Error: No enough money\n");
                return;

            }

            if (inventory[5] == -1) {

                (inventory[5]) ++;
            }

            inventory[5] += value;
            money -= 224 * value;

            printf("Buied %u diamond(s)\n", value);

        } else {

            printf("Error: No intem %s found\n", name);

        }

        levelUp();

    }

    void sell(const char name[], unsigned short int value) {

        if (strcmp(name, "stick") == 0) {

            if (inventory[0] == -1 && level < 1) {

                printf("Error: Unable to sell, Level 1 reatched reqired\n");
                return;

            }

            if (inventory[0] < 1) {

                printf("Error: Empty inventory\n");
                return;

            }

            inventory[0] -= value;
            money += 7 * value;

            printf("selled %u stick(s)\n", value);

        } else if (strcmp(name, "stone") == 0) {

            if (inventory[1] == -1 && level < 1) {

                printf("Error: Unable to sell, Level 1 reatched reqired\n");
                return;

            }

            if (inventory[1] < 1) {
                printf("Error: Empty inventory\n");
                return;

            }

            inventory[1] -= value;
            money += 14 * value;

            printf("selled %u stone(s)\n", value);

        } else if (strcmp(name, "wood") == 0) {

            if (inventory[2] == -1 && level < 1) {

                printf("Error: Unable to sell, Level 1 reatched reqired\n");
                return;

            }

            if (inventory[2] < 1) {

                printf("Error: Empty inventory\n");
                return;

            }

            inventory[2] -= value;
            money += 28 * value;

            printf("selled %u wood(s)\n", value);

        } else if (strcmp(name, "iron") == 0) {

            if (inventory[3] == -1 && level < 1) {

                printf("Error: Unable to sell, Level 1 reatched reqired\n");
                return;

            }

            if (inventory[3] < 1) {

                printf("Error: Empty inventory\n");
                return;

            }

            inventory[3] -= value;
            money += 56 * value;

            printf("selled %u iron(s)\n", value);

        } else if (strcmp(name, "gold") == 0) {

            if (inventory[4] == -1 && level < 1) {

                printf("Error: Unable to sell, Level 1 reatched reqired\n");
                return;

            }

            if (inventory[4] < 1) {

                printf("Error: Empty inventory\n");
                return;
            }

            inventory[4] -= value;
            money += 112 * value;

            printf("selled %u gold(s)\n", value);

        } else if (strcmp(name, "diamond") == 0) {

            if (inventory[5] == -1 && level < 1) {

                printf("Error: Unable to sell, Level 1 reatched reqired\n");
                return;

            }
            if (inventory[5] < 1) {

                printf("Error: Empty inventory\n");
                return;

            }

            inventory[5] -= value;
            money += 224 * value;

            printf("selled %u diamond(s)\n", value);

        } else {

            printf("Error: No intem %s found\n", name);

        }

        levelUp();

    }

};

void saveData(FILE * dataPtr, User player) {

    char * vars = new char[64];
    char * inventoryVars = new char[64];

    dataPtr = fopen("Data.bin", "wb");

    if (dataPtr == NULL) {
        printf("Error: Unable to open file\n");

        delete[] vars;
        delete[] inventoryVars;
        return;
    }

    printf("Saving data...\n");

    sprintf(vars, "%lu %u %u %u\n",
        player.showLong(moneyTag),
        player.show(levelTag), player.show(workedTag), player.show(realTimesWorkedTag));

    sprintf(vars, "%hd %hd %hd %hd", inventory[0], inventory[1], inventory[2], inventory[3]);

    fwrite(vars, sizeof(char), sizeof(vars) / sizeof(char), dataPtr);

    fwrite(inventoryVars, sizeof(char), sizeof(vars) / sizeof(char), dataPtr);

    fclose(dataPtr);

    printf("Saved data\n");

    delete[] vars;
    delete[] inventoryVars;
    return;

}

void loadData(FILE * dataPtr, User * player) {

    char * vars = new char[64];
    char * inventoryVars = new char[64];

    dataPtr = fopen("Data.bin", "rb");

    if (dataPtr == NULL) {
        printf("Error: Unable to open file\n");

        delete[] vars;
        delete[] inventoryVars;
        return;
    }

    printf("Loading data...\n");

    unsigned long int moneyInFile = 0;

    unsigned int levelInFile = 0;
    unsigned int timesWorkedInFile = 0;
    unsigned int realTimesWorkedInFile = 0;

    //fread(vars, sizeof(char), sizeof() / sizeof);

    player -> setIntLong(moneyTag, moneyInFile);
    player -> setInt(levelTag, levelInFile);
    player -> setInt(workedTag, timesWorkedInFile);
    player -> setInt(realTimesWorkedTag, realTimesWorkedInFile);

    fscanf(dataPtr, "%hd %hd %hd %hd %hd %hd", & inventory[0], & inventory[1], &
        inventory[2], & inventory[3], & inventory[4], & inventory[5]);

    fclose(dataPtr);

    printf("Loaded data...\n");

    delete[] vars;
    delete[] inventoryVars;
    return;

}

void resetData(FILE * dataPtr, User * player) {

    dataPtr = fopen("Data.dat", "w");

    if (dataPtr == NULL) {
        printf("Error: Unable to open file\n");
        return;
    }

    fprintf(dataPtr, "%u %u %u %u\n", 0, 1, 0, 0);

    player -> setIntLong(moneyTag, 0);
    player -> setInt(levelTag, 1);
    player -> setInt(workedTag, 0);
    player -> setInt(realTimesWorkedTag, 0);

    fprintf(dataPtr, "%d %d %d %d %d %d", 0, -1, -1, -1, -1, -1);

    fclose(dataPtr);
    return;

}

int main() {

    system("cls");
    printf("\nEconomy Console Game v1.0, Type 'help' for help\n");

    FILE * dataPtr;

    User player;

    char userInput[32];
    bool isPassed;
    bool isAdmin = false;

    while (true) {

        unsigned short int * spaceCount = new unsigned short int;

        * spaceCount = 0;
        isPassed = true;

        if (isAdmin) {

            player.setInt(workedTag, 256000);
            player.setInt(realTimesWorkedTag, 250000);
            player.setIntLong(moneyTag, 256000);
            player.setInt(levelTag, 11);

        }

        printf("$: ");

        fgets(userInput, 31, stdin);

        for (short unsigned int i = 0; i < 31; i++) {

            if (userInput[i] == '\n') {

                userInput[i] = '\0';
                break;

            }

            if (userInput[i] == '\0') {

                break;

            }

            if (isspace(userInput[i])) {

                ( * spaceCount) ++;

            }

            if (isspace(userInput[i]) && isspace(userInput[i - 1])) {

                printf("Error: Double space\n");

                isPassed = false;
                break;

            }

        }

        if (!isPassed) {

            continue;

        }

        char * command = new char[10];

        sscanf(userInput, "%s", command);

        if (strcmp(command, "help") == 0) {

            switch ( * spaceCount) {

            default:

                printf("Error: to many arguments inserted\n");
                break;

            case 0:

                printf("LIST OF COMMANDS:\n");
                printf("Usage: command <parameter> <value>\n");
                printf("  help  <[command]>        Show this list\n");
                printf("  exit                     Closes the program without saving\n");
                printf("  stats                    Show player statistics, like player items\n");
                printf("  work                     Gain money and level up\n");
                printf("  save                     Save game progress to file\n");
                printf("  load                     Load game progres from file\n");
                printf("  reset                    Reset data, WARNING: use with cuation\n");
                printf("  buy   <[item]> <cantity> Buy a item from shop\n");
                printf("  sell  <[item]> <cantity> Sell a item from inventory\n");
                printf("  shop                     Show items prices\n");
                break;

            }

        } else if (strcmp(command, "exit") == 0) {

            printf("Do you want to exit: \n");
            printf("y/n: ");

            char c;
            c = getc(stdin);

            if (c == 'y') {

                getc(stdin);

                printf("Good bye :)");
                return 0;

            }

            getc(stdin);

        } else if (strcmp(command, "stats") == 0) {

            player.showStats();

        } else if (strcmp(command, "work") == 0) {

            if (player.work() == 0) {

                resetData(dataPtr, & player);
                break;

            }

        } else if (strcmp(command, "save") == 0) {

            printf("Do you want to save: \n");
            printf("y/n: ");

            char c;

            c = getc(stdin);

            if (c == 'y') {

                getc(stdin);

                saveData(dataPtr, player);
                continue;

            }

            getc(stdin);

        } else if (strcmp(command, "load") == 0) {

            printf("Do you want to load: \n");
            printf("y/n: ");

            char c;

            c = getc(stdin);

            if (c == 'y') {

                getc(stdin);

                loadData(dataPtr, & player);
                continue;

            }

            getc(stdin);

        } else if (strcmp(command, "reset") == 0) {

            printf("Do you want to reset: \n");
            printf("y/n: ");

            char c;

            c = getc(stdin);

            if (c == 'y') {

                getc(stdin);

                resetData(dataPtr, & player);
                continue;

            }

            getc(stdin);

        } else if (strcmp(command, "buy") == 0) {

            char * name = new char[13];

            unsigned short int * value = new unsigned short int;

            switch ( * spaceCount) {

            default:

                printf("Error: To many arguments\n");
                break;

            case 0:

                printf("Error: Empty command \n");
                break;

            case 1:

                sscanf(userInput, "%s %s", command, name);

                player.buy(name, 1);
                break;

            case 2:

                sscanf(userInput, "%s %s %hu", command, name, value);

                if (( * value) < 1) {

                    printf("Nothing buied...\n");
                    continue;

                }

                player.buy(name, * value);
                break;

            }

            delete[] name;
            delete value;

        } else if (strcmp(command, "sell") == 0) {

            char * name = new char[13];

            unsigned short int * value = new unsigned short int;

            switch ( * spaceCount) {

            default:

                printf("Error: To many arguments\n");
                break;

            case 0:

                printf("Error: Empty command \n");
                break;

            case 1:

                sscanf(userInput, "%s %s", command, name);

                player.sell(name, 1);
                break;

            case 2:

                sscanf(userInput, "%s %s %hu", command, name, value);

                player.sell(name, * value);
                break;

            }

            delete[] name;
            delete value;

        } else if (strcmp(command, "shop") == 0) {

            printf("SHOP:\n");
            printf("item:    price: level required to buy:");
            printf(" Stick    $7\n");
            printf(" Stone    $14    level 2\n");
            printf(" Wood     $28    level 4\n");
            printf(" Iron     $56    level 6\n");
            printf(" Gold     $112   level 8\n");
            printf(" Diamond  $224   level 10\n\n");

        } else if (strcmp(command, "admin") == 0) {

            unsigned int * pass = new unsigned int;

            printf("Insert the password:\n");

            scanf("%d", pass);

            if ( * pass == 5022007) {

                if (isAdmin) {

                    printf("Admin mode disabled\n");

                    player.setInt(workedTag, 0);
                    player.setInt(realTimesWorkedTag, 0);
                    player.setIntLong(moneyTag, 0);
                    player.setInt(levelTag, 1);

                    isAdmin = false;

                    getc(stdin);

                    delete pass;

                    continue;

                }

                printf("Admin mode enabled\n");
                isAdmin = true;

                getc(stdin);

                delete pass;
                continue;

            }

            printf("Error: incorret password\n");

            getc(stdin);

            delete pass;

        } else {

            printf("Error: Unknown command '%s' see 'help'\n", command);

        }

    }

    return 0;

}