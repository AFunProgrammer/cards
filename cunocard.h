#ifndef CUNOCARD_H
#define CUNOCARD_H
#pragma once
#include <QObject>

#include <QString>
#include <QRect>
#include <QVector>
#include <QPixmap>

#if !defined(STRINGIFY)
#define STRINGIFY(x) #x
#endif

#if !defined(TO_STRING)
#define TO_STRING(x) STRINGIFY(x)
#endif

enum class eUnoCardFace
{
    Zero = 0x0,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    DrawTwo,
    Skip,
    Reverse,
    Wild,
    DrawFour,
    Back,
    None
};

enum class eUnoCardColour
{
    Green = 0x0,
    Blue,
    Red,
    Yellow,
    Wild,
    Back,
    None
};

enum class eUnoCard
{
    GreenZero = 0x0,
    GreenOne,
    GreenTwo,
    GreenThree,
    GreenFour,
    GreenFive,
    GreenSix,
    GreenSeven,
    GreenEight,
    GreenNine,
    GreenDrawTwo,
    GreenSkip,
    GreenReverse,
    BlueZero,
    BlueOne,
    BlueTwo,
    BlueThree,
    BlueFour,
    BlueFive,
    BlueSix,
    BlueSeven,
    BlueEight,
    BlueNine,
    BlueDrawTwo,
    BlueSkip,
    BlueReverse,
    RedZero,
    RedOne,
    RedTwo,
    RedThree,
    RedFour,
    RedFive,
    RedSix,
    RedSeven,
    RedEight,
    RedNine,
    RedDrawTwo,
    RedSkip,
    RedReverse,
    YellowZero,
    YellowOne,
    YellowTwo,
    YellowThree,
    YellowFour,
    YellowFive,
    YellowSix,
    YellowSeven,
    YellowEight,
    YellowNine,
    YellowDrawTwo,
    YellowSkip,
    YellowReverse,
    WildWild,
    WildDrawFour,
    BackBack,
    Blank
};

typedef struct UnoCard
{
public:
    eUnoCard _id;
    eUnoCardColour _colour;
    eUnoCardFace _face;
    QString _name;
    QPixmap* _pImage;

    UnoCard(eUnoCard id = eUnoCard::Blank,
            eUnoCardColour colour = eUnoCardColour::None,
            eUnoCardFace face = eUnoCardFace::None,
            QString name = "none",
            QPixmap* pixmap = nullptr) :
            _id(id),
            _colour(colour),
            _face(face),
            _name(name)
    {
        if ( pixmap != NULL )
            _pImage = new QPixmap(*pixmap);
    }

    ~UnoCard(){}

    UnoCard operator= (UnoCard RHS);

    static QVector<UnoCard> SetupCards();

private:
}CUnoCard,*pUnoCard;

#endif // CUNOCARD_H
