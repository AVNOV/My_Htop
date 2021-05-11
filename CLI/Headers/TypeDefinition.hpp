/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** TypeDefinition.hpp
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
    // using core_clocked_data_t = std::vector<CoreClo>;
    using cpu_t = std::unordered_map<std::string, std::string>;
}

#endif /* !TYPEDEFINITION_HPP_ */
