#ifndef CORKBOARD_H
#define CORKBOARD_H

#include <QGraphicsView>

#include "corkboardscene.h"

class Corkboard : public QGraphicsView
{
    Q_OBJECT

public:
    Corkboard(CorkboardScene* scene, QWidget* parent = nullptr);

    void setScene(CorkboardScene*);

protected:
    virtual void resizeEvent(QResizeEvent *event);

private:
    CorkboardScene* scene;
};

#endif // CORKBOARD_H
