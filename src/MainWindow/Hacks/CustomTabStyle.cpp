/*
 * Copyright (c) 2015 WinT 3794 <http://wint3794.org>
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

#include "CustomTabStyle.h"

//=============================================================================
// CustomTabStyle::CustomTabStyle
//=============================================================================

CustomTabStyle::CustomTabStyle()
{
    setBaseStyle (QStyleFactory::create ("Fusion"));
}

//=============================================================================
// CustomTabStyle::sizeFromContents
//=============================================================================

QSize CustomTabStyle::sizeFromContents (ContentsType type,
                                        const QStyleOption* option,
                                        const QSize& size,
                                        const QWidget* widget) const
{
    QSize _size = QProxyStyle::sizeFromContents (type, option, size, widget);

    if (type == QStyle::CT_TabBarTab)
        _size = QSize (DPI_SCALE (42), DPI_SCALE (36));

    return _size;
}

//=============================================================================
// CustomTabStyle::drawControl
//=============================================================================

void CustomTabStyle::drawControl (ControlElement element,
                                  const QStyleOption* option,
                                  QPainter* painter,
                                  const QWidget* widget) const
{
    if (element == CE_TabBarTabLabel)
        {
            if (const QStyleOptionTab* tab = qstyleoption_cast <const QStyleOptionTab*>
                                             (option))
                {
                    QStyleOptionTab opt (*tab);
                    opt.shape = QTabBar::RoundedNorth;
                    QProxyStyle::drawControl (element, &opt, painter, widget);
                    return;
                }
        }

    QProxyStyle::drawControl (element, option, painter, widget);
}
