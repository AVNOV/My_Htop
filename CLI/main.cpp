/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : nicolas.dayot@ynov.com
** File description : main function Htop_Sender
*/

#include <iostream>
#include <string.h>

#include <MonitorsInfo.hpp>
#include <IMonitorModule.hpp>

int htopSendEngine()
{
    MonitorsInfo *info;

    if (!(info = new MonitorsInfo()))
        return (-1);
    return 0;
}

int main(int ac, char *av[]) {
    if (ac >= 2 || (ac == 2 && !(strncmp(av[1], "-h", 2)))) {
        std::cerr << "USAGE:\n\n\tOnly execute :\t./Htop_Sender" << std::endl;
        return (-1);
    }
    return (htopSendEngine());
}