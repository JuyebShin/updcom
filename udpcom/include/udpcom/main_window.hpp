/**
 * @file /include/udpcom/main_window.hpp
 *
 * @brief Qt based gui for udpcom.
 *
 * @date November 2010
 **/
#ifndef udpcom_MAIN_WINDOW_H
#define udpcom_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

#include <QtNetwork>
#include <QUdpSocket>
#include <QHostAddress>

#include <iostream>



/*****************************************************************************
** Namespace
*****************************************************************************/

namespace udpcom {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

        void initAddrAndPort();
        void closeSocket();
        void sendData();

        void ChangeSendAddress(QHostAddress Address);

        QList<QHostAddress> ipAddressesList;


public Q_SLOTS:
        void BallDt_callback();
        void readData();

private:
	Ui::MainWindowDesign ui;
	QNode qnode;

        QUdpSocket     *m_pUdpSocket;

        QHostAddress   m_qSrcAddress;
        QHostAddress   m_qDestAddress;

        quint16        m_iPort_write = 1220;
        quint16        m_iPort_read = 9809;
        QString        m_qstrIp;

        bool           m_bIsServerOpen;

        int my_gamecase = 0;
        double my_balldt = 0.0;

        double order = 0.0;


private Q_SLOTS:


};

}  // namespace udpcom

#endif // udpcom_MAIN_WINDOW_H
