/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com & nicolas.dayot@ynov.com
** File description : CpuModule header
*/

#include "../Headers/DateTimeModule.hpp"
#include <ctime>
#include <iostream>

DateTimeModule::DateTimeModule()
: CoreModule("Date and Time", Type::DATE)
{
}

DateTimeModule::~DateTimeModule()
{
}

void DateTimeModule::updateData(void)
{
    time_t tmm = time(0);
    tm *ltm = localtime(&tmm);

    _dateAndTime[0] = (std::to_string( 1900 + ltm->tm_year));
    _dateAndTime[1] = (std::to_string(1 + ltm->tm_mon));
    _dateAndTime[2] = (this->_month[ltm->tm_mon]); // mois en lettre;
    _dateAndTime[3] = (std::to_string(1 + ltm->tm_mday));
    _dateAndTime[4] = (std::to_string(ltm->tm_hour));
    _dateAndTime[5] = (std::to_string(ltm->tm_min ));
    _dateAndTime[6] = (std::to_string(ltm->tm_sec ));
}

std::string DateTimeModule::getData(DateTimeModule::dataType type)
{
    updateData();
    return (_dateAndTime[type]);
}

void DateTimeModule::printData(std::string binaryCode) const
{
    size_t i = 0;

    while (i != 7) {
        if (binaryCode[i] && binaryCode[i] == '1')
            std::cout << _dateAndTime[i] << std::endl;
        i += 1;
    }
}
