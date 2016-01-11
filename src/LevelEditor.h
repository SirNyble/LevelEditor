//
// Created by rhys on 05/01/16.
//
#ifndef LEVELEDITOR_H
#define LEVELEDITOR_H

//QT Specific
#include <QWidget>
#include <string>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGridLayout>
#include <QToolBar>
#include <QToolButton>
#include <QDebug>
#include <QFileDialog>
#include <QDialog>

//Forms
#include "ui/ui_LevelEditor.h"

#include "NewProjectDialog.h"

namespace Ui
{
  class LevelEditor;
}

class LevelEditor : public QMainWindow
{
    Q_OBJECT
public:
    LevelEditor(QString title, QWidget *parent =0);
    void setupMenu();
    QToolBar * m_stampBar;

public slots:
    void newMap();

private:
    Ui::LevelEditor *m_ui;
    QMenu * m_fileMenu;
    QAction *m_newMap;

    int m_tileSize;
    QString m_spriteSheetFiles;
};
#endif //LEVELEDITOR_H
