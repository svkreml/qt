#ifndef CORKBOARDSCENE_H
#define CORKBOARDSCENE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "notepackitem.h"
#include "noteproxywidget.h"

class CorkboardSceneLoader;
class CorkboardSceneSaver;

class CorkboardScene : public QGraphicsScene
{
    Q_OBJECT

public:  
    explicit CorkboardScene(QObject* parent = nullptr);

    void clearNotes();

protected:
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent*);
    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent*);
    virtual void dropEvent(QGraphicsSceneDragDropEvent*);

private:
    void align();

    NotePackItem* notePack;
    CorkboardSceneLoader* openIcon;
    CorkboardSceneSaver* saveIcon;
};

class CorkboardSceneLoader : public QGraphicsPixmapItem
{
public:
    CorkboardSceneLoader(const QPixmap& icon, QGraphicsItem* parent = 0);

    // Структура файла сцены:
    // {[qreal, qreal, QString], ...}, где:
    // 1 - qreal - координата x заметки на сцене
    // 2 - qreal - координата y заметки на сцене
    // 3 - QString - строка с текстом заметки
    void openScene(QFile* file);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*);
};

class CorkboardSceneSaver : public QGraphicsPixmapItem
{
public:
    CorkboardSceneSaver(const QPixmap& icon, QGraphicsItem* parent = 0);

    // Структура файла сцены:
    // {[qreal, qreal, QString], ...}, где:
    // 1 - qreal - координата x заметки на сцене
    // 2 - qreal - координата y заметки на сцене
    // 3 - QString - строка с текстом заметки
    void saveScene(QFile* file);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*);
};

#endif // CORKBOARDSCENE_H
