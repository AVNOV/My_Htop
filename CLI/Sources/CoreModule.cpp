/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com
** File description : CoreModule treatment
*/

#include "../Headers/CoreModule.hpp"

CoreModule::CoreModule(const std::string &title, Type::Module type)
    : _title(title), _type(type)
{
}

std::string const &CoreModule::getModuleTitle() const
{
    return (this->_title);
}

Type::Module CoreModule::getType(void) const
{
    return (this->_type);
}

std::string CoreModule::getValueByKey(std::string const &key) const
{
    Type::core_data_t::const_iterator got = this->_data.find(key);

    if (got == this->_data.end()) {
        return std::string("Error");
    } else {
        return got->second;
    }
}
