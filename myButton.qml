/**
    CPU Information, myButton.qml
    Purpose: The button qml for generating

    @author R. Varga
    @version 1.0 03/04/17
*/

import QtQuick 2.4
import QtQuick.Controls 1.4
import TblModel 1.0


Button {
    property int num: 0
    width: 100

    TblModel
    {
        id: myModel
    }

    onClicked: myModel.changeData(num);
}

