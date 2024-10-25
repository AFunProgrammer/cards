#ifndef QIMAGEBOX_H
#define QIMAGEBOX_H

#pragma once
#include <QLabel>
#include <QMouseEvent>

#include <stdlib.h>
#include <iostream>

#include "cunocard.h"

union TaggedData
{
    TaggedData() : _string(){}

    TaggedData(const TaggedData& CopyClass) : _string()
    {
        if ( sizeof(CopyClass._string) > sizeof(CopyClass._pixmap) )
            memcpy((void*)&_string, (void*)&(CopyClass._string), sizeof(_string));
        else
            memcpy((void*)&_pixmap, (void*)&(CopyClass._pixmap), sizeof(_pixmap));
    }

    TaggedData(const QString& CopyClass) : _string()
    {
        _string = CopyClass;
    }

    TaggedData(const QPixmap& CopyClass) : _string()
    {
        _pixmap = CopyClass;
    }

    TaggedData* operator= (QString &RHS)
    {
        _string = RHS;
        return this;
    }

    TaggedData* operator= (QPixmap &RHS)
    {
        _pixmap = RHS;
        return this;
    }


    ~TaggedData(){}
    QString _string;
    QPixmap _pixmap;
};


class QImageBox : public QLabel
{

private:
    bool m_bAutoSize = false;
    TaggedData m_Tag;
    CUnoCard m_Card;
    QPoint dragStartPosition;

public:
    QImageBox(const QPixmap &pixmap, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    QImageBox(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    QImageBox(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    bool AutoSize();
    void setAutoSize(bool autosize);

    TaggedData Tag();
    void setTag(QString);
    void setTag(QPixmap);
    void setTag(CUnoCard);

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void dragMoveEvent(QDragMoveEvent* event);
    void dragLeaveEvent(QDragLeaveEvent* event);
    void dropEvent(QDropEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

    void resizeEvent(QResizeEvent*);
};

#endif // QIMAGEBOX_H
