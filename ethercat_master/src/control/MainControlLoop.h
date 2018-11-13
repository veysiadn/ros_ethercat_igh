/*
* Add Comment here
*/

#ifndef MAINCONTROLLOOP_H
#define MAINCONTROLLOOP_H

#include <mcx/mcx_core.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "Drive.h"
#include "motorcortex_msgs/MotorcortexInList.h"
#include "motorcortex_msgs/MotorcortexOutList.h"

class MainControlLoop : public mcx::container::Module {
public:

    MainControlLoop() = default;

    ~MainControlLoop() override = default;

    void controlCallback(const motorcortex_msgs::MotorcortexOutList::ConstPtr& command_msg);

private:
    void create_(const char *name, mcx::parameter_server::Parameter *parameter_server, uint64_t dt_micro_s) override;

    bool initPhase1_() override;

    bool initPhase2_() override;

    bool startOp_() override;

    bool stopOp_() override;

    bool iterateOp_(const mcx::container::TaskTime &system_time, mcx::container::UserTime *user_time) override;

    ros::NodeHandle nh_;
    ros::Subscriber sub_;
    ros::Publisher pub_;
    std::array<Drive, 2> drives_;
    motorcortex_msgs::MotorcortexOutList motorcortexOutListMsg_;


};

#endif /* MAINCONTROLLOOP_H */