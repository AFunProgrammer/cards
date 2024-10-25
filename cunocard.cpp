#pragma once
#include "cunocard.h"
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QFile>
#include <iostream>

UnoCard unocards[] =
{
    { eUnoCard::GreenZero,              eUnoCardColour::Green,   eUnoCardFace::Zero,                QString("GreenZero")},
    { eUnoCard::GreenOne,               eUnoCardColour::Green,   eUnoCardFace::One,                 QString("GreenOne")},
    { eUnoCard::GreenTwo,               eUnoCardColour::Green,   eUnoCardFace::Two,                 QString("GreenTwo")},
    { eUnoCard::GreenThree,             eUnoCardColour::Green,   eUnoCardFace::Three,               QString("GreenThree")},
    { eUnoCard::GreenFour,              eUnoCardColour::Green,   eUnoCardFace::Four,                QString("GreenFour")},
    { eUnoCard::GreenFive,              eUnoCardColour::Green,   eUnoCardFace::Five,                QString("GreenFive")},
    { eUnoCard::GreenSix,               eUnoCardColour::Green,   eUnoCardFace::Six,                 QString("GreenSix")},
    { eUnoCard::GreenSeven,             eUnoCardColour::Green,   eUnoCardFace::Seven,               QString("GreenSeven")},
    { eUnoCard::GreenEight,             eUnoCardColour::Green,   eUnoCardFace::Eight,               QString("GreenEight")},
    { eUnoCard::GreenNine,              eUnoCardColour::Green,   eUnoCardFace::Nine,                QString("GreenNine")},
    { eUnoCard::GreenDrawTwo,           eUnoCardColour::Green,   eUnoCardFace::DrawTwo,             QString("GreenDrawTwo")},
    { eUnoCard::GreenSkip,              eUnoCardColour::Green,   eUnoCardFace::Skip,                QString("GreenSkip")},
    { eUnoCard::GreenReverse,           eUnoCardColour::Green,   eUnoCardFace::Reverse,             QString("GreenReverse")},
    { eUnoCard::BlueZero,               eUnoCardColour::Blue,    eUnoCardFace::Zero,                QString("BlueZero")},
    { eUnoCard::BlueOne,                eUnoCardColour::Blue,    eUnoCardFace::One,                 QString("BlueOne")},
    { eUnoCard::BlueTwo,                eUnoCardColour::Blue,    eUnoCardFace::Two,                 QString("BlueTwo")},
    { eUnoCard::BlueThree,              eUnoCardColour::Blue,    eUnoCardFace::Three,               QString("BlueThree")},
    { eUnoCard::BlueFour,               eUnoCardColour::Blue,    eUnoCardFace::Four,                QString("BlueFour")},
    { eUnoCard::BlueFive,               eUnoCardColour::Blue,    eUnoCardFace::Five,                QString("BlueFive")},
    { eUnoCard::BlueSix,                eUnoCardColour::Blue,    eUnoCardFace::Six,                 QString("BlueSix")},
    { eUnoCard::BlueSeven,              eUnoCardColour::Blue,    eUnoCardFace::Seven,               QString("BlueSeven")},
    { eUnoCard::BlueEight,              eUnoCardColour::Blue,    eUnoCardFace::Eight,               QString("BlueEight")},
    { eUnoCard::BlueNine,               eUnoCardColour::Blue,    eUnoCardFace::Nine,                QString("BlueNine")},
    { eUnoCard::BlueDrawTwo,            eUnoCardColour::Blue,    eUnoCardFace::DrawTwo,             QString("BlueDrawTwo")},
    { eUnoCard::BlueSkip,               eUnoCardColour::Blue,    eUnoCardFace::Skip,                QString("BlueSkip")},
    { eUnoCard::BlueReverse,            eUnoCardColour::Blue,    eUnoCardFace::Reverse,             QString("BlueReverse")},
    { eUnoCard::RedZero,                eUnoCardColour::Red,     eUnoCardFace::Zero,                QString("RedZero")},
    { eUnoCard::RedOne,                 eUnoCardColour::Red,     eUnoCardFace::One,                 QString("RedOne")},
    { eUnoCard::RedTwo,                 eUnoCardColour::Red,     eUnoCardFace::Two,                 QString("RedTwo")},
    { eUnoCard::RedThree,               eUnoCardColour::Red,     eUnoCardFace::Three,               QString("RedThree")},
    { eUnoCard::RedFour,                eUnoCardColour::Red,     eUnoCardFace::Four,                QString("RedFour")},
    { eUnoCard::RedFive,                eUnoCardColour::Red,     eUnoCardFace::Five,                QString("RedFive")},
    { eUnoCard::RedSix,                 eUnoCardColour::Red,     eUnoCardFace::Six,                 QString("RedSix")},
    { eUnoCard::RedSeven,               eUnoCardColour::Red,     eUnoCardFace::Seven,               QString("RedSeven")},
    { eUnoCard::RedEight,               eUnoCardColour::Red,     eUnoCardFace::Eight,               QString("RedEight")},
    { eUnoCard::RedNine,                eUnoCardColour::Red,     eUnoCardFace::Nine,                QString("RedNine")},
    { eUnoCard::RedDrawTwo,             eUnoCardColour::Red,     eUnoCardFace::DrawTwo,             QString("RedDrawTwo")},
    { eUnoCard::RedSkip,                eUnoCardColour::Red,     eUnoCardFace::Skip,                QString("RedSkip")},
    { eUnoCard::RedReverse,             eUnoCardColour::Red,     eUnoCardFace::Reverse,             QString("RedReverse")},
    { eUnoCard::YellowZero,             eUnoCardColour::Yellow,  eUnoCardFace::Zero,                QString("YellowZero")},
    { eUnoCard::YellowOne,              eUnoCardColour::Yellow,  eUnoCardFace::One,                 QString("YellowOne")},
    { eUnoCard::YellowTwo,              eUnoCardColour::Yellow,  eUnoCardFace::Two,                 QString("YellowTwo")},
    { eUnoCard::YellowThree,            eUnoCardColour::Yellow,  eUnoCardFace::Three,               QString("YellowThree")},
    { eUnoCard::YellowFour,             eUnoCardColour::Yellow,  eUnoCardFace::Four,                QString("YellowFour")},
    { eUnoCard::YellowFive,             eUnoCardColour::Yellow,  eUnoCardFace::Five,                QString("YellowFive")},
    { eUnoCard::YellowSix,              eUnoCardColour::Yellow,  eUnoCardFace::Six,                 QString("YellowSix")},
    { eUnoCard::YellowSeven,            eUnoCardColour::Yellow,  eUnoCardFace::Seven,               QString("YellowSeven")},
    { eUnoCard::YellowEight,            eUnoCardColour::Yellow,  eUnoCardFace::Eight,               QString("YellowEight")},
    { eUnoCard::YellowNine,             eUnoCardColour::Yellow,  eUnoCardFace::Nine,                QString("YellowNine")},
    { eUnoCard::YellowDrawTwo,          eUnoCardColour::Yellow,  eUnoCardFace::DrawTwo,             QString("YellowDrawTwo")},
    { eUnoCard::YellowSkip,             eUnoCardColour::Yellow,  eUnoCardFace::Skip,                QString("YellowSkip")},
    { eUnoCard::YellowReverse,          eUnoCardColour::Yellow,  eUnoCardFace::Reverse,             QString("YellowReverse")},
    { eUnoCard::WildWild,               eUnoCardColour::Wild,    eUnoCardFace::Wild,                QString("Wild")},
    { eUnoCard::WildDrawFour,           eUnoCardColour::Wild,    eUnoCardFace::DrawFour,            QString("WildDrawFour")},
    { eUnoCard::BackBack,               eUnoCardColour::Back,    eUnoCardFace::Back,                QString("Back")},
    { eUnoCard::Blank,                  eUnoCardColour::None,    eUnoCardFace::None,                QString("None")}
};


UnoCard UnoCard::operator= (UnoCard RHS)
{
    this->_colour = RHS._colour;
    this->_face = RHS._face;
    this->_id = RHS._id;
    this->_name = RHS._name;
    this->_pImage = new QPixmap(*RHS._pImage);

    return *this;
}

QVector<UnoCard> UnoCard::SetupCards()
{
    QVector<UnoCard> arrayOfCards;

    int iCardArraySize = sizeof(unocards)/sizeof(UnoCard);
    //QString filename("C:\\temp\\cards\\unodeck.svg");
    QString filename("C:\\temp\\projects\\cards\\unodeck.svg");

    if ( !QFile::exists(filename) )
        qFatal("Missing Uno Cards File");

    QImage* qimGeneratedCard = new QImage(242,362,QImage::Format::Format_ARGB32);
    QPainter renderSVG(qimGeneratedCard);
    QSvgRenderer svgRenderer;

    svgRenderer.load(filename);

    for( int iCard = 0; iCard < iCardArraySize; iCard++ )
    {
        //clear for rendering
        qimGeneratedCard->fill(Qt::transparent);
        renderSVG.setBackgroundMode(Qt::TransparentMode);
        //render each card beautifully and crisply
        svgRenderer.render(&renderSVG, unocards[iCard]._name);

        //get each uno card image
        QPixmap pixmap = QPixmap::fromImage(*qimGeneratedCard,Qt::NoFormatConversion);
        unocards[iCard]._pImage = new QPixmap(pixmap.copy());

        //append card to list
        arrayOfCards.append(unocards[iCard]);
    }

    return arrayOfCards;
}
