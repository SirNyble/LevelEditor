//
// Created by rhys on 05/01/16.
//
#include "LevelEditor.h"

LevelEditor::LevelEditor(QString title, int width, int height, QWidget *parent)
: QMainWindow(parent),
  m_ui(new Ui::LevelEditor)
{
    //Ui::LevelEditor ui;
    m_ui->setupUi(this);

    setWindowTitle(title);
    setFixedSize(width, height);

    //vLayout->addWidget(scene);
}
