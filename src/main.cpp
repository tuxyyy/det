#include <iostream>
#include <vector>


using namespace std;


// Функция для вывода матрицы
void printMatrix(vector<vector<double>> matrix) 
{
    for (int i = 0; i < matrix.size(); i++) 
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


// Функция для нахождения определителя матрицы
double determinant(vector<vector<double>> matrix) 
{
    double det = 1;
    int n = matrix.size();


    // Приводим матрицу к треугольному виду
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++) 
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }


    // Вычисляем определитель как произведение элементов на главной диагонали
    for (int i = 0; i < n; i++) 
    {
        det *= matrix[i][i];
    }


    return det;
}


int main() 
{
    setlocale(LC_ALL, "Russian");
    // Вводим размерность матрицы
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;


    // Создаем матрицу
    vector<vector<double>> matrix(n, vector<double>(n));
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> matrix[i][j];
        }
    }


    // Выводим матрицу
    cout << "Матрица:" << endl;
    printMatrix(matrix);


    // Вычисляем определитель
    double det = determinant(matrix);


    // Выводим определитель
    cout << "Определитель равен: " << det << endl;


    return 0;
}