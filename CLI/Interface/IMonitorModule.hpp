/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com && lucas.richard@ynov.com
** File description : IMonitorModule interface to treat MonitorsInfo Object
*/

class IMonitorModule {
    public:
        virtual ~IMonitorModule(void) = default;

        virtual void sendThroughSocket();
        virtual void serialiseIt();
};