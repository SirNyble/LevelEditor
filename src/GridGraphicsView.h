#ifndef GRID_GRAPHICS_VIEW_H
#define GRID_GRAPHICS_VIEW_H

#include <QWidget>
#include <QtWidgets/QGraphicsView>
#include <QDebug>
class GridGraphicsView : public QGraphicsView
{
public:
  GridGraphicsView(QWidget *parent =0);
};
#endif //GRID_GRAPHICS_VIEW_H
