#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>

#include "corkboardscene.h"
#include "noteproxywidget.h"

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
    notePack->setZValue(1);
    picturePack->setZValue(1);

    connect(this, &CorkboardScene::sceneRectChanged,
            this, &CorkboardScene::align);
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

void CorkboardScene::dragEnterEvent(QGraphicsSceneDragDropEvent* event)
{
    auto mime = event->mimeData();
    if (mime->formats().contains("application/note"))
        event->accept();
}

void CorkboardScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    event->accept();
}

void CorkboardScene::dropEvent(QGraphicsSceneDragDropEvent* event)
{
    auto note = new NoteProxyWidget;
    addItem(note);

    auto notePos = event->scenePos() - QPointF(130, 20);
    if (notePos.x() < 0) notePos.rx() = 0;
    if (notePos.y() < 0) notePos.ry() = 0;
    note->setPos(notePos);
}
