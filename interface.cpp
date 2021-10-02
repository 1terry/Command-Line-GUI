// #include "interfaceHeader.h"

// MainWindow::MainWindow(QWidget *parent)
//   : QMainWindow(parent)
// {
//   // Create the button, make "this" the parent
//   m_button = new QPushButton("My Button", this);
//   // set size and location of the button
//   m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
 

//   QLabel *label = new QLabel(this);
//   label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
//   label->setText("first line\nsecond line");
//   label->setAlignment(Qt::AlignBottom | Qt::AlignRight);

//   // Connect button signal to appropriate slot
//   connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);
// }
 
// void MainWindow::handleButton()
// {
//   // change the text
//   m_button->setText("Enter");
//   // resize button
//   m_button->resize(100,100);
// }

#include <QMenu>
#include <QMenuBar>
#include "simple_menu.h"

SimpleMenu::SimpleMenu(QWidget *parent)
    : QMainWindow(parent) {

  auto *quit = new QAction("&Quit", this);

  QMenu *file = menuBar()->addMenu("&File");
  file->addAction(quit);

  connect(quit, &QAction::triggered, qApp, QApplication::quit);
}