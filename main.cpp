/**
    CPU Information, main.cpp
    Purpose: The main source code

    @author R. Varga
    @version 1.0 03/04/17
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlcontext.h>

#include "tblModel.h"

int main(int argc, char *argv[])
{
    // The application and engine
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Register the table model and set root context property
    qmlRegisterType<TblModel>("TblModel", 1, 0, "TblModel");
    TblModel model;
    engine.rootContext()->setContextProperty("theModel", &model);

    // Load qml file
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Run application
    return app.exec();
}
