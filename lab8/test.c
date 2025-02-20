#include <stdio.h>
#define TABLE_SIZE 10

// Global variables for hash table
int keys[TABLE_SIZE];   // Keys for probing methods
int values[TABLE_SIZE]; // Values for probing methods

// Initialize for all methods
void initializeTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        keys[i] = -1; // Empty slots
        values[i] = 0;
    }
}

void insertLinearProbing(int key, int value)
{
    int index = key % TABLE_SIZE;
    int startIndex = index;

    while (keys[index] != -1)
    {
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex)
        {
            printf("Hash table is full (Linear Probing)\n");
            return;
        }
    }

    keys[index] = key;
    values[index] = value;
    printf("Linear Probing: Inserted key %d at index %d\n", key, index);
}

int searchLinearProbing(int key)
{
    int index = key % TABLE_SIZE;
    int startIndex = index;

    while (keys[index] != -1)
    {
        if (keys[index] == key)
        {
            return values[index];
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex)
        {
            break;
        }
    }

    return -1; // Not found
}
void insertQuadraticProbing(int key, int value)
{
    int index = key % TABLE_SIZE;
    int i = 0;

    while (keys[(index + i * i) % TABLE_SIZE] != -1)
    {
        i++;
        if (i >= TABLE_SIZE)
        {
            printf("Hash table is full (Quadratic Probing)\n");
            return;
        }
    }

    index = (index + i * i) % TABLE_SIZE;
    keys[index] = key;
    values[index] = value;
    printf("Quadratic Probing: Inserted key %d at index %d\n", key, index);
}

int searchQuadraticProbing(int key)
{
    int index = key % TABLE_SIZE;
    int i = 0;

    while (keys[(index + i * i) % TABLE_SIZE] != -1)
    {
        if (keys[(index + i * i) % TABLE_SIZE] == key)
        {
            return values[(index + i * i) % TABLE_SIZE];
        }
        i++;
        if (i >= TABLE_SIZE)
        {
            break;
        }
    }

    return -1; // Not found
}

int secondHash(int key){
    return 7 - (key % 7); // Secondary hash step
}

void insertDoubleHashing(int key, int value)
{
    int index = key % TABLE_SIZE;
    int step = secondHash(key);

    while (keys[index] != -1)
    {
        index = (index + step) % TABLE_SIZE;
    }

    keys[index] = key;
    values[index] = value;
    printf("Double Hashing: Inserted key %d at index %d\n", key, index);
}

int searchDoubleHashing(int key)
{
    int index = key % TABLE_SIZE;
    int step = secondHash(key);

    while (keys[index] != -1)
    {
        if (keys[index] == key)
        {
            return values[index];
        }
        index = (index + step) % TABLE_SIZE;
    }

    return -1; // Not found
}

#define MAX_CHAIN 5                // For Separate Chaining
int chains[TABLE_SIZE][MAX_CHAIN]; // 2D array for separate chaining

void initializeChaining()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        for (int j = 0; j < MAX_CHAIN; j++)
        {
            chains[i][j] = -1; // Empty chains
        }
    }
}

void insertChaining(int key, int value)
{
    int index = key % TABLE_SIZE;

    for (int i = 0; i < MAX_CHAIN; i++)
    {
        if (chains[index][i] == -1)
        {
            chains[index][i] = value;
            printf("Separate Chaining: Inserted key %d at index %d, chain %d\n", key, index, i);
            return;
        }
    }

    printf("No space in chain for key %d\n", key);
}

void displayChaining()
{
    printf("Separate Chaining:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("[%d]: ", i);
        for (int j = 0; j < MAX_CHAIN; j++)
        {
            if (chains[i][j] != -1)
            {
                printf("%d -> ", chains[i][j]);
            }
        }
        printf("NULL\n");
    }
}
int main()
{
    initializeTable();
    initializeChaining();

    printf("Testing Linear Probing:\n");
    insertLinearProbing(1, 10);
    insertLinearProbing(11, 20);
    printf("Value for key 11: %d\n", searchLinearProbing(11));
    printf("\n");

    printf("Testing Quadratic Probing:\n");
    insertQuadraticProbing(2, 30);
    insertQuadraticProbing(12, 40);
    printf("Value for key 12: %d\n", searchQuadraticProbing(12));
    printf("\n");

    printf("Testing Double Hashing:\n");
    insertDoubleHashing(3, 50);
    insertDoubleHashing(13, 60);
    printf("Value for key 13: %d\n", searchDoubleHashing(13));
    printf("\n");

    printf("Testing Separate Chaining:\n");
    insertChaining(4, 70);
    insertChaining(14, 80);
    displayChaining();

    return 0;
}
