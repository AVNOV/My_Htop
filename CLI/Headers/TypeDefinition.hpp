/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com && lucas.richard@ynov.com
** File description : NetworkModule sources
*/

#ifndef TYPEDEFINITION_HPP_
 #define TYPEDEFINITION_HPP_

#include <string>
#include <unordered_map>

namespace Type {
    typedef enum {
        OS,
        DATE,
        HOSTNAME,
        RAM,
        NETWORK,
        CPU,
        UNKNOWN
    } Module;
    using core_data_t = std::unordered_map<std::string, std::string>;
    using cpu_t = std::unordered_map<std::string, std::string>;
}

#endif /* !TYPEDEFINITION_HPP_ */
