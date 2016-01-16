#ifndef GRID_GRAPHICS_VIEW_H
#define GRID_GRAPHICS_VIEW_H

#include <QWidget>
#include <QtWidgets/QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QMouseEvent>

#include "Tile.h"

class GridGraphicsView : public QGraphicsView
{
public:
  GridGraphicsView(QWidget *parent =0);
  void createEmptyGrid(int rows, int cols, int tileSize);
  virtual void mousePressEvent(QMouseEvent *event);

  int m_tileSize;
  QGraphicsScene * m_scene;

private:
  int m_rows;
  int m_cols;
  int m_gridWidth;
  int m_gridHeight;
};
#endif //GRID_GRAPHICS_VIEW_H
