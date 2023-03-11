
#include <iostream>
#include <string>

using namespace std;

int pl1[10][10] = { 0 };
int pl2[10][10] = { 0 };
static int label = 1;

int GetV(string crd, int(*arr)[10]) {
    int row = int(crd[0]) - 65;
    int col = int(crd[1]) - 48;
    return arr[row][col];

}

void SetV(string crd, int(*arr)[10], int new_v) {
    int row = int(crd[0]) - 65;
    int col = int(crd[1]) - 48;
    arr[row][col] = new_v;
}

void ValidSetUp(int(*a)[10], string str) {
    bool Top = int(str[0]) == 'A' || a[int(str[0]) - 66][int(str[1]) - 48] ? true : false;
    bool Bottom = int(str[0]) == 'J' || a[int(str[0]) - 64][int(str[1]) - 48] ? true : false;
    bool Left = int(str[1]) == '0' || a[int(str[0]) - 64][int(str[1]) - 49] ? true : false;
    bool Right = int(str[1]) == '9' || a[int(str[0]) - 64][int(str[1]) - 47] ? true : false;
    if (Top && Bottom && Left && Right) {
        SetV(str, a, label);
    }
}

void PutShips(int(*a)[10]) {
    string linkor[4];
    string kreiser[3];
    string esminets[2];
    string boat[4];
    cout << "Where you gonna put linkor: ";
    for (int i = 0; i < 4; i++) {
        cin >> linkor[i];
        SetV(linkor[i], a, label);
    }
    cout << endl << "Where you gonna put kreisers: ";
    for (size_t i = 0; i < 2; i++)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> kreiser[i];
            
            SetV(kreiser[i], a, label);
        }
    }
    cout << endl << "Where you gonna put esminetses: ";
    for (size_t i = 0; i < 3; i++)
    {
        for (int i = 0; i < 2; i++)
        {
            cin >> esminets[i];
            
            SetV(esminets[i], a, label);
        }
    }
    cout << endl << "Where you gonna put boat: ";
    for (int i = 0; i < 4; i++) {
        cin >> boat[i];
        cout << endl;
        SetV(boat[i], a, label);

    }

    if (label == 1) label++;
    else {
        label = 1;
    }
}

void DrawField(int(*a)[10]) {
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    PutShips(pl1);
    DrawField(pl1);
}

