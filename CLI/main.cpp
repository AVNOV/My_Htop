/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : nicolas.dayot@ynov.com
** File description : main function Htop_Sender
*/

#include "Headers/MonitorsInfo.hpp"
#include "Interface/IMonitorModule.hpp"
#include "Graphical/SfmlGest.hpp"
#include <string.h>
#include <ostream>

void eventHandling(sf::Event event, sf::Window &window, SfmlGest &sfml);

int htopSendEngine()
{
    MonitorsInfo *info;

    if (!(info = new MonitorsInfo()))
        return (-1);

    SfmlGest sfml;
    sfml.window.setVerticalSyncEnabled(true);
    sfml.window.setFramerateLimit(30);
    while (sfml.window.isOpen()) {
        sf::Event event;
        sfml.window.clear(sf::Color::Blue);
        eventHandling(event, sfml.window, sfml);
        sfml.display(info->_hostname);
        sfml.display(info->_network);
        sfml.display(info->_dateTimeM);
        sfml.display(info->_oS);
        sfml.display(info->_ram);
        sfml.display();
        sfml.window.display();
    }

    return 0;
}

int main(int ac, char *av[]) {
    if (ac >= 2 || (ac == 2 && !(strncmp(av[1], "-h", 2)))) {
        std::cerr << "USAGE:\n\n\tOnly execute :\t./HtopSender" << std::endl;
        return (-1);
    }
    return (htopSendEngine());
}