/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : nicolas.dayot@ynov.com
** File description : OsModule sources
*/

#include <fstream>
#include <iostream>
#include <sys/utsname.h>
#include "../Headers/OsModule.hpp"

OsModule::OsModule()
: CoreModule(std::string("OS name and Kernel"), Type::OS),
  _osName(""), _kernelVersion("")
{
    this->getInfo();
}

std::string OsModule::getOsName() const
{
    return (this->_osName);
}

std::string OsModule::getKernelVersion() const
{
    return (this->_kernelVersion);
}

void OsModule::dumpDatas() const
{
    std::cout << "OS Name: " << this->_osName << std::endl << "Kernel Version: " << this->_kernelVersion << std::endl;
}

void OsModule::getInfo()
{
    struct utsname uts;

    uname(&uts);
    this->_osName = std::string(uts.sysname);
    this->_kernelVersion = std::string(uts.release);
    this->_data.insert({"OsName", this->_osName});
    this->_data.insert({"KernelVersion", this->_kernelVersion});
}