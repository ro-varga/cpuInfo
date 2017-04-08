/**
    CPU Information, tblModel.cpp
    Purpose: Soruce code for the TableView model

    @author R. Varga
    @version 1.0 03/04/17
*/

#include <QModelIndex>

#include "tblModel.h"

enum Role
{
    AttributeRole = Qt::UserRole,
    ValueRole
};

TblModel::TblModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    // gather the information related to the processors
    processor.getInfo();

    // create the list of items for ONLY one processor (0 by default)
    for (int i = 0; i<processor.getNrOfItems(); i++)
    {
        // get item
        QPair<int, QPair <QString, QString>> t_item = processor.getItem(i);

        // check for the processor's ID
        if (0 == t_item.first)
        {
            // add it to the list
            items.append(new ModelItem(t_item.first,t_item.second.first, t_item.second.second));
        }
    }
}

/**
    Change the data set to the corresponding processor
    Function used to call from QML

    @param id the ID of the processor
    @return void
*/
void TblModel::changeData(int id)
{
    int j = 0;
    for (int i = 0; i<processor.getNrOfItems(); i++)
    {
        // get item
        QPair<int, QPair <QString, QString>> t_item = processor.getItem(i);

        // check for the processor's ID
        if (id == t_item.first)
        {
            // set the data
            setData(index(j, 0), t_item.second.first, AttributeRole);
            setData(index(j, 1), t_item.second.second, ValueRole);
            j++;
        }
    }
}


/**
    Get the number of types
    Function used to call from QML

    @param none.
    @return int the number of rows in the table
*/
int TblModel::nrOfTypes(void)
{
    return processor.getNrOfProcessors();
}

/**
    Get the total number of rows

    @param parent the parent of the model
    @return int the total number of rows
*/
int TblModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return items.count();
}


/**
    Get the total number of columns

    @param parent the parent of the model
    @return int the total number of columns
*/
int TblModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}


/**
    Get the data under the given role for the item referred to by the index

    @param index the index of the item
    @param role the display role
    @return QVariant the corresponding data
*/
QVariant TblModel::data(const QModelIndex &index, int role) const
{
    switch (role)
    {
        case AttributeRole: return items[index.row()]->attribute;
        case ValueRole: return items[index.row()]->value;
    }

    return QVariant();
}


/**
    Get the model's role names

    @param none
    @return QHash<int, QByteArray> the model's role names
*/
QHash<int, QByteArray> TblModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[AttributeRole] = "attribute";
    roles[ValueRole] = "value";

    return roles;
}


/**
    Set the role data for the item at index to value

    @param index the index of the item
    @param value the new value of the item
    @param role the role of the item
    @return true if successful
*/
bool TblModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    // set the data
    switch (role)
    {
        case AttributeRole: items[index.row()]->attribute = value.toString();
        case ValueRole: items[index.row()]->value = value.toString();
    }

    // emit signal that the data was changed
    emit dataChanged(index, index);

    return true;
}




