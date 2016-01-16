#include "TileButton.h"

TileButton::TileButton()
:QToolButton()
{

}

void TileButton::mousePressEvent(QMouseEvent * e)
{
  qDebug() << "WOOT";
}
