#ifndef NOTEPROXYWIDGET_H
#define NOTEPROXYWIDGET_H

#include <QGraphicsProxyWidget>

#include "note.h"

class NoteProxyWidget : public QGraphicsProxyWidget
{
    Q_OBJECT

public:
    NoteProxyWidget(QGraphicsItem* parent = nullptr,
                    Note* note = new Note,
                    Qt::WindowFlags wFlags = 0);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    Note* note;
    QGraphicsRectItem* pinArea;

    QPointF offset = QPointF();
    bool pinPressed = false;
};

#endif // NOTEPROXYWIDGET_H
