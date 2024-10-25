#include "qdrawcards.h"
#include "qevent.h"
#include "mainwindow.h"

#include <QPainter>

#include <QSet>


inline ulong getCrossProduct(QPoint ptA, QPoint ptB)
{
    float fXProduct = sqrt(((ptA.x() - ptB.x()) * (ptA.x() - ptB.x())) + ((ptA.y() - ptB.y()) * (ptA.y() - ptB.y())));

    return (ulong)fXProduct;
}

QDrawCards::QDrawCards()
{
    this->setMouseTracking(true);
    this->setAttribute(Qt::WA_Hover, true);
}

void QDrawCards::drawCards(QPainter* painter, QRect areaSize)
{
    QPixmap cardPix;
    QString filename;
    QRect cardRect = QRect(0,0,1,1);
    QPen redPen = QPen(Qt::red);

    bool bFirstBegin = true;

    int iMaxCardY = (areaSize.height() - (m_PlayersCards.count()*10)) / m_PlayersCards.count();
    int iMaxCards = 0;
    for(QList player: m_PlayersCards)
    {
        iMaxCards = std::max(static_cast<int>(player.count()),iMaxCards);
    }

    int iMaxCardX = (areaSize.width() * 2) / iMaxCards;

    if ( (iMaxCardX / 2) > (iMaxCardY / 3) )
        iMaxCardX = (iMaxCardY / 3) * 2;
    else
        iMaxCardY = (iMaxCardX / 2) * 3;

    m_LastDraw.clear();

    //for(QList player: m_PlayersCards)
    for( int iPlayer = 0; iPlayer < m_PlayersCards.count(); iPlayer++ )
    {
        //iCard = 0;
        //for(UnoCard card: player)
        for( int iCard = 0; iCard < m_PlayersCards[iPlayer].count(); iCard++ )
        {
            UnoCard* pCard = &m_PlayersCards[iPlayer][iCard];
            cardRect = QRect(iCard*iMaxCardX/2,iPlayer*(iMaxCardY+10),iMaxCardX,iMaxCardY);

            m_LastDraw.append(CardDrawRect(pCard,cardRect,iPlayer,iCard));

            if ( !bFirstBegin )
                painter->begin(this);

            bFirstBegin = false;
            painter->drawPixmap(cardRect,pCard->_pImage->copy().scaled(iMaxCardX,iMaxCardY));

            painter->end();

            //QImage image = card._pImage->toImage();
            //QString format = QString("bpp: ") + std::to_string(image.pixelFormat().bitsPerPixel()).c_str() + " format: " + std::to_string(image.format()).c_str();

            //qDebug() << "Draw Rect: " << cardRect << " card: " << pCard->_name; // << " format: " << format;
            //iCard++;
        }
        //iPlayer++;
    }

    if ( m_SelectedPlayer >= 0 && m_SelectedCard >= 0 )
    {
        UnoCard* pCard = &m_PlayersCards[m_SelectedPlayer][m_SelectedCard];

        painter->begin(this);
        painter->drawPixmap(m_LastDraw[m_SelectedDraw].m_drawRect,pCard->_pImage->copy().scaled(iMaxCardX,iMaxCardY));
        painter->end();
    }

    m_bSelectionUpdateable = true;
}


void QDrawCards::setCardBackFace(QPixmap* BackFace)
{
    if ( BackFace != nullptr )
        m_pixBackFace = BackFace;
}

void QDrawCards::setClearColor(QColor ClearColor)
{
    m_ClearColor = ClearColor;
}

void QDrawCards::SetPlayerCards(int Player, QList<UnoCard> cards)
{
    if ( m_PlayersCards.count() <= Player )
    {
        for ( int create = m_PlayersCards.count(); create <= Player; create++ )
        {
            QList<UnoCard> newPlayer = QList<UnoCard>();
            m_PlayersCards.append(newPlayer);
        }
    }
    else
    {
        m_PlayersCards[Player].clear();
        m_PlayersCards[Player].empty();
    }

    m_PlayersCards[Player].append(cards);
}


void QDrawCards::leaveEvent(QEvent* event)
{
    if ( m_bSelectionUpdateable )
    {
        m_SelectedPlayer = -1;
        m_SelectedCard = -1;
        m_SelectedDraw = -1;
        m_bSelectionUpdateable = false;
        this->repaint();
    }

    qDebug() << "Received: leaveEvent";
}

//On a platform that allows the mouse, or sense touch devices
// that can detect a near touch without physical contact
// this will allow the 'hover' effect to make cards pop-up
// to easily identify selection
void QDrawCards::mouseMoveEvent(QMouseEvent* event)
{
    QPainter qpMeasure(this);
    QPoint clickPos = event->pos();
    QRect clickArea = QRect(0,0,0,0);

    float fDpcmX = (float)qpMeasure.device()->logicalDpiX() / 2.54f;
    float fDpcmY = (float)qpMeasure.device()->logicalDpiY() / 2.54f;

    //Click area is considered the 'nice' area of being clicked in
    // allowing for 'fat' finger touch to select a specific spot
    // within a region and allowing for making mistakes but
    // still having the pleasure of using touch
    clickArea.setX(clickPos.x() - (int)(fDpcmX/2.0f) );
    clickArea.setY(clickPos.y() - (int)(fDpcmY/2.0f) );
    clickArea.setWidth((int)(fDpcmX) );
    clickArea.setHeight((int)(fDpcmY) );

    int hoverCard = -1;

    for( int iCard = 0; iCard < m_LastDraw.count(); iCard++ )
    {
        if ( clickArea.intersects(m_LastDraw[iCard].m_drawRect) )
        {
            qDebug() << "mouseMoveEvent: The Move Intersects: " << m_LastDraw[iCard].m_pUnoCard->_name << " updateable: " << m_bSelectionUpdateable;

            if ( hoverCard != -1 )
            {
                ulong uNewCard = getCrossProduct(m_LastDraw[iCard].m_drawRect.center(), clickPos);
                ulong uCard = getCrossProduct(m_LastDraw[hoverCard].m_drawRect.center(), clickPos);
                if ( uNewCard < uCard )
                    hoverCard = iCard;
            }
            else
               hoverCard = iCard;
        }
    }

    if ( m_bSelectionUpdateable )
    {
        if ( hoverCard >= 0 )
        {
            if ( m_SelectedPlayer >= 0 && m_SelectedCard >= 0 )
            {
                if ( (m_SelectedPlayer != m_LastDraw[hoverCard].m_Player) ||
                     ( m_SelectedCard != m_LastDraw[hoverCard].m_Card ) )
                    m_bSelectionChange = true;
                else
                    m_bSelectionChange = false;
            }

            m_SelectedPlayer =  m_LastDraw[hoverCard].m_Player;
            m_SelectedCard = m_LastDraw[hoverCard].m_Card;
            m_SelectedDraw = hoverCard;
            qDebug() << "Received: mouseMoveEvent: Closest Player:" << m_SelectedPlayer << " Closest Card: " << m_LastDraw[hoverCard].m_pUnoCard->_name;
        }
        else
        {
            if ( m_SelectedPlayer == -1 || m_SelectedCard == -1 )
                m_bSelectionChange = false;
            else
                m_bSelectionChange = true;

            m_SelectedPlayer = -1;
            m_SelectedCard = -1;
            m_SelectedDraw = -1;

            qDebug() << "Received: mouseMoveEvent: No Player No Card";
        }

        if ( m_bSelectionChange )
        {
            m_bSelectionUpdateable = false;
            this->repaint();
        }
    }
}

void QDrawCards::mouseDoubleClickEvent(QMouseEvent*)
{
    pGlobal->setPlayersCards();
    this->repaint();
}



void QDrawCards::mousePressEvent(QMouseEvent *event)
{
    QPainter qpMeasure(this);
    QPoint clickPos = event->pos();
    QRect clickArea = QRect(0,0,0,0);

    float fDpcmX = (float)qpMeasure.device()->logicalDpiX() / 2.54f;
    float fDpcmY = (float)qpMeasure.device()->logicalDpiY() / 2.54f;

    //Click area is considered the 'nice' area of being clicked in
    // allowing for 'fat' finger touch to select a specific spot
    // within a region and allowing for making mistakes but
    // still having the pleasure of using touch
    clickArea.setX(clickPos.x() - (int)(fDpcmX/2.0f) );
    clickArea.setY(clickPos.y() - (int)(fDpcmY/2.0f) );
    clickArea.setWidth((int)(fDpcmX) );
    clickArea.setHeight((int)(fDpcmY) );

    int closestCardToClick = -1;

    for( int iCard = 0; iCard < m_LastDraw.count(); iCard++ )
    {
        if ( clickArea.intersects(m_LastDraw[iCard].m_drawRect) )
        {
            if ( closestCardToClick != -1 )
            {
                ulong uNewCard = getCrossProduct(m_LastDraw[iCard].m_drawRect.center(), clickPos);
                ulong uCard = getCrossProduct(m_LastDraw[closestCardToClick].m_drawRect.center(), clickPos);
                if ( uNewCard < uCard )
                    closestCardToClick = iCard;
            }
            else
               closestCardToClick = iCard;
        }
    }

    if ( closestCardToClick >= 0 )
    {
        UnoCard* pCard = m_LastDraw[closestCardToClick].m_pUnoCard;
        QRect rectDraw = m_LastDraw[closestCardToClick].m_drawRect;

        QPixmap pixCursor = pCard->_pImage->scaled(rectDraw.width()/2,rectDraw.height()/2);

        QCursor cursor = QCursor(pixCursor);
        this->setCursor(cursor);

        //this->setCursor(QCursor(*(m_LastDraw[closestCardToClick].m_pUnoCard->_pImage)));
    }
    else
    {
        QCursor cursor = QCursor(Qt::CursorShape::ArrowCursor);
        this->setCursor(cursor);
    }

}

void QDrawCards::paintEvent(QPaintEvent *event)
{
    QPainter Painter(this);
    QBrush brushBackground = QBrush(m_ClearColor);

    qDebug() << "Received: paintEvent";
    //glEnable(GL_MULTISAMPLE);
    //glEnable(GL_LINE_SMOOTH);
    Painter.setRenderHint(QPainter::Antialiasing);
    Painter.setRenderHint(QPainter::SmoothPixmapTransform);
    Painter.fillRect(event->rect(),brushBackground);

    drawCards(&Painter,event->rect());

    //Painter.end();
}
