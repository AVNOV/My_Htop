/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : nicolas.dayot@ynov.com
** File description : main function Htop_Sender
*/

#include <iostream>
#include <sys/sysinfo.h>
#include <cmath>
#include <fstream>
#include "../Headers/RamModule.hpp"

RamModule::RamModule(void)
        : CoreClockedModule("Ram", 1000, Type::Module::RAM)
{
    this->getInfo();
}

void RamModule::getInfo(void)
{
    struct sysinfo info;
    long long totalVirtualMem;
    long long virtualMemUsed;
    long long virtualMemFree __attribute__((unused));
    std::string totalMem = "";
    std::string freeMem = "";
    std::ifstream fs;
    fs.open("/proc/meminfo");

    if (!fs)
        throw ("error");
    std::getline(fs, totalMem);
    std::getline(fs, freeMem);
    this->_freeRam = freeMem;
    this->_totalRam = totalMem;
    fs.close();
    sysinfo(&info);

    totalVirtualMem = info.totalram;
    totalVirtualMem *= info.mem_unit;
    virtualMemUsed = info.totalram - info.freeram;
    virtualMemUsed *= info.mem_unit;

    totalVirtualMem = totalVirtualMem / std::pow(1024, 2);
    virtualMemFree = totalVirtualMem - virtualMemUsed / std::pow(1024, 2);
    this->_data.insert({"Total", totalMem});
    this->_data.insert({"Free", freeMem});

}

std::string RamModule::getFreeRam(void) const
{
    return (_freeRam);
}


std::string RamModule::getTotalRam(void) const
{
    return (_totalRam);
}

Type::core_data_t RamModule::getData() const
{
    return this->_data;
}

std::string RamModule::getValueByKey(std::string const &key) const
{
    Type::core_data_t::const_iterator got = this->_data.find(key);

    if (got == this->_data.end()) {
        return std::string("Error");
    } else {
        return got->second;
    }
}
