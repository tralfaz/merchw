#include <QFile>
#include <QIODevice>
#include <QObject>
#include <QTextStream>
#include <QWidget>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])

{
QGuiApplication app(argc, argv);

// Load file to QString
QString filePath = QString("/proc/cpuinfo");
//QString filePath = QString("/Users/mdm/Cpuinfo.txt");
if ( argc > 1 ) {
    filePath = QString(argv[1]);
}

QString cpuInfoText = QString("");
QFile* cpuInfoFIle = new QFile(filePath);
if ( cpuInfoFIle->open(QIODevice::ReadOnly) )
    {
    QTextStream cpuInfoIS(cpuInfoFIle);
    cpuInfoText = cpuInfoIS.readAll();
    cpuInfoFIle->close();
    }
else
    {
    cpuInfoText = "Failed to open" + filePath;
    }
delete cpuInfoFIle;
printf("CpuInfo Text %s\n", cpuInfoText.toStdString().c_str());

QQmlApplicationEngine engine;
engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

// Get Root Widget of QML Scene
QList<QObject*> topChildren = engine.rootObjects();
printf("rootObjs count = %d\n", topChildren.length());
if ( topChildren.length() < 1 )
    {
    printf("Failed to find top level objects\n");
    return -1;
    }
QObject& rootWGT = *topChildren[0];

// Find target text object and set its text property
QObject *qmlOBJ = rootWGT.findChild<QObject*>("cpuInfoText");
printf("qmlOBJ = %p\n", qmlOBJ);
if ( qmlOBJ )
    {/// Found object, set property
    QString cpuInfoHtml = QString("<PRE>") + cpuInfoText + QString("</PRE>");
    qmlOBJ->setProperty("text", cpuInfoHtml);
    }

return app.exec();
}
