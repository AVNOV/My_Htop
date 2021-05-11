/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com && lucas.richard@ynov.com
** File description : NetworkModule sources
*/

#include <iostream>
#include <ifaddrs.h>
#include <linux/if_link.h>
#include <string>
#include "../Headers/NetworkModule.hpp"

NetworkModule::NetworkModule()
: CoreClockedModule("Network", 1000, Type::Module::NETWORK)
{
}

NetworkModule::~NetworkModule()
{
}

NetworkModule::NetworkInterface::NetworkInterface(std::string name, int tx, int tx_bytes, int rx, int rx_bytes)
: _name(name), _tx(tx), _tx_bytes(tx_bytes), _rx(rx), _rx_bytes(rx_bytes)
{
}
void NetworkModule::getInfo()
{
    size_t i = 0;

    if (getifaddrs(&_ifaddr) == -1) {
        return;
    }
    for (auto tmp = _ifaddr; tmp != NULL; tmp = tmp->ifa_next) {
        if (tmp->ifa_addr == NULL)
            continue;
        else if (tmp->ifa_addr->sa_family == AF_PACKET && tmp->ifa_data != NULL) {
            i ++;
            struct rtnl_link_stats *stats = static_cast<struct rtnl_link_stats*>(tmp->ifa_data);
            NetworkInterface netInterface(std::string(tmp->ifa_name), stats->tx_packets, stats->tx_bytes,
                                          stats->rx_packets, stats->rx_bytes);
            if (i == 3) {
            this->name = tmp->ifa_name;
            this->_rx = stats->rx_packets;
            this->_tx = stats->tx_packets;
            this->_rx_bytes = stats->rx_bytes;
            this->_tx_bytes = stats->tx_bytes;
            }
            this->_network.push_back(netInterface);
        }
    }
    freeifaddrs(_ifaddr);
}

void NetworkModule::NetworkInterface::dumpData() const
{
    std::cout << "Name: " << this->_name << std::endl;
    std::cout << "Packet:    tx:" << this->_tx << "       bytes: " << this->_tx_bytes << std::endl;
    std::cout << "           rx:" << this->_rx << "       bytes: " << this->_rx_bytes  << std::endl;
}

std::vector<NetworkModule::NetworkInterface> NetworkModule::getData() const
{
    return this->_network;
}

std::string NetworkModule::getRxBytes(void) const
{
    return (std::to_string(this->_rx_bytes));
}

std::string NetworkModule::getTxBytes(void) const
{
    return (std::to_string(this->_tx_bytes));
}

std::string NetworkModule::getRxPacket(void) const
{
    return (std::to_string(this->_rx));
}

std::string NetworkModule::getTxPacket(void) const
{
    return (std::to_string(this->_tx));
}


void NetworkModule::setRxBytes(long rx)
{
    this->_rx_bytes = rx;
}

void NetworkModule::setTxBytes(long tx)
{
    this->_tx_bytes = tx;
}

void NetworkModule::setRxPacket(long rx)
{
    this->_rx = rx;
}

void NetworkModule::setTxPacket(long tx)
{
    this->_tx = tx;
}

std::string NetworkModule::getName(void) const
{
    return (this->name);
}