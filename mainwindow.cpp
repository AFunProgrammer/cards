#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDrag>
#include <QFile>
#include <QLabel>
#include <QPushButton>
#include <QPainter>

#include "utility.h"
#include "ccarddeck.h"
#include "qdrawcards.h"

using namespace std;
int iCurrentCard = 0;

MainWindow* pGlobal = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    pGlobal = this;
    ui->setupUi(this);

    drawCards.setGeometry(0,0,500,500);
    drawCards.setParent(ui->centralwidget);
    drawCards.raise();
    drawCards.show();

    setPlayersCards();
}

void MainWindow::setPlayersCards()
{
    QList<UnoCard> cards;

    m_cardDeck.ReShuffle();
    m_cardDeck.Shuffle(7);

    for( int iPlayer = 0; iPlayer < 4; iPlayer++ )
    {
        m_cardDeck.Draw(&cards,7);
        drawCards.SetPlayerCards(iPlayer, cards);
        m_cardDeck.Return(cards);
        cards.clear();
    }
}


void MainWindow::resizeEvent(QResizeEvent*)
{
#if defined(Q_OS_ANDROID)
    int iWidth = this->screen()->availableGeometry().width();
    int iHeight = this->screen()->availableGeometry().height();
    this->setGeometry(QRect(0,0,iWidth,iHeight));
#else
    int iWidth = this->window()->childrenRect().width();
    int iHeight = this->window()->childrenRect().height();
#endif

    drawCards.setGeometry(QRect(0,0,iWidth,iHeight));
}


MainWindow::~MainWindow()
{
    delete ui;
}

