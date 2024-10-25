#ifndef CCARDDECK_H
#define CCARDDECK_H

#pragma once

#include <QObject>

//#include "cfacecard.h"
#include "cunocard.h"


class CCardDeck : public QObject
{
    Q_OBJECT

    int m_iDrawn;
    //Deck is the control of the cards
    QVector<UnoCard> m_Deck;
    //Discard pile is returned until a new... [when my brain thinks of it...]
    QVector<UnoCard> m_Discard;

    QPixmap m_BackFace;

    void SetupDeck();

    void SetupUnoDeck();

public:
    explicit CCardDeck(QObject *parent = nullptr);

    void ReShuffle();

    void Shuffle(int ShuffleTimes = 1);

    int Count();
    int Drawn();

    UnoCard Draw();
    void Draw(QList<UnoCard> *List, int Count = 1);

    void Return(UnoCard Card);
    void Return(QList<UnoCard> Cards);

signals:


};

#endif // CCARDDECK_H
