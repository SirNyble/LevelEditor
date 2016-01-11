//
// Created by rhys on 05/01/16.
//
#ifndef NEW_PROJECT_DIALOG_H
#define NEW_PROJECT_DIALOG_H
#include <QWidget>
#include <QFileDialog>
#include <QDialog>
#include <QDebug>

#include "ui/ui_NewProjectDialog.h"

namespace Ui
{
  class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
  Q_OBJECT

public:
  NewProjectDialog(QWidget * parent = 0);
  Ui::NewProjectDialog * m_ui;
  QStringList m_spriteSheetFiles;
  int m_tileSize;
public slots:
  void findSpriteSheet();
};

#endif //NEW_PROJECT_DIALOG
