// ������.cpp: ���������� ����� ����� ��� ����������� ����������.
//

/*
������� ��������, ���� ������� ����� w1,w2,�,wn, � ���� ������� ����� c1,c2,�,cn. 
������� �� ��� ��������, ��������� ��� ������� ������ 20 ��, � ��������� � �����������.
*/

#include "stdafx.h"
#include <iostream> 

using namespace std;
 
int main()
{
    setlocale(LC_CTYPE, "rus");
    const int k = 10; // ���������� ���������
    const double W = 5; // ����������� �������
    double m[k] = { 4, 6 ,19, 7, 5 ,3 ,1, 8 ,10, 12}; // ����� ���������
    double s[k] = { 5, 8 ,4 , 5, 3, 6 ,5, 9 , 7 ,20}; // ��������� ���������
    double mass[9][k]; //������ ��� ��������
    double weight = 0; //��������� ���
    double pay = 0; // ��������� ���������
    for (int i = 0; i<k; i++)  //���������� ����� ������� � ������� �������������
    {
        mass[0][i] = (s[i] / m[i]);
        mass[1][i] = m[i];
        mass[2][i] = s[i];
        mass[3][i] = i + 1;
        
    }
    for (int i = 0; i<k; i++) //������� ��������
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
    cout << "�������� ������� ���������: ";
        for (int i = 0; i<k; i++)//�������
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
    cout << endl << "\n����� ���: " << weight << endl << "\n�����: " << pay << endl << endl;
    system("pause");
}

