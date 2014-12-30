#include "corkboard.h"

Corkboard::Corkboard(QWidget *parent)
    : Corkboard(nullptr, parent)
{

}

Corkboard::Corkboard(CorkboardScene* scene, QWidget* parent)
    : QGraphicsView(scene, parent)
{
    setBackgroundBrush(QBrush(QImage(":/textures/cork.jpg")));
}

void Corkboard::setScene(CorkboardScene* scene)
{
    QGraphicsView::setScene(scene);
}
