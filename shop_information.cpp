/*****************************************************************/ /**
 * \file   shop_information.cpp
 * \brief  Функции для работы с информацией о цехах
 * 
 * \author youngh8r (Шамшетдинов Руслан)
 * \date   May 2020
 * 
 *         Исходный файл с функциями для работы с информацией о цехах и перегрузка операторов ввода/вывода
 * 
 * 
 *********************************************************************/
#include "shop_information.h"
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/**
 * Конструктор для создания объекта класса и инициализации полей класса shop_information
 * Название цеха
 * Количество сотрудников, размер массива сотрудников
 * Количество СИЗ, размер массива СИЗ
 * Размер массивов сотрудников и СИЗ для операций с памятью
 * Массив сотрудников, массив СИЗов
 */
shop_information::shop_information()
{
    sotrudnik_count = 0;
    ciz_count = 0;
    ciz_size = 0;
    sotrudnik_size = 0;
    mas_sotrudnik = NULL;
    mas_ciz = NULL;
    shop_name = "";
}
/**
 * Конструктор для создания объекта класса и инициализации полей класса shop_information
 */
shop_information::shop_information(string shopname_1)
{
    sotrudnik_count = 0;
    ciz_count = 0;
    ciz_size = 0;
    sotrudnik_size = 0;
    mas_sotrudnik = NULL;
    mas_ciz = NULL;
    shop_name = shopname_1;
}
/**
 * Перегрузка операторов ввода/вывода
 */
ostream &operator<<(ostream &out, const shop_information &obj)
{

    out << "shop name: " << obj.shop_name << endl;
    out << "____________________________________________________________" << endl;
    return out;
}
istream &operator>>(istream &in, shop_information &obj)
{
    in >> obj.shop_name;
    return in;
}
