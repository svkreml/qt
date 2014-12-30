#ifndef CORKBOARD_H
#define CORKBOARD_H

#include <QGraphicsView>

#include "corkboardscene.h"

class Corkboard : public QGraphicsView
{
    Q_OBJECT

public:
    Corkboard(QWidget* parent = nullptr);
    Corkboard(CorkboardScene* scene, QWidget* parent = nullptr);

    void setScene(CorkboardScene*);
};

#endif // CORKBOARD_H
