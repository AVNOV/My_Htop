/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** CoreClockedModule.cpp
*/

#include "../Headers/CoreClockedModule.hpp"

CoreClockedModule::CoreClockedModule()
        : _title("")
{
    this->_refreshRate = 1000;
    this->_type = Type::Module::RAM;
}

CoreClockedModule::CoreClockedModule(std::string const &title,
        unsigned long refreshRate, Type::Module type)
        : _title(title), _type(type), _refreshRate(refreshRate)
{
}

Type::Module CoreClockedModule::getType(void) const
{
    return this->_type;
}

std::string const &CoreClockedModule::getModuleTitle() const
{
    return this->_title;
}

unsigned long CoreClockedModule::getRefreshRate() const
{
    return this->_refreshRate;
}

void CoreClockedModule::setRefreshRate(unsigned long refreshRate)
{
    this->_refreshRate = refreshRate;
}

// Type::core_clocked_data_t CoreClockedModule::getClockedData() const
// {
//     return (this->_data);
// }