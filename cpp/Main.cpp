#include <iostream>
#include <fstream>
using namespace std;

class Matrix {
    int n;
    int **arr = new int*[n];
    int **brr = new int*[n];

public:
    int scale() {
        cout<<"Enter the scale: ";
        cin>>n;
        while (n<=0) {
            cout<<"Enter the right scale!"<< endl;
            cin>>n;
        }
        return n;
    }
    int** filler() {
        setlocale(LC_ALL, "ru");
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
            brr[i] = new int[n];
        }
        string path = "matrix.txt";
        ifstream fin;
        fin.open(path);
        if (!fin.is_open())
        {
            cout << "Ошибка открытия файла!" << endl;
        }
        else {
            cout << "Файл открыт" << endl;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    fin >> arr[i][j];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    fin >> brr[i][j];
        }   
        return arr;
        return brr;
    }
    int** manualFiller() {
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
            brr[i] = new int[n];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cout<<"Enter matrix a[" << i+1 << "][" << j+1 << "]" << endl;
                cin >> arr[i][j];
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cout<<"Enter matrix b[" << i+1 << "][" << j+1 << "]" << endl;
                cin >> brr[i][j];
            }
        return arr;
        return brr;    
    }
    void plus() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = arr[i][j] + brr[i][j];
                cout<< sum << " ";
                if (j == n - 1) 
                    cout << endl;
            }
        }
    }
    void minus() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sub = arr[i][j] - brr[i][j];
                cout<< sub << " ";
                if (j == n - 1) 
                    cout << endl;
            }
        }
    }
    void multi() {
        int** res;
        int i, j;
        res = new int* [n];
        for (i = 0; i < n; i++)
            res[i] = new int[n];


        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                res[i][j] = 0;
                for (int k = 0; k < n; k++)
                    res[i][j] += arr[i][k] * brr[k][j];
            }
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++)
                    cout << res[i][j] << "\t";
            cout << endl;
        }
    }            
};

int main() {
    int k = 0;
    Matrix matrix1;
    cout<<"Choose an option: \n \
    1 - Enter matrix manually. \n \
    2 - Read matrix from the file. \n";
    cin>> k;
    switch (k) {
            case 1: { 
                matrix1.scale();
                matrix1.manualFiller();
                k = 0;
                break;
            }
            case 2: { 
                matrix1.scale();
                matrix1.filler();
                k = 0;
                break;
            }
            default: { 
                cout<<"Error! wrong operation! Insert true command.\n";
                k = 0;
                break;
            } 
    }
    while (k != -1) {
        cout<< "Choose an option: \n \
        1 - Addition. \n \
        2 - Subtraction. \n \
        3 - Multiplication. \n \
        4 - Exit. \n";
        cin>> k;
        switch (k) {
            case 1: { 
                matrix1.plus();
                k = 0;
                break;
            }
            case 2: { 
                matrix1.minus();
                k = 0;
                break;
            }
            case 3: {
                matrix1.multi(); 
                k = 0;
                break;
            }
            case 4: { 
                k = -1;
                break;
            }
            default: { 
                cout<<"Error! wrong operation! Insert true command.\n";
                k = 0;
                break;
            } 
        }
    }
    return 0;
}