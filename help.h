/*****************************************************************/ /**
 * \file   help.h
 * \brief  
 * 
 * \author youngh8r(Шамшетдинов Руслан)
 * \date   May 2020
 *         Исходный файл отвечающий за вывод меню
 * 
 *********************************************************************/
#ifndef help_H
#define help_H
#include <iostream>
#define MAX_MENU_NUMBER 9
/**
 * Класс меню
 */
class help
{
public:
    /// Функция вывода меню
    void showmenu();
    /// Функция проверки введенного пользователем значения в меню
    bool isvalid(int ch);
};
#endif