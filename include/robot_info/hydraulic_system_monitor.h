#pragma once

#include <string>

#include "robot_info_msg/robot_info_10.h"


class HydraulicSystemMonitor
{
public:
    void fill_in_msg(robot_info_msg::robot_info_10 &msg)
    {
        msg.data_06 = "hydraulic_oil_temperature: " + hydraulic_oil_temperature;
        msg.data_07 = "hydraulic_oil_tank_level: " + hydraulic_oil_tank_level;
        msg.data_08 = "hydraulic_oil_pressure: " + hydraulic_oil_pressure;
    }

private:
    // the temperature of the hydraulic oil helps to identify malfunction early and
    // extends the operational time for the oil
    std::string hydraulic_oil_temperature{ "45C" };
    // can help identify any issues before the pump starts to suck in air
    std::string hydraulic_oil_tank_level{ "100%" };
    // Monitoring the pressure is critical to ensure safe operation
    std::string hydraulic_oil_pressure{ "250 bar" };
};
