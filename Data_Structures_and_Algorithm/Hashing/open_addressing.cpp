#include <bits/stdc++.h>
using namespace std;

struct Myhash
{

    int Bucket;
    int table[]; //Not working if int *table//Not correct code can't figure out conditions to on while

    Myhash(int b)
    {
        Bucket = b;
        for (int i = 0; i < Bucket; i++)
        {
            table[i] = -1;
        }
    }

    int h1(int key)
    {
        return key % 7;
    }

    int h2(int key)
    {
        return 6 - (key % 6);
    }

    void insert(int key)
    {
        int i = (h1(key) + h2(key)) % 7;

        while (table[i] != key && table[i] != -1)
        {
            i = (h1(key) + i * h2(key)) % 7;
        }

        table[i] = key;

        for (int i = 0; i < Bucket; i++)
        {
            cout << table[i] << " ";
        }
    }

    void search(int key)
    {
        int i = (h1(key) + h2(key)) % 7;

        if (table[i] == key && table[i] != -2)
        {
            cout << "true";
        }
        else
        {
            cout << "false";
        }
    }

    void delete1(int key)
    {
        int i = (h1(key) + h2(key)) % 7;
        if (table[i] != key && table[i] != -1)
        {
            i = (h1(key) + i * h2(key)) % 7;
        }

        if (table[i] != -1)
        {
            table[i] = -2;
        }

        for (int i = 0; i < Bucket; i++)
        {
            cout << table[i] << " ";
        }
    }
};

int main()
{

    Myhash H(7);

    H.insert(15);

    cout << endl;

    H.insert(16);

    cout << endl;

    H.search(15);

    cout << endl;

    H.delete1(15);

    cout << endl;

    H.delete1(16);

    cout << endl;

    H.search(5);

    return 0;
}