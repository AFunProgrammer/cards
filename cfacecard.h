#ifndef CFACECARD_H
#define CFACECARD_H

#endif // CFACECARD_H

#pragma once

#include <QObject>

#include <QString>
#include <QRect>
#include <QVector>
#include <QPixmap>

enum class eFaceCardSuit
{
    Clovers = 0x0,
    Diamonds,
    Hearts,
    Spades
};

enum class eFaceCardFace
{
    Ace = 0x0,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Joker
};

enum class eFaceCard
{
    AceOfClovers = 0x0,
    TwoOfClovers,
    ThreeOfClovers,
    FourOfClovers,
    FiveOfClovers,
    SixOfClovers,
    SevenOfClovers,
    EightOfClovers,
    NineOfClovers,
    TenOfClovers,
    JackOfClovers,
    QueenOfClovers,
    KingOfClovers,
    AceOfDiamonds,
    TwoOfDiamonds,
    ThreeOfDiamonds,
    FourOfDiamonds,
    FiveOfDiamonds,
    SixOfDiamonds,
    SevenOfDiamonds,
    EightOfDiamonds,
    NineOfDiamonds,
    TenOfDiamonds,
    JackOfDiamonds,
    QueenOfDiamonds,
    KingOfDiamonds,
    AceOfHearts,
    TwoOfHearts,
    ThreeOfHearts,
    FourOfHearts,
    FiveOfHearts,
    SixOfHearts,
    SevenOfHearts,
    EightOfHearts,
    NineOfHearts,
    TenOfHearts,
    JackOfHearts,
    QueenOfHearts,
    KingOfHearts,
    AceOfSpades,
    TwoOfSpades,
    ThreeOfSpades,
    FourOfSpades,
    FiveOfSpades,
    SixOfSpades,
    SevenOfSpades,
    EightOfSpades,
    NineOfSpades,
    TenOfSpades,
    JackOfSpades,
    QueenOfSpades,
    KingOfSpades,
    WhiteCard,
    BackFace
};

typedef struct FaceCard
{
public:
    eFaceCard _id;
    QString _suit = "";
    QString _face = "";
    QRect _loc;
    QPixmap* _pImage;

    FaceCard(eFaceCard id, QString suit, QString face, QRect loc )
    {
        SetupCard(id, suit, face, loc);
    }

    FaceCard(eFaceCard id, QString suit, QString face, QRect loc, QPixmap* pixmap )
    {
        SetupCard(id, suit, face, loc, pixmap);
    }

    ~FaceCard(){}

    static QVector<FaceCard> SetupCards();

private:
    void SetupCard(eFaceCard id = eFaceCard::BackFace, QString suit = "", QString face = "", QRect loc = QRect(0,0,0,0), QPixmap* pixmap = NULL)
    {
        _id = id;
        _suit = suit;
        _face = face;
        _loc = loc;
        if( pixmap != NULL)
            _pImage = new QPixmap(*pixmap);

    }
}CCard,*pCard;

