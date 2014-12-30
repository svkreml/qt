#ifndef CORKBOARDSCENE_H
#define CORKBOARDSCENE_H

#include <QGraphicsScene>

#include "notepackitem.h"
#include "picturepackitem.h"

class CorkboardScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit CorkboardScene(QObject* parent = nullptr);

private:
    void align();

    NotePackItem* notePack;
    PicturePackItem* picturePack;
};

#endif // CORKBOARDSCENE_H
