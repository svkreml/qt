#ifndef CORKBOARDSCENE_H
#define CORKBOARDSCENE_H

#include <QGraphicsScene>

#include "notepackitem.h"
#include "noteproxywidget.h"
#include "picturepackitem.h"

class CorkboardScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit CorkboardScene(QObject* parent = nullptr);

protected:
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent*);
    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent*);
    virtual void dropEvent(QGraphicsSceneDragDropEvent*);

private:
    void align();

    NotePackItem* notePack;
    PicturePackItem* picturePack;
};

#endif // CORKBOARDSCENE_H
