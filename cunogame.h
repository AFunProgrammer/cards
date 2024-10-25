#ifndef CUNOGAME_H
#define CUNOGAME_H

#pragma once
#include <QObject>
#include <QVector>

#include "ccarddeck.h"
#include "cunoplayer.h"

enum class eUnoMove
{
    None = 0x0,
    Play = 0x1,
    Draw = 0x2,
};

enum class eUnoPenalty
{
    None = 0x0,
    DrawTwo = 0x1,
    DrawFour = 0x2,
    Skip = 0x4
};

class CUnoMove : public QObject
{
    Q_OBJECT

    CUnoPlayer m_Player;

    QList<eUnoPenalty> m_Penalties;
    QList<eUnoMove> m_Move;
public:
    CUnoMove(){}

    void AddMove(eUnoMove Move){m_Move.append(Move);}
    void AddPenalty(eUnoPenalty Penalty){m_Penalties.append(Penalty);}
};


class CUnoGame : public QObject
{
    Q_OBJECT

    CCardDeck m_UnoDeck;
    QList<CUnoPlayer> m_Players;
    QList<CUnoMove> m_MoveHistory;

public:
    explicit CUnoGame(QObject *parent = nullptr);

    void StartGame();

    void AddPlayer(CUnoPlayer Player);
    CUnoPlayer RemovePlayer(QString Name);
    void SubPlayer(CUnoPlayer Player);


    void Turn();

signals:

};

#endif // CUNOGAME_H
