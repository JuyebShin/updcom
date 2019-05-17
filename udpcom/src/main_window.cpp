/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <QUdpSocket>
#include "../include/udpcom/main_window.hpp"
#include "../include/udpcom/udp_order.h"
#include "../include/udpcom/udp_balldt.h"


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace udpcom {

using namespace Qt;

QHostAddress ARRIBAL_IP = QHostAddress("192.168.0.5");
/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
    MainWindow::ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    qnode.init();

    m_pUdpSocket = new QUdpSocket(this);
    ipAddressesList = QNetworkInterface::allAddresses();
    initAddrAndPort();

    if(m_pUdpSocket->bind(m_iPort_read , QUdpSocket::ShareAddress))
        connect(m_pUdpSocket, SIGNAL(readyRead()), this, SLOT(readData()));

    ChangeSendAddress(QHostAddress("192.168.7.134"));

    QObject::connect(&qnode, SIGNAL(getballdt()), this, SLOT(BallDt_callback()));
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

}

void MainWindow::BallDt_callback()
{
    my_gamecase = qnode.gamecase;
    my_balldt = qnode.myballdt;

    if(my_balldt >= 200000)
        my_balldt = 200000;

    sendData();
}


void MainWindow::ChangeSendAddress(QHostAddress Address)
{
    ARRIBAL_IP = Address;
}

void MainWindow::initAddrAndPort()
{
    m_qstrIp = QHostAddress::LocalHost;

    if(!ipAddressesList.isEmpty())
    {
        for(int i = 0 ; i < ipAddressesList.size() ; i ++)
        {
            QStringList ipList = ipAddressesList[i].toString().split(".") ;
            if(ipList[0] == "192" && ipList[1] == "168")
            {
                m_qstrIp = ipAddressesList.at(i).toString();
                break;
            }
        }
    }

    ui.IP_Line->setText(m_qstrIp);
    ui.PORT_Line->setText(QString::number(m_iPort_read));
    ui.PORT_Line_2->setText(QString::number(m_iPort_write));
}



void MainWindow::readData()
{
    QHostAddress senderAddress;
    quint16 senderPort;

    QByteArray Buffer;
    Buffer.resize(m_pUdpSocket->pendingDatagramSize());

    m_pUdpSocket->readDatagram(Buffer.data(),Buffer.size(),&senderAddress,&senderPort);
//    qDebug() << "From : "<<senderAddress.toString();
//    qDebug() << "Port : "<<senderPort;
//    qDebug() << "Message : "<<Buffer;

    char* RxData = Buffer.data();

    udpcom::udp2master order_msg;
    order_msg.yourcase = RxData[0];
    order_msg.yourballdt = (RxData[2]<<8);
    order_msg.yourballdt += RxData[1];

//    std::cout<<"Rx_gamecase   ====   "<<Rx_gamecase<<std::endl;

    ui.textEdit_READ->append(QString::number(order_msg.yourcase));
    ui.textEdit_READ->append(QString::number(order_msg.yourballdt));

    qnode.order_pub.publish(order_msg);
    Buffer.clear();
}

void MainWindow::sendData()
{
    QByteArray Data;

    Data.push_back(my_gamecase);
    Data.push_back((int)(my_balldt) & 0x00ff);
    Data.push_back((int)(my_balldt) >> 8);
//    Data.push_back(balldt & 0x00ff);
//    Data.push_back(balldt >> 8);
    m_pUdpSocket->writeDatagram(Data.data(),Data.size(),ARRIBAL_IP, m_iPort_write);
    ui.textEdit_SEND->append(QString::number(my_gamecase));
    ui.textEdit_SEND->append(QString::number((int)(my_balldt)));
}

void MainWindow::closeSocket()
{
    ui.IP_Line->setEnabled(true);
    ui.PORT_Line->setEnabled(true);

    disconnect(m_pUdpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    ui.textEdit_READ->clear();
    ui.textEdit_SEND->clear();

    m_pUdpSocket->close();

    m_bIsServerOpen = false;
}

MainWindow::~MainWindow()
{
    closeSocket();
    delete &ui;
    delete m_pUdpSocket;
}


/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/



}  // namespace udpcom

