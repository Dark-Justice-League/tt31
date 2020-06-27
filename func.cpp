#include "func.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <math.h>
#include "ciz_information.h"
#include "sotrudnik_information.h"
#include "shop_information.h"
using namespace std;


void Func::addSotr(string _poisk_shop_name, int _count_shop, int _count_sotr, shop_information * _mas_shop, string _name_adding, string _surname_adding, string _middlename_adding, int _size_sotrudnik){
        int flag_name = 0;
        cout << "Введите имя цеха" << endl;
        cin >> _poisk_shop_name;
        for (int i = 0; i < _count_shop; i++)
        {
            if (_poisk_shop_name == _mas_shop[i].Getshop_name())
            {
                cout << "Введите имя сотрудника" << endl;
                cin >> _name_adding;
                cout << "Введите фамилию сотрудника" << endl;
                cin >> _surname_adding;
                cout << "Введите отчество сотрудника" << endl;
                cin >> _middlename_adding;
                sotrudnik_information a(_name_adding, _surname_adding, _middlename_adding);
                flag_name = 1;
                sotrudnik_information **mas_sotrudnik = _mas_shop[i].Getmas_sotrudnik();
                if (*mas_sotrudnik == NULL)
                {
                    *mas_sotrudnik = new sotrudnik_information[5];
                    _mas_shop[i].setsotrudnik_size(5);
                }
                if (_mas_shop[i].Getsotrudnik_size() <= _mas_shop[i].Getsotrudnik_count())
                {
                    sotrudnik_information *new_mas_sotrudnik = new sotrudnik_information[2 * _size_sotrudnik];
                    copy_n(*mas_sotrudnik, _size_sotrudnik, new_mas_sotrudnik);
                    delete[] * mas_sotrudnik;
                    *mas_sotrudnik = new_mas_sotrudnik;
                    _size_sotrudnik *= 2;
                    _mas_shop[i].setsotrudnik_size(_size_sotrudnik);
                }
                _count_sotr = _mas_shop[i].Getsotrudnik_count();
                (*mas_sotrudnik)[_count_sotr++] = a;
                _mas_shop[i].setsotrudnik_count(_count_sotr);
                break;
            }
        }
        if (flag_name == 0)
        {
            cout << "Введенного цеха не существует" << endl;
        }
}


void Func::printSotr(int _count_shop, int _count_sotr,shop_information *_mas_shop){
    for (int i = 0; i < _count_shop; ++i)
        {
            cout << "Shop #" << i + 1 << endl;
            cout << _mas_shop[i] << endl;
            sotrudnik_information **mas_sotrudnik = _mas_shop[i].Getmas_sotrudnik();
            if (*mas_sotrudnik != NULL)
            {
                _count_sotr = _mas_shop[i].Getsotrudnik_count();
                for (int j = 0; j < _count_sotr; j++)
                {
                    cout << "Sotrudnik: " << j + 1 << endl;
                    cout << (*mas_sotrudnik)[j] << endl;
                }
            }
        }
}


void Func::addCiz(string _poisk_shop_name, int _count_shop, shop_information *_mas_shop, string _ciz_name_adding, int _ciz_data_adding, int _count_ciz, int _size_ciz){
        int flag_name = 0;
        cout << "Введите имя цеха" << endl;
        cin >> _poisk_shop_name;
        for (int i = 0; i < _count_shop; i++)
        {
            if (_poisk_shop_name == _mas_shop[i].Getshop_name())
            {
                cout << "Введите  название СИЗ" << endl;
                cin >> _ciz_name_adding;
                cout << "Введите  срок ношения (в часах)" << endl;
                cin >> _ciz_data_adding;
                ciz_information c(_ciz_name_adding, _ciz_data_adding);
                flag_name = 1;
                ciz_information **mas_ciz = _mas_shop[i].Getmas_ciz();
                if (*mas_ciz == NULL)
                {
                    *mas_ciz = new ciz_information[5];
                    _mas_shop[i].setciz_size(5);
                }
                if (_mas_shop[i].Getciz_size() <= _mas_shop[i].Getciz_count())
                {
                    ciz_information *new_mas_ciz = new ciz_information[2 * _size_ciz];
                    copy_n(*mas_ciz, _size_ciz, new_mas_ciz);
                    delete[] * mas_ciz;
                    *mas_ciz = new_mas_ciz;
                    _size_ciz *= 2;
                    _mas_shop[i].setciz_size(_size_ciz);
                }
                _count_ciz = _mas_shop[i].Getciz_count();
                (*mas_ciz)[_count_ciz++] = c;
                _mas_shop[i].setciz_count(_count_ciz);
            }
        }
        if (flag_name == 0)
        {
            cout << "Введенного цеха не существует" << endl;
        }

}


void Func::printCiz(int _count_shop, shop_information *_mas_shop, int _count_ciz){
     for (int i = 0; i < _count_shop; i++)
        {
            cout << "Shop #" << i + 1 << endl;
            cout << _mas_shop[i] << endl;
            ciz_information **mas_ciz = _mas_shop[i].Getmas_ciz();
            if (*mas_ciz != NULL)
            {
                _count_ciz = _mas_shop[i].Getciz_count();
                for (int k = 0; k < _count_ciz; ++k)
                {
                    cout << "СИЗ:" << k + 1 << endl;
                    cout << (*mas_ciz)[k] << endl;
                }
            }
        }
}


void Func::addShop(string _shopname_adding, int _size_shop, int _count_shop, shop_information *_mas_shop){
    cout << "Введите название цеха" << endl;
    cin >> _shopname_adding;
    shop_information b(_shopname_adding);
    if (_size_shop <= _count_shop)
    {
        shop_information *new_mas_shop = new shop_information[2 * _size_shop];
        copy_n(_mas_shop, _size_shop, new_mas_shop);
        delete[] _mas_shop;
        _mas_shop = new_mas_shop;
        _size_shop *= 2;
    }
    _mas_shop[_count_shop++] = b;
}


void Func::printShop(int _count_shop, shop_information *_mas_shop, int _count_ciz){
    for (int i = 0; i < _count_shop; ++i)
        {
        cout << "Shop #" << i + 1 << endl;
        cout << _mas_shop[i] << endl;
        ciz_information **mas_ciz = _mas_shop[i].Getmas_ciz();
        if (*mas_ciz != NULL)
            {
                _count_ciz = _mas_shop[i].Getciz_count();
                for (int k = 0; k < _count_ciz; ++k)
                {
                    cout << "СИЗ:" << k + 1 << endl;
                    cout << (*mas_ciz)[k] << endl;
                }
            }
        }
}


void Func::deleteSotr(string _shopname_search, int _count_shop, shop_information *_mas_shop, int _count_sotr, string _name_search, string _surname_search, string _middlename_search){
            cout << "Введите имя цеха: " << endl;
            cin >> _shopname_search;
            int check = 0;
            int check2 = 0;
            for (int i = 0; i < _count_shop; ++i)
            {
                if (_shopname_search == _mas_shop[i].Getshop_name())
                {
                    sotrudnik_information **mas_sotrudnik = _mas_shop[i].Getmas_sotrudnik();
                    _count_sotr = _mas_shop[i].Getsotrudnik_count();
                    check2 = 1;
                    if (_count_sotr == 0)
                    {
                        cout << "Цех пуст!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Введите имя сотрудника: " << endl;
                        cin >> _name_search;
                        cout << "Введите фамилию сотрудника: " << endl;
                        cin >> _surname_search;
                        cout << "Введите отчество сотрудника: " << endl;
                        cin >> _middlename_search;
                        for (int j = 0; j < _count_sotr; ++j)
                        {
                            if ((_surname_search == (*mas_sotrudnik)[j].Getsotrudnik_surname()) && (_name_search == (*mas_sotrudnik)[j].Getsotrudnik_name()) && (_middlename_search == (*mas_sotrudnik)[j].Getsotrudnik_middlename()))
                            {
                                for (int k = j; k < _count_sotr - 1; ++k)
                                {
                                    (*mas_sotrudnik)[k].Getsotrudnik_surname() = (*mas_sotrudnik)[k + 1].Getsotrudnik_surname();
                                    (*mas_sotrudnik)[k].Getsotrudnik_name() = (*mas_sotrudnik)[k + 1].Getsotrudnik_name();
                                    (*mas_sotrudnik)[k].Getsotrudnik_middlename() = (*mas_sotrudnik)[k + 1].Getsotrudnik_middlename();
                                }
                                _count_sotr = _count_sotr - 1;
                                _mas_shop[i].setsotrudnik_count(_count_sotr);
                                check = check + 1;
                            }
                        }
                        if (check == 0)
                        {
                            cout << "Сотрудник не найден!" << endl;
                            break;
                        }
                    }
                }
            }
            if (check2 == 0)
            {
                cout << "Цех не найден!" << endl;
            }
}


void Func::calculation(string _answer, string _poisk_shop_name, int _data_srok, int _count_shop, shop_information *_mas_shop, int _count_sotr, int _count_ciz, string _name_search, string _surname_search, string _middlename_search){
            cout << "Введите для кого рассчитать" << endl;
            cout << "1 - если для цеха, 2- для сотрудника, 3 - для предприятия" << endl;
            cin >> _answer;
            if (_answer == "1")
            {
                int flag_name_2 = 0;
                cout << "Введите название цеха" << endl;
                cin >> _poisk_shop_name;
                cout << "Введите на какой период (в днях) рассчитать кол-во СИЗ" << endl;
                cin >> _data_srok;
                _data_srok = _data_srok * 24;
                int count = 0;
                for (int i = 0; i < _count_shop; ++i)
                {
                    if (_poisk_shop_name == _mas_shop[i].Getshop_name())
                    {
                        flag_name_2 = 1;
                        sotrudnik_information **mas_sotrudnik = _mas_shop[i].Getmas_sotrudnik();
                        if (*mas_sotrudnik != NULL)
                        {
                            _count_sotr = _mas_shop[i].Getsotrudnik_count();
                        }
                        if (_count_sotr == 0)
                        {
                            cout << "В цеху нет сотрудников" << endl;
                        }
                        else
                        {
                            ciz_information **mas_ciz = _mas_shop[i].Getmas_ciz();
                            if (*mas_ciz != NULL)
                            {
                                _count_ciz = _mas_shop[i].Getciz_count();
                                for (int k = 0; k < _count_ciz; ++k)
                                {
                                    count = ceil((double)_data_srok / (double)(*mas_ciz)[k].Getciz_data()) * _count_sotr;
                                    cout << "на " << _data_srok / 24 << " дней нужно " << (*mas_ciz)[k].Getciz_name() << " количество " << count << endl;
                                }
                            }
                            else
                            {
                                cout << "В цеху нет СИЗ" << endl;
                            }
                        }
                    }
                }
                if (flag_name_2 == 0)
                {
                    cout << "Введенного цеха не существует" << endl;
                }
            }
            else
            {
                if (_answer == "2")
                {
                    int flag_name_2 = 0;
                    cout << "Введите название цеха" << endl;
                    cin >> _poisk_shop_name;
                    cout << "Введите фамилию сотрудника: " << endl;
                    cin >> _surname_search;
                    cout << "Введите имя сотрудника: " << endl;
                    cin >> _name_search;
                    cout << "Введите отчество сотрудника: " << endl;
                    cin >> _middlename_search;
                    cout << "Введите на какой период(в днях) рассчитать кол-во СИЗ" << endl;
                    cin >> _data_srok;
                    _data_srok = _data_srok * 24;
                    int check = 0;
                    int count = 0;
                    for (int i = 0; i < _count_shop; ++i)
                    {
                        if (_poisk_shop_name == _mas_shop[i].Getshop_name())
                        {
                            flag_name_2 = 1;
                            sotrudnik_information **mas_sotrudnik = _mas_shop[i].Getmas_sotrudnik();
                            if (*mas_sotrudnik != NULL)
                            {
                                _count_sotr = _mas_shop[i].Getsotrudnik_count();
                                if (_count_sotr == 0)
                                {
                                    cout << "В цеху нет сотрудников" << endl;
                                }
                                else
                                {
                                    for (int j = 0; j < _count_sotr; j++)
                                    {
                                        if ((_surname_search == (*mas_sotrudnik)[j].Getsotrudnik_surname()) && (_name_search == (*mas_sotrudnik)[j].Getsotrudnik_name()) && (_middlename_search == (*mas_sotrudnik)[j].Getsotrudnik_middlename()))
                                        {
                                            check = 1;
                                        }
                                    }
                                }
                            }
                            if (check == 1)
                            {
                                ciz_information **mas_ciz = _mas_shop[i].Getmas_ciz();
                                if (*mas_ciz != NULL)
                                {
                                    _count_ciz = _mas_shop[i].Getciz_count();
                                    for (int k = 0; k < _count_ciz; ++k)
                                    {
                                        count = ceil((double)_data_srok / (double)(*mas_ciz)[k].Getciz_data());
                                        cout << "на " << _data_srok / 24 << " дней нужно " << (*mas_ciz)[k].Getciz_name() << " количество " << count << endl;
                                    }
                                }
                                else
                                {
                                    cout << "В цеху нет СИЗ" << endl;
                                }
                            }
                        }
                    }
                    if (flag_name_2 == 0)
                    {
                        cout << "Введенного цеха не существует" << endl;
                    }
                    if (check == 0)
                    {
                        cout << "Введенного сотрудника не существует" << endl;
                    }
                }
                if (_answer == "3")
                {
                    cout << "Введите на какой период(в днях) рассчитать кол-во СИЗ" << endl;
                    cin >> _data_srok;
                    _data_srok = _data_srok * 24;
                    int count = 0;
                    for (int i = 0; i < _count_shop; ++i)
                    {
                        sotrudnik_information **mas_sotrudnik = _mas_shop[i].Getmas_sotrudnik();
                        if (*mas_sotrudnik != NULL)
                        {
                            _count_sotr = _mas_shop[i].Getsotrudnik_count();
                        }
                        ciz_information **mas_ciz = _mas_shop[i].Getmas_ciz();
                        if (*mas_ciz != NULL)
                        {
                            _count_ciz = _mas_shop[i].Getciz_count();
                            for (int k = 0; k < _count_ciz; ++k)
                            {
                                count = ceil((double)_data_srok / (double)(*mas_ciz)[k].Getciz_data()) * _mas_shop[i].Getsotrudnik_count();
                                cout << "на " << _data_srok / 24 << " дней нужно " << (*mas_ciz)[k].Getciz_name() << " количество " << count << endl;
                            }
                        }
                    }
                }
            }
}