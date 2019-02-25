/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/udpcom/qnode.hpp"
#include "../include/udpcom/udp_order.h"
#include "../include/udpcom/udp_balldt.h"


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace udpcom {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"udpcom");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
        // Add your ros communications here.
        order_pub = n.advertise<udpcom::udp2master>("udp_order",100);
        caseSub = n.subscribe("udp_case", 100, &QNode::caseCallback,this);
        std::cout<<"init"<<std::endl;
	start();
	return true;
}

void QNode::run() {
    ros::spin();
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void QNode::caseCallback(const udpcom::master2udp::ConstPtr& msg)
{
    gamecase = msg->gamecase;
    myballdt = msg->ball_dt;
    Q_EMIT getballdt();
}
}
