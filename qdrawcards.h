#ifndef QDRAWCARDS_H
#define QDRAWCARDS_H

#pragma once
#include <QOpenGLWidget>

#include "cunocard.h"


typedef struct CardDrawRect
{
    CardDrawRect(){}
    CardDrawRect(UnoCard* pCard, QRect drawRect) : m_pUnoCard(pCard), m_drawRect(drawRect)
    {
    }

    CardDrawRect(UnoCard* pCard, QRect drawRect, int Player, int Card) :
        m_Player(Player), m_Card(Card), m_pUnoCard(pCard), m_drawRect(drawRect)
    {
    }

    int m_Player = -1;
    int m_Card = -1;
    UnoCard* m_pUnoCard = nullptr;
    QRect m_drawRect;
}TCardDrawRect,*PCardDrawRect;

class QDrawCards : public QOpenGLWidget
{
public:
    QDrawCards();

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent*) override;
    void leaveEvent(QEvent* event) override;


    void drawCards(QPainter*,QRect);

    void setCardBackFace(QPixmap* BackFace);
    void setClearColor(QColor ClearColor);

    void SetPlayerCards(int Player, QList<UnoCard>);

    QList<CardDrawRect> m_LastDraw;

    int m_SelectedPlayer = -1;
    int m_SelectedCard = -1;
    int m_SelectedDraw = -1;
    bool m_bSelectionChange = false;

    bool m_bSelectionUpdateable = true;

    /*
     * SetPlayerCards(PlayerNumber,Cards);
     * SetLastCardDiscardedForDiscardPile(); Showing face up
     * SetBackFaceCardForDrawPile(CardFace);
     *
     * SetExtraFeaturesColors
     *
     * SetPlayerPictures/Icons(OnEvent?)
     *
     * SetPlayerEmotionsEtc(OnEvent)
     *
     *
     *signal
     * OnPlayCard (for Emotions/Reactions)
     * OnDrawCard (for Emotions/Reactions)
     * OnUno (forEmotions/Reactions)
     */
private:
    QList<QList<UnoCard>> m_PlayersCards;

    QPixmap* m_pixBackFace;
    QColor m_ClearColor = Qt::black;

public:
    signals:


};

#endif // QDRAWCARDS_H
