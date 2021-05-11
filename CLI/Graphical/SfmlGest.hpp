/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com
** File description : SFML MODULE & WINDOW HANDLING
*/

#ifndef SFMLGEST_HPP_
#define SFMLGEST_HPP_

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "../Headers/HostnameModule.hpp"
#include "../Headers/NetworkModule.hpp"
#include "../Headers/DateTimeModule.hpp"
#include "../Headers/OsModule.hpp"
#include "../Headers/RamModule.hpp"

class SfmlGest {
    private:
        sf::Font _font;

        // ======== HostName Module ! ========
        sf::Text _hostName;
        sf::Text _userName;
        sf::Text _titleHostname;
        sf::RectangleShape _hostModuleRectangle;
        //========= Os module ! ==============
        sf::Text _kernelVersion;
        sf::Text _osName;
        sf::Text _titleOs;
        sf::RectangleShape _osModuleRectangle;
        // ========== Network Module ! ========
        sf::Text _rxPackets;
        sf::Text _txPackets;
        sf::Text _txbytes;
        sf::Text _rxbytes;
        sf::Text _networkNames;
        sf::Text _titleNetwork;
        sf::RectangleShape _networkRectangle;
        // Date and time Module  ============
        sf::Text _dayMonthYear;
        sf::Text _Hours;
        sf::Text _titleDate;
        sf::RectangleShape _dateTimeRectangle;
        // RAM  ============
        sf::Text _maxRam;
        sf::Text _freeRam;
        sf::Text _titleRam;
        sf::RectangleShape _ramRectangle;

        sf::Text _usage;


        /* data */
    public:
        bool isDisplayHostname = true;
        bool isDisplayOs = true;
        bool isDisplayNetwork = true;
        bool isDisplayDateTime = true;
        bool isDisplayRam = true;
        void initNetwork();
        void initHostname();
        sf::RenderWindow window;
        SfmlGest(/* args */);
        ~SfmlGest() = default;
        sf::Text createText(std::string, unsigned int, sf::Color);
        void display();
        void display(HostnameModule &);
        void display(DateTimeModule &);
        void display(OsModule &);
        void display(RamModule &);
        void display(NetworkModule &network);
};

int startGraphics(void);

#endif /* !SFMLGEST_HPP_ */
