#include "ccarddeck.h"
#include "qdebug.h"

CCardDeck::CCardDeck(QObject *parent)
    : QObject{parent}
{
    SetupDeck();
}

void CCardDeck::SetupUnoDeck()
{
    QList<UnoCard> unoCards = UnoCard::SetupCards().toList();

    m_BackFace = *(unoCards[unoCards.count()-2]._pImage);

    //need 1-9,skip,draw,reverse again
    for ( UnoCard &card: unoCards )
    {
        switch ( card._face )
        {
        case eUnoCardFace::Zero:
            m_Deck.append(card);
            break;
        case eUnoCardFace::One:
        case eUnoCardFace::Two:
        case eUnoCardFace::Three:
        case eUnoCardFace::Four:
        case eUnoCardFace::Five:
        case eUnoCardFace::Six:
        case eUnoCardFace::Seven:
        case eUnoCardFace::Eight:
        case eUnoCardFace::Nine:
        case eUnoCardFace::Reverse:
        case eUnoCardFace::Skip:
        case eUnoCardFace::DrawTwo:
            m_Deck.append(card);
            m_Deck.append(card);
            break;
        case eUnoCardFace::Wild:
        case eUnoCardFace::DrawFour:
            m_Deck.append(card);
            m_Deck.append(card);
            m_Deck.append(card);
            m_Deck.append(card);
            break;
        default:
            qt_noop(); //not necessary but qt complains about unhandled cases hahahaha
        }
    }

    qDebug() << "Cards In Uno Deck:\n";

    for( UnoCard &card: m_Deck )
    {
        qDebug() << card._name;
    }
}

void CCardDeck::SetupDeck()
{
    //Uno consists of essentially 2 decks of the same cards
    SetupUnoDeck();
}

void CCardDeck::ReShuffle()
{
    m_Deck.append(m_Discard.toList());
    m_Discard.clear();

    Shuffle();

    qDebug() << "CCardDeck::ReShuffle: Cards In Draw Pile" << m_Deck.count();
}

void CCardDeck::Shuffle(int ShuffleTimes)
{
    QList<UnoCard> ShuffledDeck;

    if ( m_Deck.count() < 2 )
        return;

    srand(time(NULL));

    //randomly pick out cards to put in shuffle deck
    for ( int iShuffle = 0; iShuffle < ShuffleTimes; iShuffle++ )
    {
        while ( m_Deck.count() > 0 )
        {
            int iCardIdx = rand() % m_Deck.count();
            ShuffledDeck.append(m_Deck[iCardIdx]);
            m_Deck.removeAt(iCardIdx);
        }

        m_Deck.append(ShuffledDeck);
        ShuffledDeck.clear();
    }
}

int CCardDeck::Count()
{
    return m_Deck.count();
}

int CCardDeck::Drawn()
{
    return m_iDrawn;
}

UnoCard CCardDeck::Draw()
{
    UnoCard card;

    if ( m_Deck.count() > 0 )
    {
        card = m_Deck[0];
        m_Deck.removeFirst();
    }

    m_iDrawn++;

    qDebug() << "CCardDeck::Draw: Cards Left In Draw Pile" << m_Deck.count();

    return card;
}

void CCardDeck::Draw(QList<UnoCard> *List, int Count)
{
    int Draws = Count;

    if (List == 0 || Count == 0 || m_Deck.count() == 0)
        return;

    m_iDrawn += Count;
    if ( Count > m_Deck.count() )
        Draws = m_Deck.count();

    for( int iCard = 0; iCard < Draws; iCard++ )
    {
        (*List).append(Draw());
    }

    qDebug() << "CCardDeck::Draw: Cards Left In Draw Pile" << m_Deck.count();
}

void CCardDeck::Return(UnoCard Card)
{
    m_Discard.append(Card);

    qDebug() << "CCardDeck::Return: Cards In Discard Pile" << m_Discard.count();
}

//When returning a number of cards, assume it's a player leaving the game
// so return them to the bottom of the discard pile (which is the front)
void CCardDeck::Return(QList<UnoCard> Cards)
{
    for(UnoCard &card: Cards)
    {
        m_Discard.push_front(card);
    }

    qDebug() << "CCardDeck::Return: Cards In Discard Pile" << m_Discard.count();
}
