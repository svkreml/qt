#ifndef NOTEPACKITEM_H
#define NOTEPACKITEM_H

#include <QGraphicsPixmapItem>

class NotePackItem : public QGraphicsPixmapItem
{
public:
    NotePackItem(const QPixmap& pixmap, QGraphicsItem* parent = nullptr);
};

#endif // NOTEPACKITEM_H
