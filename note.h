#ifndef NOTE_H
#define NOTE_H

#include <QPlainTextEdit>

class Note : public QPlainTextEdit
{
    Q_OBJECT

public:
    Note(QWidget* parent = nullptr);

protected:
    virtual void contextMenuEvent(QContextMenuEvent* e) { e->accept(); }
};

#endif // NOTE_H
