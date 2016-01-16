#ifndef TILE_BUTTON_H
#define TILE_BUTTON_H

#include <QWidget>
#include <QDebug>

class Tile
{
public:
    Tile();
    QImage m_tile;
    int m_row;
    int m_col;
    //QToolButton * m_toolButton;
};

#endif //TILE_BUTTON_H
