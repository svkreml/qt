#include <QDrag>
#include <QGraphicsSceneMouseEvent>
#include <QMimeData>

#include "notepackitem.h"
#include "noteproxywidget.h"

NotePackItem::NotePackItem(const QPixmap& pixmap, QGraphicsItem* parent)
    : QGraphicsPixmapItem(pixmap, parent)
{

}

void NotePackItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QDrag* drag = new QDrag(event->widget());
    auto mimeData = new QMimeData;
    mimeData->setData("application/note", QByteArray());
    drag->setMimeData(new QMimeData);
    drag->setPixmap(QPixmap(":/textures/note.png"));
    drag->setHotSpot(QPoint(130, 20));
    drag->exec();
    event->accept();
}
