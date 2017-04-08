/**
    CPU Information, modelItem.h
    Purpose: Header for the Model item

    @author R. Varga
    @version 1.0 03/04/17
*/

#ifndef MODELITEM
#define MODELITEM

#include <QString>

struct ModelItem
{
    ModelItem(int id_, QString attribute_, QString value_)
        : id(id_), attribute(attribute_), value(value_) {}
    int id;
    QString attribute;
    QString value;
};

#endif // MODELITEM
