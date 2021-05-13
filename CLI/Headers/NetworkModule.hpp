/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : nicolas.dayot@ynov.com
** File description : NetworkModule Header
*/

#ifndef NETWORKMODULE_HPP_
#define NETWORKMODULE_HPP_

#include <memory>
#include "CoreClockedModule.hpp"

class NetworkModule : public CoreClockedModule {
    public:
        NetworkModule();
        ~NetworkModule();

        void getInfo();
        class NetworkInterface {
            public:
                NetworkInterface(std::string, int, int, int, int);
                ~NetworkInterface() = default;
                void dumpData() const;
                std::string _name;
                long _tx;
                long _tx_bytes;
                long _rx;
                long _rx_bytes;
        };
        std::vector<NetworkInterface> getData() const;
        std::string getTxPacket() const;
        std::string getRxPacket() const;
        std::string getTxBytes() const;
        std::string getRxBytes() const;
        std::string getName() const;
        void setTxPacket(long);
        void setRxPacket(long);
        void setTxBytes(long);
        void setRxBytes(long);

	protected:
	private:
        long _tx;
        long _tx_bytes;
        long _rx;
        long _rx_bytes;
        std::string name;
        const std::string _title;
        std::vector<NetworkModule::NetworkInterface> _network;
        struct ifaddrs *_ifaddr;
};

typedef std::shared_ptr<NetworkModule> NetworkModulePtr;

#endif /* !NETWORKMODULE_HPP_ */
