#include "qimagebox.h"

#include <QDrag>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QGuiApplication>
#include <QMimeData>

#include "mainwindow.h"

QImageBox::QImageBox(const QPixmap &pixmap, QWidget *parent, Qt::WindowFlags f)
{
    setPixmap(pixmap);
    setParent(parent);
    setWindowFlags(f);
    setAcceptDrops(true);
}

QImageBox::QImageBox(const QString &text, QWidget *parent, Qt::WindowFlags f)
{
    setText(text);
    setParent(parent);
    setWindowFlags(f);
    setAcceptDrops(true);
}

QImageBox::QImageBox(QWidget *parent, Qt::WindowFlags f)
{
    setParent(parent);
    setWindowFlags(f);
    setAcceptDrops(true);
}

bool QImageBox::AutoSize()
{
    return m_bAutoSize;
}

void QImageBox::setAutoSize(bool autosize)
{
    m_bAutoSize = autosize;

    if ( m_bAutoSize == false )
        return;

    if ( this->pixmap().data_ptr() == nullptr )
        return;

    setFrameRect(QRect(0, 0, pixmap().width(), pixmap().height()));
}

TaggedData QImageBox::Tag()
{
    return m_Tag;
}

void QImageBox::setTag(QString string)
{
    m_Tag = string;
}

void QImageBox::setTag(QPixmap pixmap)
{
    m_Tag = pixmap;
}

void QImageBox::setTag(UnoCard card)
{
    m_Card = card;
}


void QImageBox::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        dragStartPosition = event->pos();
}

void QImageBox::mouseReleaseEvent(QMouseEvent*)
{
    //if ( QGuiApplication::)
}

void QImageBox::mouseDoubleClickEvent(QMouseEvent*)
{
    if ( pGlobal == NULL )
        return;

    // Need to find a way to return the card?
    //pGlobal->m_cardDeck.Return(m_Card);

    delete this;
}



void QImageBox::dragEnterEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();
}

void QImageBox::dragMoveEvent(QDragMoveEvent*)
{

}


void QImageBox::dragLeaveEvent(QDragLeaveEvent*)
{
    //event->setAccepted(false);
}

void QImageBox::dropEvent(QDropEvent* event)
{
    //event->acceptProposedAction();
    QImageBox* pSource = (QImageBox*)(event->source());
    QPoint ptSrc = pSource->pos();
    QPoint ptDst = this->pos();
    QRect rctSrc = pSource->geometry();
    QRect rctDst = this->geometry();

    pSource->setGeometry(rctDst);
    pSource->move(ptDst);
    this->setGeometry(rctSrc);
    this->move(ptSrc);
}


void QImageBox::resizeEvent(QResizeEvent*)
{
    if ( parent() == nullptr )
        return;

    //QRect rctLocation = geometry();
    //QPoint ptSize = MainWindow::m_WindowSize;
    // QPoint ptSize = dynamic_cast<MainWindow*>(parent())->m_WindowSize;
    // partial initialization of main window, though windowSize is set
    // returns a Read A/V - have to create a public member instead
    // to deal with odd A/V
    //QPoint ptSize = dynamic_cast<MainWindow*>(parent())->windowSize();

    //this->setGeometry(QRect(rctLocation.x(),rctLocation.y(),ptSize.x()/15,ptSize.y()/6));
}

void QImageBox::mouseMoveEvent(QMouseEvent* event)
{
    if (!(event->buttons() & Qt::LeftButton))
    {
        std::cout << "Exiting Because Left Button Not Down" << std::endl;
        return;
    }
    if ((event->pos() - dragStartPosition).manhattanLength()
         < QPoint(5,5).manhattanLength())
    {
        std::cout << "Exiting because Drag distance isn't far enough" << std::endl;
        return;
    }

    //QVariant var = this->property("pixmap");
    //std::cout << var.toString().toStdString() << std::endl;
    std::cout << "Started Drag Event" << std::endl;

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;

    mimeData->setText("DraggingACard");
    drag->setMimeData(mimeData);
    //drag->setPixmap(this->pixmap());
    drag->setHotSpot(QPoint(this->pixmap().width()/2,this->pixmap().height()/2));
    drag->setDragCursor(this->pixmap(),Qt::LinkAction);

    drag->connect(drag, &QDrag::actionChanged,
                  [this,drag](Qt::DropAction action)
    {
        if ( action != Qt::IgnoreAction )
            drag->setDragCursor(this->pixmap(),Qt::IgnoreAction);
    });


    drag->connect(drag, &QDrag::targetChanged,
                  [](QObject*)
    {
        std::cout << "Target Changed" << std::endl;// To: " << object->objectName().toStdString();
    });

    //The next line of code executes until completed and essentially blocks all other code
    // until finished (check for async operations if they exist too...)
    Qt::DropAction dropAction = drag->exec(Qt::LinkAction);

    qDebug() << dropAction;
}

