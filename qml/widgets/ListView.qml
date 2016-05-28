/*
 * Copyright (c) 2015-2016 WinT 3794 <http://wint3794.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

import QtQuick 2.0
import "../globals.js" as Globals

Rectangle {
    property alias list: view
    property alias model: view.model
    property alias delegate: view.delegate

    border.width: Globals.scale (1)
    color: Globals.Colors.WindowBackground
    border.color: Globals.Colors.WidgetBorder

    MouseArea {
        id: mouse
        anchors.fill: parent
    }

    Flickable {
        id: flick
        clip: true
        interactive: true
        contentWidth: parent.width
        contentHeight: view.contentHeight
        flickableDirection: Flickable.VerticalFlick

        anchors {
            fill: parent
            margins: Globals.scale (5)
            rightMargin: Globals.scale (16)
        }

        ListView {
            id: view
            anchors.fill: parent
        }
    }

    Scrollbar {
        id: scroll
        mouseArea: mouse
        scrollArea: flick
        height: parent.height
        width: Globals.scale (8)

        anchors {
            top: parent.top
            right: parent.right
            bottom: parent.bottom
            margins: Globals.scale (6)
        }
    }

    Behavior on width {
        NumberAnimation {
            duration: Globals.slowAnimation
        }
    }

    Behavior on height {
        NumberAnimation {
            duration: Globals.slowAnimation
        }
    }
}
