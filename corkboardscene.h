#ifndef CORKBOARDSCENE_H
#define CORKBOARDSCENE_H

#include <QGraphicsScene>

class CorkboardScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit CorkboardScene(QObject* parent = nullptr);

private:
    void align();

    QGraphicsPixmapItem* notePack;
    QGraphicsPixmapItem* picturePack;
};

#endif // CORKBOARDSCENE_H
