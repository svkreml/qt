#include <QGraphicsPixmapItem>

#include "corkboardscene.h"

CorkboardScene::CorkboardScene(QObject* parent)
    : QGraphicsScene(parent),
      notePack(new NotePackItem(
                      QPixmap(":/textures/notePack.jpg")
                      .scaled(80, 80, Qt::KeepAspectRatio))
               ),
      picturePack(new PicturePackItem(
                      QPixmap(":/textures/picturePack.jpg")
                      .scaled(80, 80, Qt::KeepAspectRatio))
                  )
{
    addItem(notePack);
    addItem(picturePack);
    connect(this, &CorkboardScene::sceneRectChanged, this, &CorkboardScene::align);
}

void CorkboardScene::align()
{
    static const auto margin = 10;
    static const auto margins = QPointF(margin, margin);

    auto bottomRight = sceneRect().bottomRight();

    auto notePackPos =
            bottomRight - margins -
            notePack->boundingRect().bottomRight();

    auto picturePackPos =
            notePackPos - QPointF(0, margin) -
            picturePack->boundingRect().bottomLeft();

    notePack->setPos(notePackPos);
    picturePack->setPos(picturePackPos);
}
