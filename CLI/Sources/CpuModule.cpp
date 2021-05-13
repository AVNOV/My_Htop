/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com & nicolas.dayot@ynov.com
** File description : CpuModule header
*/

#include "../Headers/CpuModule.hpp"
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

CpuModule::CpuModule()
: CoreClockedModule("CPU Module", 1000, Type::Module::CPU)
{

}

static std::string get_activity_percent(float max, float used)
{
    std::stringstream strm;
    float temp;

    max *= 1000;
    temp = ((used / max) * 100);
    if (temp > 100)
        temp = 100;
    strm << std::fixed << std::setprecision(2) << temp << " %";
    return (strm.str());
}

void CpuModule::getInfo(void)
{
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    std::string temp;
    std::string info;
    std::string max;
    std::string activity;
    std::size_t base = 0;
    std::string id;
    std::string frequency;

    while (getline(file,line)) {
        std::stringstream str(line);
        if (line.substr(0,10) == "model name") {
            getline(str, temp, ':');
            getline(str, info);
            auto f = info.find_first_of('@', 0);
            max = info.substr(f+1).c_str();
            _modele = info;
        }
        if (line.substr(0, 9) == "processor") {
            getline(str, temp, ':');
            getline(str, info);
            id = info.substr(1);
            base++;
        }
        if (line.substr(0, 7) == "cpu MHz") {
            getline(str, temp, ':');
            getline(str, info);
            frequency = info.substr(1);
            base++;
        }
        if (base == 2) {
            activity = get_activity_percent(atof(max.c_str()), atof(frequency.c_str()));
            std::vector<std::string> elem;
            elem.push_back(id);
            elem.push_back(frequency);
            elem.push_back(activity);
            this->data.push_back(elem);
            base = 0;
        }
    }
}

std::vector<std::vector<std::string>> CpuModule::getData(void) const
{
    return this->data;
}

std::string const &CpuModule::getModel(void) const
{
    return this->_modele;
}