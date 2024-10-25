#ifndef CPLAYER_H
#define CPLAYER_H

#pragma once

#include <QObject>
#include <QString>
#include <QList>

#include "cfacecard.h"

#if !defined(signals)
#define signals //nop
#endif

class CPlayer : public QObject
{
    Q_OBJECT
public:
    explicit CPlayer(QObject *parent = nullptr);

    void GiveCards();

private:
    QString m_Name;
    QList<CCard> m_Cards;



signals:

};

#endif // CPLAYER_H
