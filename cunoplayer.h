#ifndef CUNOPLAYER_H
#define CUNOPLAYER_H

#pragma once
#include <QObject>

#include "cunocard.h"
#include "ccarddeck.h"

class CUnoPlayer : public QObject
{
    Q_OBJECT

    QString m_Name;
    QList<CUnoCard> m_Cards;

    void Start();

public:
    explicit CUnoPlayer(QObject *parent = nullptr, QString Name = "", QList<CUnoCard> Cards = QList<CUnoCard>()) :
        m_Name(Name), m_Cards(Cards)
    {
        setParent(parent);
    }

    CUnoPlayer(const CUnoPlayer &Copy) : m_Name(Copy.m_Name), m_Cards(Copy.m_Cards)
    {
        setParent(Copy.parent());
        setObjectName(Copy.objectName());
    }

    ~CUnoPlayer(){}

    void Play();
    void Draw();
    void Uno();

    void setName(QString Name);
    QString getName();

    void setCards(QList<UnoCard> Cards);
    QList<UnoCard> getCards();


    CUnoPlayer& operator= (const CUnoPlayer &RHS)
    {
        m_Name = RHS.m_Name;
        m_Cards = QList<CUnoCard>(RHS.m_Cards);
        return *this;
    }

    CUnoPlayer* operator= (const CUnoPlayer *RHS)
    {
        m_Name = RHS->m_Name;
        m_Cards = QList<CUnoCard>(RHS->m_Cards);
        return this;
    }

signals:

};

#endif // CUNOPLAYER_H
