#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "cpuinfoitem.h"

int main(int argc, char *argv[])

{
QGuiApplication app(argc, argv);

// Create the QML engine and get root context
QQmlApplicationEngine engine;
QQmlContext* rootCtx = engine.rootContext();

// Add our CpuInfoItem to the root QML context
CpuInfoItem cpuInfoItem(rootCtx);
//cpuInfoItem.loadCpuInfo(QString("/Users/mdm/CpuInfo.txt"));
cpuInfoItem.loadCpuInfo(QString("/proc/cpuinfo"));

rootCtx->setContextProperty("CpuInfo", &cpuInfoItem);

// Start the QML engine running
engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

return app.exec();
}
