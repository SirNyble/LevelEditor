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
#include <vector>

//Forms
#include "ui/ui_LevelEditor.h"

#include "NewProjectDialog.h"
#include "TileButton.h"

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
    void createTileButtons();
    void createEmptyGrid();
    Ui::LevelEditor *m_ui;
    QMenu * m_fileMenu;
    QAction *m_newMap;

    //Sprite Tiles
    std::vector<TileButton *> m_tileVector;
    int m_tileSize;
    int m_gridSize;
    QString m_spriteSheetFiles;

    //Grid content
    QGraphicsScene * m_scene;
    int m_gridRowSize;
    int m_gridColSize;

};
#endif //LEVELEDITOR_H
