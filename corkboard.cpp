#include <QResizeEvent>

#include "corkboard.h"

Corkboard::Corkboard(CorkboardScene* scene, QWidget* parent)
    : QGraphicsView(scene, parent),
      scene(scene)
{
    auto image = QImage(":/textures/cork.jpg")
                 .scaled(512, 512,
                         Qt::KeepAspectRatio,
                         Qt::SmoothTransformation);
    setBackgroundBrush(QBrush(image));

    scene->setSceneRect(0, 0, width(), height());
}

void Corkboard::setScene(CorkboardScene* scene)
{
    QGraphicsView::setScene(scene);
}

void Corkboard::resizeEvent(QResizeEvent* event)
{
    QGraphicsView::resizeEvent(event);

    auto newSize = event->size();
    auto sceneRect = scene->sceneRect();

    auto sceneW = newSize.width();
    auto sceneH = newSize.height();

    scene->setSceneRect(sceneRect.x(), sceneRect.y(), sceneW, sceneH);
}
