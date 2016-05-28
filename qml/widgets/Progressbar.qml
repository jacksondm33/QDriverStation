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
    property int value: 0
    property int minimumValue: 0
    property int maximumValue: 100
    property string text: value + "%"
    property string barColor: Globals.Colors.HighlightColor
    property string textColor: Globals.Colors.TextAreaForeground

    height: Globals.scale (18)
    border.width: Globals.scale (1)
    color: Globals.Colors.WindowBackground
    border.color: Globals.Colors.WidgetBorder

    Behavior on value {
        NumberAnimation {
            duration: Globals.slowAnimation
        }
    }

    Rectangle {
        y: 0
        x: 0
        color: barColor
        radius: parent.radius
        height: parent.height
        border.width: parent.border.width
        border.color: parent.border.color
        width: parent.width * ((minimumValue + value) / maximumValue)
    }

    Label {
        text: parent.text
        anchors.centerIn: parent
        opacity: font.pixelSize > Globals.scale (8)
        font.pixelSize: Math.min (Globals.scale (12), parent.height * (2/3))
    }
}
