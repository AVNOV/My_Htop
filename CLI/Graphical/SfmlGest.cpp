/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com
** File description : SFML MODULE & WINDOW SOURCES
*/

#include <iostream>
#include <SFML/Graphics.hpp> 
#include "./GUI.hpp"
#include "SfmlGest.hpp"
#include "../Headers/HostnameModule.hpp"
#include "../Headers/CoreModule.hpp"
#include <exception>

sf::RectangleShape rectangleCreation(sf::Vector2u pos, sf::Vector2f size, float outlineThickness, sf::Color color)
{
    sf::RectangleShape rect;
 
    rect.setPosition(pos.x, pos.y);
    rect.setSize(size);
    rect.setOutlineThickness(outlineThickness);
    rect.setOutlineColor(color);
    rect.setFillColor(sf::Color::Black);

    return (rect);
}

void SfmlGest::initHostname(void)
{
    _hostName = createText("Hostname : ", 10, sf::Color::White);
    _userName = createText("User name : ", 10, sf::Color::White);
    _titleHostname = createText("Name :", 14, sf::Color::White);
    _titleHostname.setPosition({100, 12});
    _hostName.setPosition({30, 30});
    _userName.setPosition({30, 70});
    _hostModuleRectangle = rectangleCreation({20, 10}, {200, 100}, 3, sf::Color::White);
}

void SfmlGest::initNetwork(void)
{
    _rxbytes = createText("rxBytes ", 10, sf::Color::White);
    _txbytes = createText("txBytes : ", 10, sf::Color::White);
    _txPackets = createText("txPackets : ", 10, sf::Color::White);
    _rxPackets = createText("rxPackets : ", 10, sf::Color::White);
    _titleNetwork = createText("Network :", 14, sf::Color::White);
    _titleNetwork.setPosition({550, 12});
    _rxbytes.setPosition({500, 30});
    _txbytes.setPosition({500, 60});
    _txPackets.setPosition({500, 90});
    _rxPackets.setPosition({500, 120});
    _networkRectangle = rectangleCreation({490, 10}, {200, 150}, 3, sf::Color::White);
}

SfmlGest::SfmlGest(/* args */)
{
    window.create(sf::VideoMode(800, 600), "My GkRellM");
    sf::Vector2u windowSize = {1920, 1080}; // Recuperer la taille de l'écran !!!!
    window.setPosition({0, 0});
    window.setSize(windowSize);

    if (!_font.loadFromFile("./Font/Roboto-Regular.ttf"))
        throw ("Error font");

    // Hostname ============= 
    initHostname();
    // Network ===============
    initNetwork();

    // DateTime =============
    _dayMonthYear = createText("", 10, sf::Color::White);
    _dayMonthYear.setPosition({310, 30});
    _titleDate = createText("Date :", 14, sf::Color::White);
    _titleDate.setPosition({330, 12});
    _Hours = createText("", 10, sf::Color::White);
    _Hours.setPosition({310, 70});
    _dateTimeRectangle = rectangleCreation({300, 10}, {100, 100}, 3, sf::Color::White);

    // Os ========================
    _osName = createText("", 10, sf::Color::White);
    _kernelVersion = createText("", 10, sf::Color::White);
    _titleOs = createText("Os :", 14, sf::Color::White);
    _titleOs.setPosition({100, 127});
    _osName.setPosition({30, 150});
    _kernelVersion.setPosition({30, 180});
    _osModuleRectangle = rectangleCreation({20, 120}, {200, 100}, 3, sf::Color::White);

    // RAM ========================
    _maxRam = createText("", 10, sf::Color::White);
    _freeRam = createText("", 10, sf::Color::White);
    _titleRam = createText("Ram :", 14, sf::Color::White);
    _titleRam.setPosition({100, 234});
    _maxRam.setPosition({30, 260});
    _freeRam.setPosition({30, 290});
    _ramRectangle = rectangleCreation({20, 230}, {200, 100}, 3, sf::Color::White);

    //init vector text

    _usage = createText("Usage :\nTouch to active or desactive Module : \nN for Network\nO for Os\nH for Hostname\nD for Date\nR for Ram\nEchap for left", 10, sf::Color::White);
    _usage.setPosition({400, 200});

}

sf::Text SfmlGest::createText(std::string text, unsigned int size, sf::Color color)
{
    sf::Text newText;
    newText.setFont(_font);
    newText.setString(text);
    newText.setCharacterSize(size);
    newText.setFillColor(color);
    return (newText);
}

// ===============Display Ram

void SfmlGest::display(RamModule &module)
{
    if (!isDisplayRam)
        return;
    module.getInfo();
    _maxRam.setString(module.getTotalRam());
    _freeRam.setString(module.getFreeRam());
    this->window.draw(_ramRectangle);
    this->window.draw(_maxRam);
    this->window.draw(_freeRam);
    window.draw(_titleRam);
}
// =================== end display ram


// ========= Display Hostname

void SfmlGest::display(HostnameModule &module)
{
    if (!isDisplayHostname)
        return;
    _hostName.setString("Hostname : " + module.getHostname());
    _userName.setString("User name : " + module.getUsername());
    this->window.draw(_hostModuleRectangle);
    this->window.draw(_hostName);
    this->window.draw(_userName);
    window.draw(_titleHostname);
}
// =================== end display Hostname


// ==================== Display Os

void SfmlGest::display(OsModule &module)
{
    if (!isDisplayOs)
        return;
    _osName.setString("Os name : " + module.getOsName());
    _kernelVersion.setString("Kernel Vesrion : " + module.getKernelVersion());
    this->window.draw(_osModuleRectangle);
    this->window.draw(_osName);
    this->window.draw(_kernelVersion);
    this->window.draw(_titleOs);
}

// =================== end display

//=================== Display Date and time

void SfmlGest::display(DateTimeModule &module)
{
    if (!isDisplayDateTime)
        return;
    _dayMonthYear.setString(module.getData(module.DAY) + " " + module.getData(module.MONTHSTR) + " " + module.getData(module.YEARS));
    _Hours.setString(module.getData(module.HOURS) + "H" + module.getData(module.MINUTES) + "m" + module.getData(module.SECONDES));
    this->window.draw(_dateTimeRectangle);
    this->window.draw(_dayMonthYear);
    this->window.draw(_Hours);
    window.draw(_titleDate);
}

//end date and time

//==================Display Network

void SfmlGest::display(NetworkModule &network)
{
    if (!isDisplayNetwork)
        return;
    network.getInfo();
    _rxPackets.setString("Rx packets  : " + network.getRxPacket());
    _txPackets.setString("Tx packets  : " + network.getTxPacket());
    _rxbytes.setString("Rx Bytes :  " + network.getRxBytes());
    _txbytes.setString("Tx Bytes :  " + network.getTxBytes());
    _titleNetwork.setString(network.getName());
    window.draw(_networkRectangle);
    window.draw(_txPackets);
    window.draw(_rxPackets);
    window.draw(_txbytes);
    window.draw(_rxbytes);
    window.draw(_titleNetwork);
}

void SfmlGest::display(void)
{
    window.draw(_usage);
}

// ================= End display network

void eventHandling(sf::Event event, sf::Window &window, SfmlGest &sfml)
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
            window.close();
        if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::N))
            sfml.isDisplayNetwork = !sfml.isDisplayNetwork;

        if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D))
            sfml.isDisplayDateTime = !sfml.isDisplayDateTime;

        if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::O))
            sfml.isDisplayOs = !sfml.isDisplayOs;

        if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::H))
            sfml.isDisplayHostname = !sfml.isDisplayHostname;

        if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R))
            sfml.isDisplayRam = !sfml.isDisplayRam;

        // if (event.type == sf::Event::MouseButtonReleased)

    }
}
