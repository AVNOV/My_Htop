/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : nicolas.dayot@ynov.com
** File description : HostnameModule header
*/

#ifndef HOSTNAMEMODULE_HPP
#define HOSTNAMEMODULE_HPP

#include "CoreModule.hpp"

class HostnameModule: public CoreModule
{
public:
    HostnameModule(void);
    HostnameModule(const std::string &);
    ~HostnameModule(void) = default;
    std::string getHostname();
    std::string getUsername();

    void getInfo();
};

typedef std::shared_ptr<HostnameModule> HostnameModulePtr;

#endif //HOSTNAMEMODULE_HPP
