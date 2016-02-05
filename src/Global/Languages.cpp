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

//=============================================================================
// System includes
//=============================================================================

#include <QLocale>
#include <QTextCodec>
#include <QMessageBox>
#include <QApplication>

//=============================================================================
// Application includes
//=============================================================================

#include "Global.h"
#include "Settings.h"
#include "Languages.h"

//=============================================================================
// Languages::globalVariables
//=============================================================================

QString _fontName;
const QString _defaultFont = "QuickSand";
static QTranslator* _translator = Q_NULLPTR;

//=============================================================================
// Languages::init
//=============================================================================

void Languages::init()
{
    QString locale;
    QTextCodec::setCodecForLocale (QTextCodec::codecForName ("UTF-8"));

    /* Get which translation file and font to open */
    switch (currentLanguage())
        {
        case kAuto:
            _fontName = _defaultFont;
            locale    = systemLanguage();
            break;
        case kGerman:
            locale    = "de";
            _fontName = _defaultFont;
            break;
        case kEnglish:
            locale    = "en";
            _fontName = _defaultFont;
            break;
        case kSpanish:
            locale    = "es";
            _fontName = _defaultFont;
            break;
        case kAurebesh:
            locale    = "en";
            _fontName = "Aurebesh";
            break;
        default:
            locale    = "en";
            _fontName = _defaultFont;
            break;
        }

    /* Load translations */
    translator()->load (":/languages/qds_" + locale);
}

//=============================================================================
// Languages::appFont
//=============================================================================

QFont Languages::appFont()
{
    QFont font;
    font.setFamily (_fontName);
    font.setPixelSize (DPI_SCALE (12));
    return font;
}

//=============================================================================
// Languages::monoFont
//=============================================================================

QFont Languages::monoFont()
{
    QFont font;
    if (appFont().family() != _defaultFont)
        {
            font.setFixedPitch (true);
            font.setFamily     (appFont().family());
            font.setPixelSize  (appFont().pixelSize());
        }

    else
        {
#if defined Q_OS_WIN
            font.setFamily     ("Consolas");
            font.setPixelSize  (DPI_SCALE (12));
#else
            font.setFamily     ("Inconsolata");
            font.setPixelSize  (DPI_SCALE (12));
#endif
        }

    return font;
}

//=============================================================================
// Languages::systemLanguage
//=============================================================================

QString Languages::systemLanguage()
{
    return QLocale::system().name().split ("_").at (0);
}

//=============================================================================
// Languages::getTranslator
//=============================================================================

QTranslator* Languages::translator()
{
    if (_translator == Q_NULLPTR)
        {
            _translator = new QTranslator;
            init();
        }

    return _translator;
}

//=============================================================================
// Languages::currentLanguage
//=============================================================================

Languages::LanguageType Languages::currentLanguage()
{
    return (LanguageType) Settings::get ("Language", kAuto).toInt();
}

//=============================================================================
// Languages::getAvailableLanguages
//=============================================================================

QStringList Languages::getAvailableLanguages()
{
    QStringList list;

    list.append ("Auto");
    list.append ("Aurebesh (Star Wars glyphs)");
    list.append ("Deutsch");
    list.append ("English");
    list.append ("Español");

    return list;
}

//=============================================================================
// Languages::setLanguage
//=============================================================================

void Languages::setLanguage (LanguageType language)
{
    if (language != currentLanguage())
        {
            Settings::set ("Language", language);
            QMessageBox::information (Q_NULLPTR,
                                      QObject::tr ("Change language"),
                                      QObject::tr ("You must restart the application "
                                                   "in order for the changes to take "
                                                   "effect"));
        }
}
