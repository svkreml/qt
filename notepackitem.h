#ifndef NOTEPACKITEM_H
#define NOTEPACKITEM_H

#include <QGraphicsPixmapItem>

class NotePackItem : public QGraphicsPixmapItem
{
public:
    NotePackItem(const QPixmap& pixmap, QGraphicsItem* parent = nullptr);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent*);
};

#endif // NOTEPACKITEM_H
