#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QGuiApplication>
#include <QLabel> 
#include <QAccessibleTextInterface>
#include <QLineEdit>
#include <QTextEdit>
#include <QString>
#include <QListWidget>
#include <QListWidgetItem>
#include <vector>
#include <cstring>
#include "header.h"

namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

private slots:
  void handleButton();
  void itemClicked(QListWidgetItem *item);

private:
  QPushButton *m_button;
  QLineEdit *echoLineEdit;
  QTextEdit *text_edit;
  QLabel *exit_label;
  std::vector<string> history;
  QListWidget *history_list;
};

#endif 