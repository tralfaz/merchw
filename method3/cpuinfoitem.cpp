#include <QFile>
#include <QTextStream>

#include "cpuinfoitem.h"

CpuInfoItem::CpuInfoItem(QQmlContext* qmlCtx)
{
m_qmlCtx = qmlCtx;
m_cpuCount  = 4;
m_cpuIndex  = 0;
}


int CpuInfoItem::cpuCount() const
{
    return m_cpuCount;
}

int CpuInfoItem::cpuIndex() const
{
    return m_cpuIndex;
}

void CpuInfoItem::setCpuIndex(int cpuIndex)
{
    if ( cpuIndex >= 0 && cpuIndex < m_cpuCount ) {
        m_cpuIndex = cpuIndex;
    }
}


QString CpuInfoItem::cpuIndexDetails() const
{
    //return QString("CPU %1 Details").arg(m_cpuIndex);
    return m_cpuDetails[m_cpuIndex];
}

QString CpuInfoItem::cpuDetails(int cpuNum)
{
    return QString("CPU %1 Details").arg(cpuNum);
}


int CpuInfoItem::loadCpuInfo(const QString& cpuInfoPath)
{
//        QString filePath = QString("/Users/mdm/Cpuinfo.txt");
    int status = 0;
    QString cpuInfoText = QString("");

    QFile* cpuInfoFIle = new QFile(cpuInfoPath);
    if ( cpuInfoFIle->open(QIODevice::ReadOnly) ) {
        QTextStream cpuInfoIS(cpuInfoFIle);
        cpuInfoText = cpuInfoIS.readAll();
        cpuInfoFIle->close();
    } else {
        cpuInfoText = "Failed to open" + cpuInfoPath;
        status = -1;
    }
    delete cpuInfoFIle;

// My Ubuntu VM only has 1 CPU, but possible you could split
// cpuInfoText into per CPU details
QString fakeMultiCPU = QString("CPU 0 Details ...\n") + cpuInfoText + QString("|") +
                       QString("CPU 1 Details ...\n") + cpuInfoText + QString("|") +
                       QString("CPU 2 Details ...\n") + cpuInfoText + QString("|") +
                       QString("CPU 3 Details ...\n") + cpuInfoText;
m_cpuDetails = fakeMultiCPU.split("|");
m_cpuCount = m_cpuDetails.length();
m_cpuIndex = 0;

return status;
}
