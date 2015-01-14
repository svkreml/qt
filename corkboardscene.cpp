#include <memory>

#include <QDataStream>
#include <QFileDialog>
#include <QIcon>
#include <QGraphicsItem>
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
      openIcon(new CorkboardSceneLoader(QPixmap(":/textures/open.png"))),
      saveIcon(new CorkboardSceneSaver(QPixmap(":/textures/save.png")))
{
    addItem(notePack);
    addItem(openIcon);
    addItem(saveIcon);

    openIcon->setPos(5, 5);
    saveIcon->setPos(50, 5);

    notePack->setZValue(1);
    openIcon->setZValue(1);
    saveIcon->setZValue(1);

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

    notePack->setPos(notePackPos);
}

void CorkboardScene::clearNotes()
{
    for (auto item : items()) {
        auto noteItem = dynamic_cast<NoteProxyWidget*>(item);
        if (noteItem)
            removeItem(noteItem);
    }
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

CorkboardSceneLoader::CorkboardSceneLoader(const QPixmap& icon, QGraphicsItem* parent)
    : QGraphicsPixmapItem(icon, parent)
{
}

void CorkboardSceneLoader::mouseDoubleClickEvent(QGraphicsSceneMouseEvent*)
{
    auto fileName =
            QFileDialog::getOpenFileName(0, "Open", QString(),
                                         "Corkboard file (*.cbf)");
    auto file = std::unique_ptr<QFile>(new QFile(fileName));
    openScene(file.get());
}

void CorkboardSceneLoader::openScene(QFile* file)
{
    auto cbScene = dynamic_cast<CorkboardScene*>(scene());
    if (!cbScene)
        return;

    if (!file->open(QFile::ReadOnly))
        return;

    cbScene->clearNotes();

    QDataStream dataStream(file);

    qreal x, y;
    QString str;
    while (!dataStream.atEnd()) {
        dataStream >> x >> y >> str;
        if (dataStream.status() == QDataStream::Ok) {
            auto noteItem = new NoteProxyWidget;
            noteItem->setPos(x, y);
            noteItem->widget()->setPlainText(str);
            cbScene->addItem(noteItem);
        }
        else {
            cbScene->clearNotes();
            return;
        }
    }
    file->close();
}

CorkboardSceneSaver::CorkboardSceneSaver(const QPixmap& icon, QGraphicsItem* parent)
    : QGraphicsPixmapItem(icon, parent)
{
}

void CorkboardSceneSaver::mouseDoubleClickEvent(QGraphicsSceneMouseEvent*)
{
    auto fileName =
            QFileDialog::getSaveFileName(0, "Save", QString(),
                                         "Corkboard file (*.cbf)");
    auto file = std::unique_ptr<QFile>(new QFile(fileName));
    saveScene(file.get());
}

void CorkboardSceneSaver::saveScene(QFile* file)
{
    auto cbScene = dynamic_cast<CorkboardScene*>(scene());
    if (!cbScene)
        return;

    if (!file->open(QFile::WriteOnly))
        return;
    QDataStream dataStream(file);

    for (QGraphicsItem* item : cbScene->items()) {
        auto noteItem = dynamic_cast<NoteProxyWidget*>(item);
        if (noteItem) {
            dataStream << noteItem->x();
            dataStream << noteItem->y();
            dataStream << noteItem->widget()->toPlainText();
        }
    }

    file->close();
}
