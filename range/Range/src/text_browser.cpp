/*********************************************************************
 *  AUTHOR: Tomas Soltys                                             *
 *  FILE:   text_browser.cpp                                         *
 *  GROUP:  Range                                                    *
 *  TYPE:   source file (*.cpp)                                      *
 *  DATE:   27-th August 2013                                        *
 *                                                                   *
 *  DESCRIPTION: Text browser class definition                       *
 *********************************************************************/

#include "text_browser.h"

TextBrowser::TextBrowser(QWidget *parent) :
    QTextBrowser(parent)
{
    QFont font("Monospace");
    font.setStyleHint(QFont::TypeWriter);
    this->setFont(font);

    QIcon clearIcon(":/icons/file/pixmaps/range-clear.svg");

    this->clearButton = new QPushButton(clearIcon,"Clear",this);

    QObject::connect(this->clearButton,
                     &QPushButton::clicked,
                     this,
                     &TextBrowser::clear);
}

void TextBrowser::resizeEvent(QResizeEvent *event)
{
    QTextBrowser::resizeEvent(event);

    int bw = this->clearButton->width();
    int bh = this->clearButton->height();
    int tw = this->width();
//    int th = this->height();

    int x = tw - bw - 25;
    int y = 5;

    this->clearButton->setGeometry(x,y,bw,bh);
}