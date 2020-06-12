/*****************************************************************/ /**
 * \file   shop_information.h
 * \brief  Информация о цехах
 * 
 * \author youngh8r (Шамшетдинов Руслан)
 * \date   May 2020
 * 
 *         Заголовочный файл с классом shop_information содержащий информацию о цехах,
 *         массив сотрудников и массив СИЗов, а также функции для работы с ними и памятью. 
 *  
 *********************************************************************/
#ifndef shop_information_H
#define shop_information_H
#include "ciz_information.h"
#include "sotrudnik_information.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
/**
 * Класс содержаший информацию о цехе
 * Название цеха,
 * Количество сотрудников в цеху, количество СИЗ,
 * Размер массива сотрудников, размер массива СИЗ,
 * Указатели на массив сотрудников и СИЗ.
 */
class shop_information
{
private:
    /// Название цеха
    std::string shop_name;
    /// Количество сотрудников в цеху
    int sotrudnik_count;
    /// Количество СИЗ
    int ciz_count;
    /// Размер массива СИЗ
    int ciz_size;
    /// Размер массива сотрудников
    int sotrudnik_size;
    /// Массив сотрудников
    sotrudnik_information *mas_sotrudnik;
    /// Массив СИЗ
    ciz_information *mas_ciz;

public:
    /// Деструктор для удаления выделенной памяти
    ~shop_information()
    {
        if (mas_sotrudnik != NULL)
        {
            delete[] mas_sotrudnik;
        }
        if (mas_ciz != NULL)
        {
            delete[] mas_ciz;
        }
    }
    /// функция доступа для получения значения sotrudnik_count
    int Getsotrudnik_count()
    {
        return sotrudnik_count;
    }
    /// Функция, которая позволяет присвоить значение закрытой переменной sotrudnik_count
    void setsotrudnik_count(int tmp_sotrudnik_count)
    {
        sotrudnik_count = tmp_sotrudnik_count;
    }
    /// функция доступа для получения значения ciz_count
    int Getciz_count()
    {
        return ciz_count;
    }
    /// Функция, которая позволяет присвоить значение закрытой переменной ciz_count
    void setciz_count(int tmp_ciz_count)
    {
        ciz_count = tmp_ciz_count;
    }
    /// функция доступа для получения значения shop_name
    std::string &Getshop_name()
    {
        return shop_name;
    }
    /// Функция, которая позволяет присвоить значение закрытой переменной shop_name
    void setshop_name(std::string tmp_shop_name)
    {
        shop_name = tmp_shop_name;
    }
    /// функция доступа для получения значения ciz_size
    int Getciz_size()
    {
        return ciz_size;
    }
    /// Функция, которая позволяет присвоить значение закрытой переменной ciz_size
    void setciz_size(int tmp_ciz_size)
    {
        ciz_size = tmp_ciz_size;
    }
    /// функция доступа для получения значения sotrudnik_size
    int Getsotrudnik_size()
    {
        return sotrudnik_size;
    }
    /// Функция, которая позволяет присвоить значение закрытой переменной sotrudnik_size
    void setsotrudnik_size(int tmp_sotrudnik_size)
    {
        sotrudnik_size = tmp_sotrudnik_size;
    }
    /// функция доступа для получения значений массива сотрудников
    sotrudnik_information **Getmas_sotrudnik()
    {
        return &mas_sotrudnik;
    }
    /// функция доступа для получения значений массива СИЗ
    ciz_information **Getmas_ciz()
    {
        return &mas_ciz;
    }
    /// Объявление конструктора
    shop_information(std::string shopname_1);
    /// Объявление конструктора
    shop_information();
    /// Перегрузка операторов ввода/вывода
    friend std::ostream &operator<<(std::ostream &out, const shop_information &obj);
    friend std::istream &operator>>(std::istream &in, shop_information &obj);
};
std::ostream &operator<<(std::ostream &out, const shop_information &obj);
std::istream &operator>>(std::istream &in, shop_information &obj);
#endif
