/**
    CPU Information, processor.cpp
    Purpose: Soruce code for the Processor class used to get the CPU information from "/proc/cpuinfo"

    @author R. Varga
    @version 1.0 03/04/17
*/

#include <QFile>
#include <QTextStream>
#include <QString>

#include "processor.h"

const QString CPUINFO("/proc/cpuinfo");

Processor::Processor() :
    m_nrOfProc(0)
{
    m_list.clear();
}

/**
    Gather the information from the "/proc/cpuinfo" file

    @param none.
    @return TRUE if successful
*/
bool Processor::getInfo()
{
    bool ret = true;

    // set file
    QFile file(CPUINFO);

    // reset nr of processors and clear list
    m_nrOfProc = 0;
    m_list.clear();

    // read file
    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString line = stream.readLine();

        while (!line.isNull())
        {
            if (!line.isEmpty())
            {
                QString addAttribute;
                QString addValue;

                // process line and create attribute and value
                if (line.contains("processor"))
                {
                    QString pNumber = line.section(' ', 1, 1);
                    m_nrOfProc = pNumber.toInt();
                }

                if (line.contains('\t'))
                {
                    addAttribute = line.section('\t', 0, 0);
                    addValue = line.section(':', 1, 1);
                    addValue = addValue.remove(0, 1);
                }
                else
                {
                    addAttribute = line.remove(':');
                    addValue = "";
                }

                // add information to the list
                m_list.append(qMakePair(m_nrOfProc, qMakePair(addAttribute, addValue)));
            }

            line = stream.readLine();
        }

        m_nrOfProc++;
        file.close();
    }
    else
    {
        // unable to read file
        ret = false;
    }

    return ret;
}

