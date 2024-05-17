#include "mainwin.h"

#include <QApplication>
#include <QScreen>
#include <QRect>
#include <windows.h>

#include <iostream>
#include "log4qt/logger.h"
#include "log4qt/basicconfigurator.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    // 打开控制台，查看调试信息
//    AllocConsole();     //打开控制台
//    freopen("CONOUT$", "w", stdout);  // 重定向标准输出和标准错误输出到控制台
//    freopen("CONOUT$", "w", stderr);  // 重定向标准输出和标准错误输出到控制台

    QString str = "你好 QString";
    printf("你好， printf()，%s\n", str.toStdString().c_str());
    printf("你好， printf()，%s\n", str.toUtf8().constData());
    printf("你好， printf()，%s\n", str.toLatin1().constData());
    printf("你好， printf()，%s\n", str.toLocal8Bit().constData());
    std::cout << "hello 你好中国" << std::endl;

//    qDebug() << "你好，01 qDebug()" ;
//    qDebug(str.toUtf8().constData());
//    qDebug(str.toLocal8Bit().constData());
//    qDebug(str.toLatin1().constData());

//    getchar();



//    Log4Qt::BasicConfigurator::configure();
//    Log4Qt::Logger * log = Log4Qt::Logger::rootLogger();
//    log->debug("debug!");
//    log->info("information!");
//    log->warn("warn");

}

int main2(int argc, char *argv[])
{
    system("chcp 65001");
    std::cout << "hello 你好中国" << std::endl;
    // 打开控制台，查看调试信息
//    AllocConsole();     //打开控制台
//    freopen("CONOUT$", "w", stdout);  // 重定向标准输出和标准错误输出到控制台
//    freopen("CONOUT$", "w", stderr);  // 重定向标准输出和标准错误输出到控制台

    QApplication a(argc, argv);



    MainWin w;
//    w.setWindowState(Qt::WindowFullScreen);
    w.resize(1024, 768);        // 设备触屏分辨率： 1024*768
    w.setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint);

    // 窗口居中
    QRect sr = a.primaryScreen()->geometry();
    w.move((sr.width() - w.width())/ 2, (sr.height() - w.height()) /2);

    w.show();

    return a.exec();
}
