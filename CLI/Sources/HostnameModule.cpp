/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : nicolas.dayot@ynov.com
** File description : HostnameModule sources
*/

#include <iostream>
#include <unistd.h>
#include <sys/utsname.h>
#include <ncurses.h>
#include "../Headers/HostnameModule.hpp"

HostnameModule::HostnameModule()
        : CoreModule("Hostname/Username", Type::Module::HOSTNAME)
{
    this->getInfo();
}

HostnameModule::HostnameModule(const std::string &title)
        : CoreModule(title, Type::Module::HOSTNAME)
{
    this->getInfo();
}

void HostnameModule::getInfo(void)
{
    struct utsname data;

    uname(&data);
    this->_data.insert({"Hostname", data.nodename});
    this->_data.insert({"Username", getlogin()});
}

std::string HostnameModule::getHostname(void)
{
    struct utsname data;

    uname(&data);
    return (data.nodename);
}

std::string HostnameModule::getUsername(void)
{
    struct utsname data;

    uname(&data);
    return (getlogin());
}