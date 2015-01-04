#include <QVBoxLayout>

#include "note.h"

Note::Note(QWidget* parent)
    : QPlainTextEdit(parent)
{
    setFixedSize(250, 285);
    setFont(QFont("Segoe Print", 16));
    setFrameStyle(QFrame::NoFrame);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setStyleSheet("padding-top: 35px;"
                  "background: transparent;"
                  "background-image: url(:/textures/note.png);");
}
