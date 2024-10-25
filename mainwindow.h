#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include <QImage>
#include <QTimer>
#include <QVBoxLayout>

#include "qimagebox.h"
#include "ccarddeck.h"
#include "qdrawcards.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mouseButtonDownEvent(QMouseEvent*);
    //void mouseDoubleClickEvent(QMouseEvent*) override;
    //void mouseMoveEvent(QMouseEvent);
    //void dragEnterEvent(QDragEnterEvent* event);
    //void dragMoveEvent(QDragMoveEvent* event);

    void resizeEvent(QResizeEvent* event) override;

    void setPlayersCards();

private:
    Ui::MainWindow *ui;
    QTimer* pTimer;
    CCardDeck m_cardDeck;
    QDrawCards drawCards;
};

extern MainWindow* pGlobal;

#endif // MAINWINDOW_H
