#ifndef GRID_GRAPHICS_VIEW_H
#define GRID_GRAPHICS_VIEW_H

#include <QWidget>
#include <QtWidgets/QGraphicsView>
#include <QDebug>
#include <QMouseEvent>

class GridGraphicsView : public QGraphicsView
{
public:
  GridGraphicsView(QWidget *parent =0);
  virtual void mousePressEvent(QMouseEvent *event);
};
#endif //GRID_GRAPHICS_VIEW_H
