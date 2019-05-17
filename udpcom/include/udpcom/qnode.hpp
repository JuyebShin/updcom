/**
 * @file /include/udpcom/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef udpcom_QNODE_HPP_
#define udpcom_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>

#include "robocupVision_msg.h"
#include "udp_order.h"
#include "udp_gamecase.h"
#include "master2udp.h"
#include "udp2master.h"



/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace udpcom {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	void run();

        ros::Subscriber caseSub;
        ros::Publisher order_pub;
        int gamecase = 0;
        double myballdt = 0.0;


Q_SIGNALS:
        void rosShutdown();
        void getballdt();

private:
	int init_argc;
	char** init_argv;

        QStringListModel logging_model;
        void caseCallback(const udpcom::master2udp::ConstPtr& msg);
};

}  // namespace udpcom

#endif /* udpcom_QNODE_HPP_ */
