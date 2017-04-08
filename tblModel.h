/**
    CPU Information, tblModel.h
    Purpose: Header for the TableView model

    @author R. Varga
    @version 1.0 03/04/17
*/

#ifndef TBLMODEL_H
#define TBLMODEL_H

#include <QAbstractTableModel>
#include "modelItem.h"
#include "processor.h"

class TblModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    // Constructor
    TblModel (QObject *parent = 0);

    /**
        Change the data set to the corresponding processor
        Function used to call from QML

        @param id the ID of the processor
        @return void
    */
    Q_INVOKABLE void changeData(int id);

    /**
        Get the number of types
        Function used to call from QML

        @param none.
        @return int the number of rows in the table
    */
    Q_INVOKABLE int nrOfTypes(void);

    /**
        Get the total number of rows

        @param parent the parent of the model
        @return int the total number of rows
    */
    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    /**
        Get the total number of columns

        @param parent the parent of the model
        @return int the total number of columns
    */
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    /**
        Get the data under the given role for the item referred to by the index

        @param index the index of the item
        @param role the display role
        @return QVariant the corresponding data
    */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    /**
        Get the model's role names

        @param none
        @return QHash<int, QByteArray> the model's role names
    */
    QHash<int, QByteArray> roleNames(void) const;

    /**
        Set the role data for the item at index to value

        @param index the index of the item
        @param value the new value of the item
        @param role the role of the item
        @return true if successful
    */
    bool setData(const QModelIndex &index, const QVariant &value, int role);

signals:

public slots:

private:
    QList<ModelItem*> items;
    Processor processor;
};

#endif // TBLMODEL_H
