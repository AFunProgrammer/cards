#include "cunogame.h"

#include <iostream>

CUnoGame::CUnoGame(QObject *parent)
    : QObject{parent}
{

}

void CUnoGame::StartGame()
{

}

void CUnoGame::AddPlayer(CUnoPlayer Player)
{
    bool bPlayerFound = false;

    for( int iPlayer = 0; iPlayer < m_Players.count(); iPlayer++ )
    {
        if ( m_Players[iPlayer].getName().compare(Player.getName(),Qt::CaseInsensitive) == 0 )
        {
            bPlayerFound = true;
            break;
        }
    }

    if ( bPlayerFound )
    {
        std::cout << "Player already in the game" << std::endl;
        return;
    }

    QList<UnoCard> newCards;
    m_UnoDeck.Draw(&newCards,7);
    Player.setCards(newCards);

    m_Players.append(Player);

}

CUnoPlayer CUnoGame::RemovePlayer(QString Name)
{
    CUnoPlayer player;

    for( int iPlayer = 0; iPlayer < m_Players.count(); iPlayer++ )
    {
        if ( m_Players[iPlayer].getName().compare(Name,Qt::CaseInsensitive) == 0 )
        {
            player = m_Players[iPlayer];
            m_Players.removeAt(iPlayer);
            this->m_UnoDeck.Return(player.getCards());
            break;
        }
    }

    return player;
}

void CUnoGame::SubPlayer(CUnoPlayer Player)
{

}


void CUnoGame::Turn()
{

}
