#ifndef func_H
#define func_H


#include <iostream>
#include <cstring>
#include <string>
#include "ciz_information.h"
#include "sotrudnik_information.h"
#include "shop_information.h"

using namespace std;

class Func{
public:

    void addSotr(string _poisk_shop_name, int _count_shop, int _count_sotr, shop_information * _mas_shop, string _name_adding, string _surname_adding, string _middlename_adding, int _size_sotrudnik);
    void printSotr(int _count_shop, int _count_sotr,shop_information *_mas_shop);
    void addCiz(string _poisk_shop_name, int _count_shop, shop_information *_mas_shop, string _ciz_name_adding, int _ciz_data_adding, int _count_ciz, int _size_ciz);
    void printCiz(int _count_shop, shop_information *_mas_shop, int _count_ciz);
    void addShop(string _shopname_adding, int _size_shop, int _count_shop, shop_information *_mas_shop);
    void printShop(int _count_shop, shop_information *_mas_shop, int _count_ciz);
    void deleteSotr(string _shopname_search, int _count_shop, shop_information *_mas_shop, int _count_sotr, string _name_search, string _surname_search, string _middlename_search);
    void calculation(string _answer, string _poisk_shop_name, int _data_srok, int _count_shop, shop_information *_mas_shop, int _count_sotr, int _count_ciz, string _name_search, string _surname_search, string _middlename_search);

};

#endif