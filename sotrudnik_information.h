/*****************************************************************/ /**
 * \file   sotrudnik_information.h
 * \brief  Класс содержащий информацию о сотрудниках
 * 
 * \author PeshinaA (Пешина Анастасия)
 * \date   May 2020
 *  
 *         Заголовочный файл с классом sotrudnik_information с информацией о сотруднике и
 *         Функции для работы с информацией о сотрудниках
 * 
 *********************************************************************/
#ifndef sotrudnik_information_H
#define sotrudnik_information_H
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
/**
 * Класс, содержащий информацию о сотруднике
 * Имя Фамилия Отчество сотрудника
 */
class sotrudnik_information
{
private:
    /// Имя сотрудника
    std::string name;
    /// Фамилия сотрудника
    std::string surname;
    /// Отчество сотрудника
    std::string middle_name;

public:
    /// функция доступа для получения значения name
    std::string &Getsotrudnik_name()
    {
        return name;
    }
    /// функция доступа для получения значения surname
    std::string &Getsotrudnik_surname()
    {
        return surname;
    }
    /// функция доступа для получения значения middle_name
    std::string &Getsotrudnik_middlename()
    {
        return middle_name;
    }
    /// Объвление конструктора
    sotrudnik_information();
    /// Объявление конструктора
    sotrudnik_information(std::string name_1, std::string surname_1, std::string middlename_1);
    /// Перегрузка операторов ввода и вывода
    friend std::ostream &operator<<(std::ostream &out, const sotrudnik_information &obj);
    friend std::istream &operator>>(std::istream &in, sotrudnik_information &obj);
};
std::ostream &operator<<(std::ostream &out, const sotrudnik_information &obj);
std::istream &operator>>(std::istream &in, sotrudnik_information &obj);
#endif
