/*****************************************************************/ /**
 * \file   main.cpp
 * \brief  
 * 
 * \author youngh8r (Шамшетдинов Руслан), PeshinaA (Пешина Анастасия), braindeadboooooy(Кляузов Глеб)
 * \date   June 2020
 *      
 *         
 *         
 *********************************************************************/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include "ciz_information.h"
#include "sotrudnik_information.h"
#include "shop_information.h"
#include "help.h"
#include "func.h"

using namespace std;
int main(int argc, char *argv[])
{
    /**
     *  Добавление сотрудника
     */
    string shopname_adding;
    string name_adding;
    string surname_adding;
    string middlename_adding;

    /**
     * Добавление СИЗ
     */
    string ciz_name_adding;
    unsigned int ciz_data_adding;

    /**
     * Поиск сотрудника
     */
    string surname_search;
    string name_search;
    string middlename_search;
    string shopname_search;
    /**
     * Срок использования СИЗ
     * Период расчета СИЗ
     */
    unsigned int ciz_data;
    unsigned int data_srok;
    /**
     * Размер массива СИЗ
     * Размер массива сотрудников 
     */
    int size_ciz;
    int size_sotrudnik;
    /**
     * Количество сотрудников
     * Количество СИЗ
     */
    int count_sotr;
    int count_ciz;
    /**
     * Создание массива цехов
     */
    shop_information *mas_shop;
    string file_name; /// Название файла
    ifstream rf;
    int choice;             /// Выбор в меню
    string poisk_shop_name; /// Поиск цеха
    string answer;
    help hlpob;

    Func func;

    if (argc >= 2)
    {
        file_name = string(argv[1]);
        rf.open(argv[1], ios::binary | ios::in);
    }
    else
    {
        cout << "Введите имя файла\n";
        cin >> file_name;
        rf.open(file_name, ios::binary | ios::in);
    }
    if (!rf)
    {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    /**
     * Выделение памяти под массив цехов -> Считывание данных из файла
     */
    int size_shop = 1;
    int count_shop = 0;
    rf.read((char *)&size_shop, sizeof(size_shop));
    rf.read((char *)&count_shop, sizeof(count_shop));
    if (!rf.gcount())
    {
        size_shop = 1;
    }
    mas_shop = new shop_information[size_shop];
    for (int i = 0; i < count_shop; i++)
    {
        size_t size1;
        rf.read((char *)&size1, sizeof(size1));
        mas_shop[i].Getshop_name().resize(size1);
        rf.read((char *)(mas_shop[i].Getshop_name().c_str()), size1);

        sotrudnik_information **mas_sotrudnik = mas_shop[i].Getmas_sotrudnik();
        ciz_information **mas_ciz = mas_shop[i].Getmas_ciz();

        rf.read((char *)&size_sotrudnik, sizeof(size_sotrudnik));
        mas_shop[i].setsotrudnik_size(size_sotrudnik);

        rf.read((char *)&size_ciz, sizeof(size_ciz));
        mas_shop[i].setciz_size(size_ciz);

        rf.read((char *)&count_sotr, sizeof(count_sotr));
        mas_shop[i].setsotrudnik_count(count_sotr);

        rf.read((char *)&count_ciz, sizeof(count_ciz));
        mas_shop[i].setciz_count(count_ciz);

        if (size_sotrudnik != 0)
        {
            *mas_sotrudnik = new sotrudnik_information[size_sotrudnik];
        }
        if (size_ciz != 0)
        {
            *mas_ciz = new ciz_information[size_ciz];
        }
        for (int j = 0; j < count_sotr; j++)
        {
            size_t size2;
            rf.read((char *)&size2, sizeof(size2));
            (*mas_sotrudnik)[j].Getsotrudnik_name().resize(size2);
            rf.read((char *)((*mas_sotrudnik)[j].Getsotrudnik_name().c_str()), size2);
            size_t size3;
            rf.read((char *)&size3, sizeof(size3));
            (*mas_sotrudnik)[j].Getsotrudnik_surname().resize(size3);
            rf.read((char *)((*mas_sotrudnik)[j].Getsotrudnik_surname().c_str()), size3);
            size_t size4;
            rf.read((char *)&size4, sizeof(size4));
            (*mas_sotrudnik)[j].Getsotrudnik_middlename().resize(size4);
            rf.read((char *)((*mas_sotrudnik)[j].Getsotrudnik_middlename().c_str()), size4);
        }
        for (int k = 0; k < count_ciz; k++)
        {
            rf.read((char *)&ciz_data, sizeof(ciz_data));
            (*mas_ciz)[k].setciz_data(ciz_data);
            size_t size5;
            rf.read((char *)&size5, sizeof(size5));
            (*mas_ciz)[k].Getciz_name().resize(size5);
            rf.read((char *)((*mas_ciz)[k].Getciz_name().c_str()), size5);
        }
    }

    rf.close();

    /**
     * Меню
     */
    for (;;)
    {
        hlpob.showmenu();
        do
        {
            cin >> choice;
        } while (!hlpob.isvalid(choice));
        if (choice == MAX_MENU_NUMBER)
            break;
        cout << endl;
        switch (choice)
        {
        /**
         * Добавление сотрудника в цех 
         * Поиск по массиву цехов нужного цеха
         * Считывание Имени, Фамилии, Отчества сотрудника
         * Выделение памяти под массив сотрудника и 
         * перевыделение памяти в случае, если Getsotrudnik_count() станет больше или равно Getsotrudnik_size()
         * Увеличение массива сотрудников после добавления сотрудника
         */
        case 1:
        {
            func.addSotr(poisk_shop_name, count_shop, count_sotr, mas_shop, name_adding, surname_adding, middlename_adding, size_sotrudnik);
        }
        break;
        /**
         * Вывод информации о сотрудниках из всех цехов
         */
        case 2:
        {
            func.printSotr(count_shop, count_sotr, mas_shop);
        }
        break;
        /**
         * Добавление СИЗ
         * Поиск по массиву цехов нужного цеха
         * Считывание наименования СИЗ и срок ношения СИЗ
         * Выделение памяти под массив сиз и 
         * перевыделение памяти в случае, если Getciz_count() больше или равно Getciz_size()
         * Увеличение массива СИЗ после добавления сотрудника 
         */
        case 3:
        {
            func.addCiz(poisk_shop_name, count_shop, mas_shop, ciz_name_adding, ciz_data_adding, count_ciz, size_ciz);
        }
        break;
        /**
         * Вывод информации о СИЗ 
         */
        case 4:
        {
            func.printCiz(count_shop, mas_shop, count_ciz);
        }
        break;
            /**
         * Добавление цеха
         * Считывание названия цеха
         * Перевыделение памяти под массив цехов в случае если, count_shop больше или равно size_shop
         * Увеличение массива цехов
         */
        case 5:
        {
            func.addShop(shopname_adding, size_shop, count_shop, mas_shop);
        }
        break;
            /**
         * Вывод информации о цехах с СИЗ
         */
        case 6:
        {
            func.printShop(count_shop, mas_shop, count_ciz);
        }
        break;
            /**
         * Удаление сотрудника из цеха 
         * Поиск по цеху 
         * Считывание Имени, Фамилии, Отчества сотрудника, которого ищем
         * Если такой нашелся, то удаление 
         * Уменьшение массива сотрудников
         */
        case 7:
        {
            func.deleteSotr(shopname_search, count_shop, mas_shop, count_sotr, name_search, surname_search, middlename_search);
        }
        break;
        /**
         * Расчет количества СИЗ необходимых для:
         * 1- цеха, 2- сотрудника, 3- предприятия 
         */
        case 8:
        {
            func.calculation(answer, poisk_shop_name, data_srok, count_shop, mas_shop, count_sotr, count_ciz, name_search, surname_search, middlename_search);
        }
        break;
        }
    }
    /**
     * Запись в файл 
     */
    ofstream wf;
    wf.open(file_name, ios::binary | ios::out);
    wf.write((char *)&size_shop, sizeof(size_shop));
    wf.write((char *)&count_shop, sizeof(count_shop));
    for (int i = 0; i < count_shop; i++)
    {
        size_t size1 = mas_shop[i].Getshop_name().length();
        wf.write((char *)&size1, sizeof(size1));
        wf.write((char *)(mas_shop[i].Getshop_name().c_str()), size1);

        sotrudnik_information **mas_sotrudnik = mas_shop[i].Getmas_sotrudnik();
        ciz_information **mas_ciz = mas_shop[i].Getmas_ciz();

        size_sotrudnik = mas_shop[i].Getsotrudnik_size();
        wf.write((char *)&size_sotrudnik, sizeof(size_sotrudnik));

        size_ciz = mas_shop[i].Getciz_size();
        wf.write((char *)&size_ciz, sizeof(size_ciz));

        count_sotr = mas_shop[i].Getsotrudnik_count();
        wf.write((char *)&count_sotr, sizeof(count_sotr));

        count_ciz = mas_shop[i].Getciz_count();
        wf.write((char *)&count_ciz, sizeof(count_ciz));
        for (int j = 0; j < count_sotr; j++)
        {
            size_t size2 = (*mas_sotrudnik)[j].Getsotrudnik_name().length();
            wf.write((char *)&size2, sizeof(size2));
            wf.write((char *)((*mas_sotrudnik)[j].Getsotrudnik_name().c_str()), size2);

            size_t size3 = (*mas_sotrudnik)[j].Getsotrudnik_surname().length();
            wf.write((char *)&size3, sizeof(size3));
            wf.write((char *)((*mas_sotrudnik)[j].Getsotrudnik_surname().c_str()), size3);

            size_t size4 = (*mas_sotrudnik)[j].Getsotrudnik_middlename().length();
            wf.write((char *)&size4, sizeof(size4));
            wf.write((char *)((*mas_sotrudnik)[j].Getsotrudnik_middlename().c_str()), size4);
        }
        for (int k = 0; k < count_ciz; k++)
        {
            ciz_data = (*mas_ciz)[k].Getciz_data();
            wf.write((char *)&ciz_data, sizeof(ciz_data));
            size_t size5 = (*mas_ciz)[k].Getciz_name().length();
            wf.write((char *)&size5, sizeof(size5));
            wf.write((char *)((*mas_ciz)[k].Getciz_name().c_str()), size5);
        }
    }
    wf.close();
    /// Удаление массива цехов
    delete[] mas_shop;
    return 0;
}
