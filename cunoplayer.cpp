#include "cunoplayer.h"

const QList<QString> g_FirstNames(
{
    "Richard",
    "Dale",
    "Dave",
    "Aisha",
    "Megan",
    "Megarama",
    "Hercules",
    "Lydia",
    "Dino",
    "Scooby",
    "Capt'n",
    "Emily",
    "Julie",
    "Ashley",
    "Peter",
    "Clarence",
    "Dude",
    "Stephanie",
    "Kimberly",
    "Alice",
    "Kyle",
    "Victoria",
    "Yolanda",
    "Nelson"
});

const QList<QString> g_LastNames(
{
    "Anderson",
    "Smith",
    "Gardner",
    "Potter",
    "Edwards",
    "Baptiste",
    "Sutherland",
    "Stewart",
    "O'Brien",
    "Brinkley"
});

void CUnoPlayer::Start()
{

}

void CUnoPlayer::Play()
{

}

void CUnoPlayer::Draw()
{

}

void CUnoPlayer::Uno()
{

}

void CUnoPlayer::setCards(QList<UnoCard> Cards)
{
    m_Cards.append(Cards);
}


QList<UnoCard> CUnoPlayer::getCards()
{
    return m_Cards;
}


void CUnoPlayer::setName(QString Name)
{
    m_Name = Name;
}

QString CUnoPlayer::getName()
{
    return m_Name;
}
