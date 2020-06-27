/*****************************************************************/ /**
 * \file   func.h
 * \brief  Объявление оновных функций програмы
 * 
 * \author braindeadboooooy(Кляузов Глеб)
 * \date   May 2020
 * 
 *         Заголовочный файл, в котором объявлены основные функции программы.
 * 
 * 
 *********************************************************************/

#ifndef func_H
#define func_H


#include <iostream>
#include <cstring>
#include <string>
#include "ciz_information.h"
#include "sotrudnik_information.h"
#include "shop_information.h"

using namespace std;

/**
 * Класс Func содержит объявление основных функций программы
 */
class Func{
public:
    ///Функция добавления сотрудника в цех
    void addSotr(string _poisk_shop_name, int _count_shop, int _count_sotr, shop_information * _mas_shop, string _name_adding, string _surname_adding, string _middlename_adding, int _size_sotrudnik);
    ///Функция вывода информации о сотрудниках из всех цехов
    void printSotr(int _count_shop, int _count_sotr,shop_information *_mas_shop);
    ///Функция добавления СИЗ
    void addCiz(string _poisk_shop_name, int _count_shop, shop_information *_mas_shop, string _ciz_name_adding, int _ciz_data_adding, int _count_ciz, int _size_ciz);
    ///Функция вывода СИЗ 
    void printCiz(int _count_shop, shop_information *_mas_shop, int _count_ciz);
    ///Функция добавления цеха
    void addShop(string _shopname_adding, int _size_shop, int _count_shop, shop_information *_mas_shop);
    ///Функция вывода цеха вместе с СИЗ
    void printShop(int _count_shop, shop_information *_mas_shop, int _count_ciz);
    ///Функция удаления сотрудника из цеха
    void deleteSotr(string _shopname_search, int _count_shop, shop_information *_mas_shop, int _count_sotr, string _name_search, string _surname_search, string _middlename_search);
    ///Функция расчета количества СИХ необходимых для:  1- цеха, 2- сотрудника, 3- предприятия 
    void calculation(string _answer, string _poisk_shop_name, int _data_srok, int _count_shop, shop_information *_mas_shop, int _count_sotr, int _count_ciz, string _name_search, string _surname_search, string _middlename_search);

};

#endif
