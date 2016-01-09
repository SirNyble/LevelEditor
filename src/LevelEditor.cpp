//
// Created by rhys on 05/01/16.
//
#include "LevelEditor.h"

LevelEditor::LevelEditor(QString title, int width, int height, QWidget *parent)
: QMainWindow(parent),
  m_ui(new Ui::LevelEditor)
{
    m_ui->setupUi(this);

    setWindowTitle(title);

    setupMenu();
    //TODO: Make sure this is moved to the LOAD function
    QImage spriteSheet(":/images/MySpriteSheet");
    QImage tile00 = spriteSheet.copy(1, 1, 16, 16);
    tile00 = tile00.scaled(32, 32);

    QImage tile01 = spriteSheet.copy(1, 16, 16, 16);
    tile01= tile01.scaled(32, 32);
    //m_stampBar = new QToolBar();
    //m_stampBar->setScaledContents(true);
    QToolButton * testButton = new QToolButton();
    testButton->setIcon(QIcon(QPixmap::fromImage(tile00)));
    testButton->setIconSize(QSize(32, 32));
    m_ui->m_stampLayout->addWidget(testButton);

    QToolButton * testButton1 = new QToolButton();
    testButton1->setIcon(QIcon(QPixmap::fromImage(tile01)));
    testButton1->setIconSize(QSize(32, 32));
    m_ui->m_stampLayout->addWidget(testButton1);
}

void LevelEditor::setupMenu()
{

}
