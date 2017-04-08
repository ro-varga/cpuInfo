/**
    CPU Information, processor.h
    Purpose: Header for the Processor class used to get the CPU information from "/proc/cpuinfo"

    @author R. Varga
    @version 1.0 03/04/17
*/

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QObject>

class Processor : public QObject
{
    Q_OBJECT
public:
    // contructor
    explicit Processor(void);

    /**
        Gather the information from the "/proc/cpuinfo" file

        @param none.
        @return TRUE if successful
    */
    bool getInfo(void);


    /**
        Get one item containing the processor id, attribute and value (call before the getInfo() function)

        @param index the index of the item in the list
        @return QPair<int, QPair <QString, QString>> the corresponding item
    */
    QPair<int, QPair <QString, QString>> getItem(int idx) const { return m_list.value(idx); }


    /**
        Get number of items of the list (call before the getInfo() function)

        @param none.
        @return int the size of the list
    */
    int getNrOfItems(void) const { return m_list.size(); }


    /**
        Get the number of processors (call before the getInfo() function)

        @param none.
        @return number of processors
    */
    int getNrOfProcessors() const { return m_nrOfProc; }


signals:

public slots:

private:
    int m_nrOfProc;
    QList<QPair<int, QPair <QString, QString>>> m_list;

};

#endif // PROCESSOR_H
