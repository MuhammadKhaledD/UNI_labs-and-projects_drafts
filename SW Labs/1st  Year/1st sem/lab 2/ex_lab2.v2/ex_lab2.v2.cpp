#include <iostream>

using namespace std;

int Multi(int* arrx, int sizex, int*& arry, int val);

int main()
{
    int sizex;
    cin >> sizex;

    int* arrx = new int[sizex];
    for (int i = 0; i < sizex; ++i)
        cin >> *(arrx + i);

    int val;
    cin >> val;

    int* arry = NULL;
    int size = Multi(arrx, sizex, arry, val);

    for (int i = 0; i < size; ++i)
        cout << *(arry + i) << " ";

    cout << endl << endl;

    for (int c = 0; c < 5; ++c)
    {
        cin >> sizex;
        if (sizex == 0)
        {
            cout << "Empty\n\n";
            continue;
        }

        arrx = new int[sizex];
        for (int i = 0; i < sizex; ++i)
            cin >> *(arrx + i);

        cin >> val;
        if (val == 0)
        {
            cout << "0 not br a divisable element\n\n";
            continue;
        }

        int size = Multi(arrx, sizex, arry, val);

        for (int i = 0; i < size; ++i)
            cout << *(arry + i) << " ";

        cout << endl << endl;
    }

    delete[]arrx;
    delete[]arry;
    arrx = NULL;
    arry = NULL;

    return 0;

}

int Multi(int* arrx, int sizex, int*& arry, int val)
{
    int size = 0;

    for (int i = 0; i < sizex; ++i)
        if ((*(arrx + i) % val) == 0)
            ++size;

    arry = new int[size];
    int count = 0;

    for (int i = 0; i < sizex; ++i)
        if ((*(arrx + i) % val) == 0)
        {
            *(arry + count) = *(arrx + i);
            count++;
        }

    return size;
}
