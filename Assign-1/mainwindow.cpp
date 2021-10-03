#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{

  // Create the button, make "this" the parent
  m_button = new QPushButton("Enter command", this);
  // set size and location of the button
  m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
 
  // Connect button signal to appropriate slot
  connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);
} 


void MainWindow::handleButton()
{
  // change the text
  // m_button->setText("command here");
  // resize button
  // m_button->resize(100,100);b 
}
