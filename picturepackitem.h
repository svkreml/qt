#ifndef PICTUREPACKITEM_H
#define PICTUREPACKITEM_H

#include <QGraphicsPixmapItem>

class PicturePackItem : public QGraphicsPixmapItem
{
public:
    PicturePackItem(const QPixmap& pixmap, QGraphicsItem* parent = nullptr);
};

#endif // PICTUREPACKITEM_H
