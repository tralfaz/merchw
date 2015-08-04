#ifndef CPUINFOITEM_H
#define CPUINFOITEM_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QtQml>

class CpuInfoItem : public QObject
{
Q_OBJECT

Q_PROPERTY(int cpuCount READ cpuCount)
Q_PROPERTY(int cpuIndex READ cpuIndex WRITE setCpuIndex NOTIFY cpuIndexChanged)
Q_PROPERTY(QString cpuIndexDetails READ cpuIndexDetails)

Q_INVOKABLE QString cpuDetails(int cpuNum);

public:
    explicit CpuInfoItem(QQmlContext *ctx);

    int cpuCount() const;
    int cpuIndex() const;
    void setCpuIndex(int cpuIndex);
    QString cpuIndexDetails() const;

    int loadCpuInfo(const QString& cpuInfoPath);

signals:
    void cpuIndexChanged();

public slots:

private:
    QQmlContext* m_qmlCtx;
    int m_cpuCount;
    int m_cpuIndex;
    QStringList m_cpuDetails;
};

#endif // CPUINFOITEM_H
