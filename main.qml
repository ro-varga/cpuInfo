/**
    CPU Information, main.qml
    Purpose: The main qml of the application

    @author R. Varga
    @version 1.0 03/04/17
*/

import QtQuick 2.4
import QtQuick.Controls 1.4
import TblModel 1.0


ApplicationWindow {
    id: rootwin
    title: "CPU Information"

    visible: true
    minimumWidth: 1024
    minimumHeight: 768
    maximumWidth: minimumHeight
    maximumHeight: minimumWidth

    // MENUBAR
    menuBar: MenuBar
    {
        Menu
        {
            title: qsTr("File")

            MenuItem
            {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    // CREATE BUTTONS ACCORDING TO THE NR OF PROCESSORS
    Component.onCompleted: rootwin.createButtons();

    TblModel
    {
        id: tModel
    }

    function createButtons()
    {
        var s = tModel.nrOfTypes();
        for (var i = 0; i<s; i++)
        {
            var x = i * 25;
            buttonHolder.createBtn(0, x, i);
        }
    }


    // APPLICATION WINDOWS SPLITED INTO 2: BUTTONS AND TABLE
    Grid
    {
        columns: 2
        spacing: 2


        // BUTTONS
        Rectangle
        {
            id: buttonHolder
            width: 100
            height: 768

            function createBtn(coordX, coordY, num)
            {
                var component = Qt.createComponent("myButton.qml");
                var btn = component.createObject(buttonHolder,{"x":coordX,"y":coordY});
                if(btn != null )
                {
                    btn.text = "Processor " + num;
                    btn.x = coordX;
                    btn.y = coordY;
                    btn.num = num;
                }
            }
        }

        // TABLE
        TableView
        {

            width: 920
            height: 768
            model: theModel

            TableViewColumn {title: "Attribute"; role: "attribute"; width: 170 }
            TableViewColumn {title: "Value"; role: "value"; width: 700   }

        }

    }
}
