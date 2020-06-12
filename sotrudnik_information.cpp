    /*****************************************************************/ /**
    * \file   sotrudnik_information.cpp
    * \brief  
    * 
    * \author PeshinaA (Пешина Анастасия)
    * \date   May 2020
    *         
    *         Исходный файл с функциями для работы с информацией о цехах и перегрузка операторов ввода/вывода
    *           
    *         
    *********************************************************************/
    #include "sotrudnik_information.h"
    #include <cstring>
    #include <string>
    #include <cstdio>
    using namespace std;

    /**
     * Конструктор для создания объекта класса и инициализации полей класса sotrudnik_information
     * Имя Фамилия Отчество
     */
    sotrudnik_information::sotrudnik_information()
    {
        name = "";
        surname = "";
        middle_name = "";
    }
    /**
     * Конструктор для создания объекта класса и инициализации полей класса sotrudnik_information
     * Имя Фамилия Отчество
     */
    sotrudnik_information::sotrudnik_information(string name_1, string surname_1, string middlename_1)
    {
        name = name_1;
        surname = surname_1;
        middle_name = middlename_1;
    }
    /**
     * Перегрузка операторов ввода/вывода
     */
    ostream &operator<<(ostream &out, const sotrudnik_information &obj)
    {
        out << "name: " << obj.name << endl;
        out << "surname: " << obj.surname << endl;
        out << "middle name: " << obj.middle_name << endl;
        out << "------------------------------------------------------------" << endl;
        return out;
    }
    istream &operator>>(istream &in, sotrudnik_information &obj)
    {
        in >> obj.name;
        in >> obj.surname;
        in >> obj.middle_name;
        return in;
    }