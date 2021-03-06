#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "corkboardscene.h"
#include "noteproxywidget.h"

NoteProxyWidget::NoteProxyWidget(QGraphicsItem* parent,
                                 Qt::WindowFlags wFlags)
    : QGraphicsProxyWidget(parent, wFlags),
      note(new Note),
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
    setZValue(2);
    offset = event->pos();
    pinPressed = pinArea->contains(mapToItem(pinArea, offset));
    QGraphicsProxyWidget::mousePressEvent(event);
}

void NoteProxyWidget::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    auto pos = mapToScene(event->pos() - offset);
    if (pinPressed) {
        if (scene()->sceneRect().contains(pos)) {
            setPos(pos);
        }
        else {
            if (pos.x() < 0) pos.rx() = 0;
            if (pos.y() < 0) pos.ry() = 0;
            setPos(pos);
        }
    }
    QGraphicsProxyWidget::mousePressEvent(event);
}

void NoteProxyWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{    
    setZValue(0);

    auto cbScene = dynamic_cast<CorkboardScene*>(scene());
    if (cbScene) {
        auto garbageArea = cbScene->garbageBinArea();
        auto mappedToGarbageArea =
                mapToScene(event->pos()) - garbageArea.topLeft();

        garbageArea.moveTopLeft(QPointF(0, 0));
        if (garbageArea.contains(mappedToGarbageArea))
            cbScene->removeItem(this);

    }
    QGraphicsProxyWidget::mouseReleaseEvent(event);
}
