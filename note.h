#ifndef NOTE_H
#define NOTE_H

#include <QPlainTextEdit>

class Note : public QPlainTextEdit
{
    Q_OBJECT

public:
    Note(QWidget* parent = 0);
};

#endif // NOTE_H
