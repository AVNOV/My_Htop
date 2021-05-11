/*
** HTOP SOFTWARE YNOV PROJECT, 2021
** Made by : arthur.viard@ynov.com & nicolas.dayot@ynov.com
** File description : DateTimeModule header
*/

#ifndef DATETIMEMODULE_HPP_
#define DATETIMEMODULE_HPP_

#include <memory>
#include <vector>
#include "CoreModule.hpp"

class DateTimeModule : public CoreModule {
public:
        typedef enum {
                YEARS,
                MONTH,
                MONTHSTR,
                DAY,
                HOURS,
                MINUTES,
                SECONDES
        } dataType;
        DateTimeModule();
        ~DateTimeModule();
        // std::vector<std::string> getDatas() const override;
        void updateData();
        std::string getData(dataType);
        void getInfo() override {};
        void printData(std::string) const;
        void getData() {};
protected:
private:
        std::string _dateAndTime[8];
        time_t tmm = time(0);
        char* dt = ctime(&tmm);
        std::string _month[12] = {"January", "February", "March",
                           "April", "May", "Jun", "July",
                           "August", "September", "October",
                           "November", "December"};
};

typedef std::shared_ptr<DateTimeModule> DateTimeModulePtr;

#endif /* !DATETIMEMODULE_HPP_ */