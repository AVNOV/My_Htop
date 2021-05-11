/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : nicolas.dayot@ynov.com
** File description : RamModule header
*/

#ifndef RAMMODULE_HPP_
#define RAMMODULE_HPP_

#include <memory>
#include "CoreClockedModule.hpp"

class RamModule: public CoreClockedModule
{
    public:
        RamModule(void);
        ~RamModule(void) = default;
    
        void getInfo(void);
        std::string getFreeRam() const;
        std::string getTotalRam() const;
        Type::core_data_t getData(void) const;
        std::string getValueByKey(std::string const &) const;
    private:
        Type::core_data_t _data;
        std::string _freeRam;
        std::string _totalRam;
};

typedef std::shared_ptr<RamModule> RamModulePtr;

#endif /* RAMMODULE_HPP_ */
