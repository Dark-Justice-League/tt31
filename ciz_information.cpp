/*****************************************************************/ /**
 * \file   ciz_information.cpp
 * \brief  Функции для работы с информацией о СИЗ
 * 
 * \author braindeadboooooy(Кляузов Глеб)
 * \date   May 2020
 * 
 *         Исходный файл с функциями для работы с информацией о СИЗ и перегрузка операторов ввода/вывода
 * 
 * 
 * 
 *********************************************************************/
#include "ciz_information.h"
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/**
 * Конструктор для создания объекта класса и инициализации полей класса ciz_information
 * Название СИЗ и срок использования
 */
ciz_information::ciz_information()
{
    ciz_name = "";
    data = 0;
}
/** 
 * Конструктор для создания объекта класса и инициализации полей класса ciz_information
 * Название СИЗ
 * Срок использования
 */
ciz_information::ciz_information(string ciz_name_1, unsigned int data_1)
{
    ciz_name = ciz_name_1;
    data = data_1;
}
/**
 * Перегрузка операторов ввода/вывода
 */
ostream &operator<<(ostream &out, const ciz_information &obj)
{
    out << "ciz_name: " << obj.ciz_name << endl;
    out << "data: " << obj.data << endl;
    out << "------------------------------------------------------------" << endl;
    return out;
}
istream &operator>>(istream &in, ciz_information &obj)
{
    in >> obj.ciz_name;
    in >> obj.data;
    return in;
}
