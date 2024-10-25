#ifndef UTILITY_H
#define UTILITY_H

#endif // UTILITY_H

#include <iostream>

#include <QDrag>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QGuiApplication>
#include <QMimeData>

void dragEnterEvent(QDragEnterEvent*)
{
    std::cout << "DragEnterEvent Occured On:" <<  " More Info: TBD " << std::endl;
}
