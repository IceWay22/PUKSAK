// Рюкзак.cpp: определяет точку входа для консольного приложения.
//

/*
Имеются предметы, веса которых равны w1,w2,…,wn, а цены которых равны c1,c2,…,cn. 
Выбрать из них предметы, суммарный вес которых меньше 20 кг, а стоимость – максимальна.
*/

#include "stdafx.h"
#include <iostream> 

using namespace std;
 
int main()
{
    setlocale(LC_CTYPE, "rus");
    const int k = 10; // количество предметов
    const double W = 5; // вместимость рюкзака
    double m[k] = { 4, 6 ,19, 7, 5 ,3 ,1, 8 ,10, 12}; // масса предметов
    double s[k] = { 5, 8 ,4 , 5, 3, 6 ,5, 9 , 7 ,20}; // стоимость предметов
    double mass[9][k]; //массив для расчетов
    double weight = 0; //суммарный вес
    double pay = 0; // суммарная стоимость
    for (int i = 0; i<k; i++)  //заполнение строк массива и подсчет коэффициентов
    {
        mass[0][i] = (s[i] / m[i]);
        mass[1][i] = m[i];
        mass[2][i] = s[i];
        mass[3][i] = i + 1;
        
    }
    for (int i = 0; i<k; i++) //порядок убывания
    {
        for (int j = 0; j<k; j++)
        {
            double buffer;
            if (mass[0][i] > mass[0][j])
            {
                for (int f = 0; f < 4; f++)
                {
                    buffer = mass[f][i];
                    mass[f][i] = mass[f][j];
                    mass[f][j] = buffer;
                }
                
            }
        }
    }
    cout << "Предметы которые подоходят: ";
        for (int i = 0; i<k; i++)//выводим
        {
            weight += mass[1][i];
            if (weight <= W)
            {
                cout << mass[3][i] << " ";
                pay += mass[2][i];
            }
            else
            {
                weight -= mass[1][i];
            }
        }
    cout << endl << "\nОбщий вес: " << weight << endl << "\nСумма: " << pay << endl << endl;
    system("pause");
}

