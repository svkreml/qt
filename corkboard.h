#ifndef CORKBOARD_H
#define CORKBOARD_H

#include <vector>

#include <QGraphicsView>

#include "corkboardscene.h"

class Corkboard : public QGraphicsView
{
    Q_OBJECT

public:
    Corkboard(CorkboardScene* scene, QWidget* parent = nullptr);

    void setScene(CorkboardScene*);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    CorkboardScene* scene;
    //std::vector<Note*> notes;
};

#endif // CORKBOARD_H
