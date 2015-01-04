#include <QGraphicsSceneMouseEvent>

#include "noteproxywidget.h"

NoteProxyWidget::NoteProxyWidget(QGraphicsItem* parent,
                                 Note* note,
                                 Qt::WindowFlags wFlags)
    : QGraphicsProxyWidget(parent, wFlags),
      note(note),
      pinArea(new QGraphicsRectItem(
                  QRectF(QPointF(113, 0),
                         QPointF(151, 50)),
                  this))
{
    pinArea->setPen(Qt::NoPen);
    setWidget(note);
}

void NoteProxyWidget::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    offset = event->pos();
    pinPressed = pinArea->contains(mapToItem(pinArea, offset));
    QGraphicsProxyWidget::mousePressEvent(event);
}

void NoteProxyWidget::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (pinPressed)
        setPos(mapToParent(event->pos() - offset));
    QGraphicsProxyWidget::mouseMoveEvent(event);
}
